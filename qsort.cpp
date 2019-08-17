#include <iostream>

using namespace std;

void swap(int arr[], int a, int b) {
  if (a != b) {
    arr[a] ^= arr[b] ^= arr[a] ^= arr[b];
  }
}

void print(int arr[], int len) {
  for (int i = 0; i < len; ++i) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int partition(int arr[], int low, int high) {
  int anchor = low;

  for (int i = low; i < high; ++i) {
    if (arr[i] <= arr[high]) {
      swap(arr, i, anchor);
      ++anchor;
    }
  }
  swap(arr, anchor, high);

  return anchor;
}

void quick_sort(int arr[], int low, int high) {

  if (low < high) {
    int pivot = partition(arr, low, high);
    if (pivot > 0)
      quick_sort(arr, low, pivot - 1);
    if (pivot < high)
      quick_sort(arr, pivot + 1, high);
  }
}

int main(int argc, char const *argv[]) {

  int arr[] = {3, 4, 5, 2, 1, 8, 9, 7};

  int len = sizeof(arr) / sizeof(arr[0]);

  quick_sort(arr, 0, len - 1);

  print(arr, len);

  return 0;
}
