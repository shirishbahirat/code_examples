#include <iostream>

int main() {
  int x = 10;
  int y = 20;

  int addrN = 0000;
  int addrA = 1111;
  int addrB = 2222;
  int addrC = 3333;

  std::cout << x << " " << y << std::endl;

  x ^= y ^= x ^= y;

  std::cout << x << " " << y << std::endl;

  int addrNNext = addrN ^ addrA;
  int addrANext = addrA ^ addrB;

  std::cout << (addrNNext ^ 0000) << " " << addrA << std::endl;

  std::cout << (addrANext ^ (addrNNext ^ 0000)) << " " << addrB << std::endl;
}
