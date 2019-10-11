#include <experimental/coroutine>
#include <stdexcept>
#include <variant>

// clang++ gen.cpp -std=c++2a -fcoroutines-ts -stdlib=libc++

namespace detail {
// simple type erasure for iterators

template <typename T> struct generic_iterable {
  virtual ~generic_iterable() = default;

  virtual T &operator*() = 0;
  virtual generic_iterable<T> &operator++() = 0;
  virtual bool empty() const = 0;

  bool await_ready() const noexcept { return empty(); }

  template <typename U>
  void await_suspend(std::experimental::coroutine_handle<U> h) noexcept {
    h.promise().store_iterator(this);
  }

  void await_resume() const noexcept {}
};

template <typename T, typename StartIterator, typename EndIterator>
struct iterator_iterable : public generic_iterable<T> {
  iterator_iterable(StartIterator start, EndIterator end)
      : start(start), end(end) {}

  T &operator*() override { return *start; }

  iterator_iterable<T, StartIterator, EndIterator> &operator++() override {
    ++start;
    return *this;
  }

  bool empty() const override { return start == end; }

  StartIterator start;
  EndIterator end;
};

} // namespace detail

template <typename T> struct generator {
  using value_type = T;

  struct promise_type {
    // 0: prestart, 1: value, 2: range, 3: done
    std::variant<std::monostate, T *, detail::generic_iterable<T> *,
                 std::monostate>
        state;

    promise_type &get_return_object() noexcept { return *this; }

    std::experimental::suspend_always initial_suspend() const noexcept {
      return {};
    }

    std::experimental::suspend_always final_suspend() const noexcept {
      return {};
    }

    std::experimental::suspend_always yield_value(T &value) noexcept {
      state.template emplace<1>(std::addressof(value));
      return {};
    }

    std::experimental::suspend_always yield_value(T &&value) noexcept {
      state.template emplace<1>(std::addressof(value));
      return {};
    }

    void return_void() noexcept { state.template emplace<3>(); }

    template <typename Range>
    auto await_transform(Range &&range) const noexcept {
      using std::begin;
      using std::end;
      auto s = begin(range);
      auto e = end(range);

      // TODO: properly constraint
      static_assert(std::is_same_v<decltype(*s), T &>);
      detail::iterator_iterable<T, decltype(s), decltype(e)> iterator{s, e};
      return iterator;
    }

    void unhandled_exception() {
      state.template emplace<3>();
      auto ex = std::current_exception();
      std::rethrow_exception(ex);
      //// MSVC bug? should be possible to rethrow with "throw;"
      //// rethrow exception immediately
      // throw;
    }

    void store_iterator(detail::generic_iterable<T> *iterator) noexcept {
      state.template emplace<2>(iterator);
    }

    T &value() {
      switch (state.index()) {
      case 1:
        return *std::get<1>(state);
      case 2:
        return **std::get<2>(state);
      case 0:
        next();
        return value();
      default:
      case 3:
        throw std::logic_error("Generator already completed!");
      }
    }

    const T &value() const {
      switch (state.index()) {
      case 1:
        return *std::get<1>(state);
      case 2:
        return **std::get<2>(state);
      case 0:
        next();
        return value();
      default:
      case 3:
        throw std::logic_error("Generator already completed!");
      }
    }

    void next() {
      auto handle =
          std::experimental::coroutine_handle<promise_type>::from_promise(
              *this);
      switch (state.index()) {
      case 0:
      case 1:
        handle.resume();
        break;
      case 2: {
        auto &iterator = *std::get<2>(state);
        ++iterator;
        if (iterator.empty()) {
          state.template emplace<0>();
          handle.resume();
        }
        break;
      }
      default:
      case 3:
        throw std::logic_error("Generator already completed!");
      }
    }
  };

  using handle_type = std::experimental::coroutine_handle<promise_type>;

  struct iterator {
    using iterator_category = std::input_iterator_tag;
    using value_type = T;
    using difference_type = ptrdiff_t;
    using pointer = T *;
    using reference = T &;

    handle_type coro_handle;

    iterator() : coro_handle(nullptr) {}

    iterator(handle_type coro_handle) : coro_handle(coro_handle) {}

    iterator &operator++() {
      try {
        coro_handle.promise().next();
      } catch (...) {
        coro_handle = nullptr;
        throw;
      }
      if (coro_handle.done())
        coro_handle = nullptr;
      return *this;
    }

    iterator operator++(int) = delete;

    bool operator==(iterator const &other) const {
      return coro_handle == other.coro_handle;
    }

    bool operator!=(iterator const &other) const { return !(*this == other); }

    const T &operator*() const { return coro_handle.promise().value(); }

    const T *operator->() const { return std::addressof(operator*()); }

    T &operator*() { return coro_handle.promise().value(); }

    T *operator->() { return std::addressof(operator*()); }
  };

  iterator begin() {
    if (coro_handle) {
      if (coro_handle.done())
        return {};
    }

    return {coro_handle};
  }

  iterator end() { return {}; }

  generator(promise_type &promise)
      : coro_handle(handle_type::from_promise(promise)) {}

  generator() = default;
  generator(generator const &) = delete;
  generator &operator=(generator const &) = delete;

  generator(generator &&other) : coro_handle(other.coro_handle) {
    other.coro_handle = nullptr;
  }

  generator &operator=(generator &&other) {
    if (&other != this) {
      coro_handle = other.coro_handle;
      other.coro_handle = nullptr;
    }
    return *this;
  }

  ~generator() {
    if (coro_handle) {
      coro_handle.destroy();
    }
  }

private:
  std::experimental::coroutine_handle<promise_type> coro_handle = nullptr;
};

