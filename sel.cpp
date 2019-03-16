#include <iostream>
using namespace std;

void swap(int arr[], int from, int to) {
  int temp = arr[from];
  arr[from] = arr[to];
  arr[to] = temp;
}

int main(int argc, const char *argv[]) {
  int arr[] = {10, 11, 4, 19, 6, 18};
  int len = (sizeof(arr) / sizeof(int)) - 1;

  for (int i = 0; i <= len; ++i) {
    int index = i;
    for (int j = i + 1; j <= len; ++j) {
      if (arr[index] < arr[j]) {
        index = j;
      }
    }
    swap(arr, index, i);
  }

  for (int i = 0; i <= len; ++i) {
    cout << arr[i] << " " << flush;
  }
  cout << endl;

  return 0;
}