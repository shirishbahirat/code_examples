#include <iostream>

using namespace std;

template <typename T> T adder(T v) { return v; }

template <typename T, typename... Args> T adder(T first, Args... args) {
  return first + adder(args...);
}

int main(int argc, char const *argv[]) {

  long sum = adder(1, 2, 3, 8, 7);

  cout << sum << endl;

  string s1 = "x ", s2 = " aa ", s3 = " bb ", s4 = "yy";
  string ssum = adder(s1, s2, s3, s4);

  cout << ssum << endl;

  return 0;
}