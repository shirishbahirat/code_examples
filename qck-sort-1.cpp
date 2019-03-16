#include <iostream>

using namespace std;

void swap(int arr[], int l, int h) {

  if (l != h) {
    arr[l] ^= arr[h] ^= arr[l] ^= arr[h];
  }
}

void print_array(int *parr, int len) {
  for (int i = 0; i < len; ++i) {
    cout << *parr << " " << flush;
    ++parr;
  }

  cout << endl;
}

int partation(int arr[], int low, int high) {

  int pivot = arr[high];
  int index = low;

  for (int j = low; j < high; ++j) {
    if (arr[j] < pivot) {
      swap(arr, index, j);
      ++index;
    }
  }
  swap(arr, index, high);

  return index;
}

void quick_sort(int arr[], int low, int high) {
  if (low < high) {
    int pivot = partation(arr, low, high);
    if (pivot > 0)
      quick_sort(arr, low, pivot - 1);
    if (pivot < high)
      quick_sort(arr, pivot + 1, high);
  }
}

int main(int argc, const char *argv[]) {

  int arr[] = {11, 2, 5, 7, 1, 14, 6, 19};
  int len = (sizeof(arr) / sizeof(int));

  quick_sort(arr, 0, len - 1);
  print_array(arr, len);

  return 0;
}