template <typename T> generator<int> range(T first, T last) {
  while (first != last) {
    co_yield first++;
  }
}

template <typename T> generator<int> range1(T first, T last) {
  while (first != last) {
    throw std::logic_error("BEGIN");

    co_yield first++;
  }
}

template <typename T> generator<int> range2(T first, T last) {
  while (first != last) {
    co_yield first++;

    throw std::logic_error("ITERATOR");
  }
}

template <typename T> generator<int> range4(T first, T last) { co_return; }

template <typename T> generator<int> range5_ex(T first, T last) {
  while (first != last) {
    co_yield first++;
  }
  throw std::logic_error("AFTER LAST YIELD (for example cleanup failure)");
}

/////////////////////////
generator<std::unique_ptr<int>> range_unqptr(int first, int last) {
  while (first != last) {
    co_yield std::make_unique<int>(first++);
  }
}

generator<std::unique_ptr<int>> gen_refs() {
  auto value = std::make_unique<int>(1);
  co_yield value;                    // lvalue&, can be moved from
  co_yield std::make_unique<int>(2); // rvalue&, can be moved from
  const auto cvalue = std::make_unique<int>(3);
  // co_yield cvalue; // compile error
}

generator<const std::unique_ptr<int>> gen_refs2() {
  auto value = std::make_unique<int>(1);
  co_yield value;                    // lvalue&
  co_yield std::make_unique<int>(2); // rvalue&
  const auto cvalue = std::make_unique<int>(3);
  co_yield cvalue; // no compile error
}

/////////////////////////
// combining generators and ranges
generator<int> gen_and_then(generator<int> first, generator<int> second) {
  co_await first;
  co_yield 999;
  co_await second;
  co_yield - 999;
}

template <typename Range1, typename Range2>
generator<int> and_then(Range1 first, Range2 second) {
  co_await first;
  co_yield 999;
  co_await second;
  co_yield - 999;
}

#include <stdio.h>
#include <string>
#include <vector>

int main() {
  // tests 1

  printf("\nrange\n");

  try {
    for (int i : range(0, 10)) {
      printf("%d\n", i);
    }
  } catch (std::exception const &e) {
    printf("%s\n", e.what());
  }

  printf("\nrange1\n");

  try {
    for (int i : range1(0, 10)) {
      printf("%d\n", i);
    }
  } catch (std::exception const &e) {
    printf("%s\n", e.what());
  }

  printf("\nrange2\n");

  try {
    for (int i : range2(0, 10)) {
      printf("%d\n", i);
    }
  } catch (std::exception const &e) {
    printf("%s\n", e.what());
  }

  try {
    for (int i : range4(0, 10)) {
      printf("%d\n", i);
    }
  } catch (std::exception const &e) {
    printf("%s\n", e.what());
  }

  printf("\nrange5_ex\n");

  try {
    for (int i : range5_ex(0, 10)) {
      printf("%d\n", i);
    }
  } catch (std::exception const &e) {
    printf("%s\n", e.what());
  }

  // tests 2
  try {
    printf("\nrange_unqptr\n");
    for (auto &i : range_unqptr(0, 10)) {
      auto b = std::move(i); // can be moved from, no UB
      printf("%d\n", *b);
    }
    printf("\ngen_refs\n");
    for (auto &i : gen_refs()) {
      auto b = std::move(i); // can be moved from, no UB
      printf("%d\n", *b);
    }

    printf("\ngen_refs2\n");
    for (auto &i : gen_refs2()) {
      // auto b = std::move(i); // compile time error
      printf("%d\n", *i);
    }

    printf("\ngen_and_then\n");
    auto g1 = gen_and_then(range(0, 2), range(5, 10));
    for (auto i : g1) {
      printf("%d\n", i);
    }

    printf("\ngen_and_then\n");
    auto g2 = gen_and_then(range(0, 2), range(5, 10));
    for (auto i : g2) {
      printf("%d\n", i);
    }

    printf("\nand_then gen+gen\n");
    auto g3 = and_then(range(0, 2), range(5, 10));
    for (auto i : g3) {
      printf("%d\n", i);
    }

    printf("\nand_then vec+vec\n");
    auto g4 = and_then(std::vector<int>{0, 1, 2}, std::vector<int>{5, 6, 7});
    for (auto i : g4) {
      printf("%d\n", i);
    }

    printf("\nand_then vec+gen\n");
    auto g5 = and_then(std::vector<int>{0, 1, 2}, range(5, 10));
    for (auto i : g5) {
      printf("%d\n", i);
    }

    // auto g6 = and_then(std::string("Hello world"), range(5, 10)); // compile
    // error

    auto lamda_gen = []() -> generator<const char> {
      co_yield '\n';
      co_await "Hello";
      co_yield ' ';
      co_await "generator!";
      co_yield '\n';
    };

    for (auto c : lamda_gen()) {
      printf("%c", c);
    }

  } catch (std::exception const &e) {
    printf("%s\n", e.what());
  }

  try {
    auto gen = range(5, 10);

    for (auto i : gen) {
    }
    for (auto i : gen) {
      printf("\nERROR: should be noop!\n");
    }
  } catch (std::exception const &e) {
    printf("Error: %s\n", e.what());
  }

  // Calling begin multiple times
  try {
    auto gen = range(5, 8);
    printf("\nShould print 5 6 7!\n");

    gen.begin();
    gen.begin();
    gen.begin();
    gen.begin();

    for (auto i : gen) {
      printf("%d\n", i);
    }
  } catch (std::exception const &e) {
    printf("Error: %s\n", e.what());
  }
}