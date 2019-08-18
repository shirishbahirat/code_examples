#include <iostream>

using namespace std;

void print(int arr[], int len) {
  for (int i = 0; i < len; ++i) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void swap(int arr[], int idx, int idy) {
  if (idx != idy)
    arr[idx] ^= arr[idy] ^= arr[idx] ^= arr[idy];
}

int partition(int arr[], int low, int high) {

  int anchor = low;

  for (int index = low; index < high; ++index) {
    if (arr[index] < arr[high]) {
      swap(arr, index, anchor);
      ++anchor;
    }
  }
  swap(arr, high, anchor);

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

  int arr[] = {9, 6, 3, 7, 4, 2, 8, 1, 5};

  int len = sizeof(arr) / sizeof(arr[0]);

  quick_sort(arr, 0, (len - 1));

  print(arr, len);

  return 0;
}