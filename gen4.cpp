/*
 * coroutines simple number generator example
 *
 * % clang++ -std=c++14 -fcoroutines-ts -stdlib=libc++ numberGen.cpp
 *
 * Tal 2017-06-27
 */

// https://github.com/tlanc007/coroutine-ts

#include <experimental/coroutine>
#include <iostream>

#include "generator.h"

generator<unsigned long> numGen(unsigned long n) {
  for (auto i{0ul}; i < n; ++i) {
    co_yield i;
  }
}

#ifndef AS_TEST
int main() {
  for (auto e : numGen(5)) {
    std::cout << e << "\n";
  }
}
#endif // AS_TEST