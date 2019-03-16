#include <iostream>

using namespace std;

void swap(int arr[], int from, int to) {
  int temp = arr[from];
  arr[from] = arr[to];
  arr[to] = temp;
}

int main(int argc, const char *argv[]) {
  int arr[] = {11, 23, 34, 33, 10, 9, 8};
  int len = (sizeof(arr) / sizeof(int)) - 1;

  for (int i = 0, j = len; i < j; ++i, --j) {
    swap(arr, i, j);
  }

  for (int i = 0; i <= len; ++i) {
    cout << arr[i] << " " << flush;
  }
  cout << endl;

  return 0;
}