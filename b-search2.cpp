#include <iostream>

using namespace std;

int main(int argc, const char *argv[]) {
  uint32_t arr[] = {0, 10, 20, 30, 40, 50, 60, 70, 80};
  uint32_t get = 70;

  uint32_t ilow = 0;
  uint32_t ihigh = (sizeof(arr) / sizeof(uint32_t)) - 1;

  if (argc > 1) {
    get = atoi(argv[1]);
  }

  while (ihigh >= ilow) {
    uint32_t imid = (ilow + ihigh) >> 1;

    if (arr[imid] == get) {
      cout << "found " << get << endl;
      break;
    }

    if (arr[imid] < get) {
      ilow = imid + 1;
    } else {
      ihigh = imid;
    }
  }

  return 0;
}