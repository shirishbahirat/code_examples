#include <chrono>
#include <condition_variable>
#include <experimental/coroutine>
#include <iostream>
#include <mutex>
#include <thread>
#include <utility>
#include <vector>

// clang++ gen2.cpp -std=c++2a -fcoroutines-ts -stdlib=libc++

struct thread_pool {
  using time_point = std::chrono::system_clock::time_point;

  thread_pool(int n) {
    for (int i = 0; i < n; i++)
      worker_.emplace_back(&thread_pool::run_worker, this);
  }
  thread_pool(const thread_pool &) = delete;
  ~thread_pool() = default;

  void enqueue(void *coro, time_point tp = time_point::min()) {
    queue_.enqueue(coro, tp);
  }
  void run_worker() {
    while (void *task = queue_.dequeue()) {
      std::experimental::coroutine_handle<>::from_address(task).resume();
    }
  }
  void run_loop() {
    queue_.close();
    for (auto &&th : worker_)
      th.join();
    worker_.clear();
  }

private:
  template <typename T = void *> struct delay_queue {
    using time_point = std::chrono::system_clock::time_point;

    void enqueue(T v, time_point tp) {
      std::lock_guard<decltype(mtx_)> lk(mtx_);
      q_.emplace_back(std::move(v), tp);
      // descending sort on time_point
      std::sort(begin(q_), end(q_),
                [](auto &&a, auto &&b) { return a.second > b.second; });
      cv_.notify_one();
    }
    T dequeue() {
      std::unique_lock<decltype(mtx_)> lk(mtx_);
      auto now = std::chrono::system_clock::now();
      // wait condition: (empty && closed) || (!empty && back.tp <= now)
      while (!(q_.empty() && closed_) &&
             !(!q_.empty() && q_.back().second <= now)) {
        if (q_.empty())
          cv_.wait(lk);
        else
          cv_.wait_until(lk, q_.back().second);
        now = std::chrono::system_clock::now();
      }
      if (q_.empty() && closed_)
        return {};
      T ret = std::move(q_.back().first);
      q_.pop_back();
      if (q_.empty() && closed_)
        cv_.notify_all();
      return ret;
    }
    void close() {
      std::lock_guard<decltype(mtx_)> lk(mtx_);
      closed_ = true;
      cv_.notify_all();
    }

    std::vector<std::pair<T, time_point>> q_;
    bool closed_ = false;
    std::mutex mtx_;
    std::condition_variable cv_;
  };

  delay_queue<> queue_;
  std::vector<std::thread> worker_;
};

// global thread pool
thread_pool tp(3);

struct coro_action {
  struct promise_type {
    coro_action get_return_object() {
      return coro_action{handle_type::from_promise(*this)};
    }
    auto initial_suspend() {
      struct awaiter {
        bool await_ready() { return false; }
        void await_suspend(std::experimental::coroutine_handle<> h) {
          tp.enqueue(h.address());
        }
        void await_resume() {}
      };
      return awaiter{};
    }
    std::experimental::suspend_always final_suspend() { return {}; }
    void return_void() {}
    void unhandled_exception() { std::terminate(); }

    // support "co_await <duration>" in coroutine
    template <class Rep, class Period>
    auto await_transform(const std::chrono::duration<Rep, Period> &d) {
      struct awaiter {
        std::chrono::duration<Rep, Period> d_;
        bool await_ready() { return false; }
        void await_suspend(handle_type h) {
          tp.enqueue(h.address(), std::chrono::system_clock::now() + d_);
        }
        void await_resume() {}
      };
      return awaiter{d};
    }
  };
  using handle_type = std::experimental::coroutine_handle<promise_type>;

  explicit coro_action(handle_type h) : coro_(h) {}
  coro_action(const coro_action &) = delete;
  coro_action(coro_action &&rhs) : coro_(rhs.coro_) { rhs.coro_ = nullptr; }
  ~coro_action() {
    if (coro_)
      coro_.destroy();
  }

  handle_type coro_;
};

// adapt void() coroutine
namespace std::experimental {
template <typename... ArgTypes> struct coroutine_traits<void, ArgTypes...> {
  using promise_type = coro_action::promise_type;
};
} // namespace std::experimental

std::mutex cout_mutex;
#define COUT std::unique_lock<decltype(cout_mutex)>(cout_mutex), std::cout

void sleep_sort(int n) {
  using namespace std::chrono_literals;
  co_await std::chrono::milliseconds(n * 100);
  COUT << n << " @" << std::this_thread::get_id() << std::endl;
}

int main() {
  sleep_sort(4);
  sleep_sort(6);
  sleep_sort(3);
  sleep_sort(7);
  sleep_sort(1);
  sleep_sort(8);
  sleep_sort(5);
  sleep_sort(2);
  tp.run_loop();
}