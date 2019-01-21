#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  uint32_t number = 10;

  if (argc > 1) {
    number = atoi(argv[1]);
    cout << "argc " << argc << " " << argv[1] << endl;
  }

  uint32_t index = sqrt(number);

  for (uint32_t i = 2; i < index; ++i) {
    if ((number % i) == 0) {
      cout << "Not a prime number " << index << " " << i << " " << number
           << endl;
      break;
    }
  }

  return 0;
}