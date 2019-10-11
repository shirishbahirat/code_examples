#include <functional>
#include <iostream>

// https://github.com/tlanc007/coroutine-ts

//-------------------------------
// BEGIN decorator implementation
//-------------------------------

template <class> struct Decorator;

template <class R, class... Args> struct Decorator<R(Args...)> {
  Decorator(std::function<R(Args...)> f) : f_(f) {}

  R operator()(Args... args) {
    std::cout << "Calling the decorated function.\n";
    return f_(args...);
  }
  std::function<R(Args...)> f_;
};

template <class R, class... Args>
Decorator<R(Args...)> makeDecorator(R (*f)(Args...)) {
  return Decorator<R(Args...)>(std::function<R(Args...)>(f));
}

//-------------------------------
// END decorator implementation
//-------------------------------

//-------------------------------
// Sample functions to decorate.
//-------------------------------

// Proposed solution doesn't work with default values.
// int decorated1(int a, float b = 0)
int decorated1(int a, float b) {
  std::cout << "a = " << a << ", b = " << b << std::endl;
  return 0;
}

void decorated2(int a) { std::cout << "a = " << a << std::endl; }

int main() {
  auto method1 = makeDecorator(decorated1);
  method1(10, 30.3);
  auto method2 = makeDecorator(decorated2);
  method2(10);
}