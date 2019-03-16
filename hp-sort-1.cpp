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

void heapify(int arr[], int n, int i) {
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;

  if (l < n && arr[l] > arr[largest])
    largest = l;

  if (r < n && arr[r] > arr[largest])
    largest = r;

  if (largest != i) {
    swap(arr, i, largest);
    heapify(arr, n, largest);
  }
}

void heap_sort(int arr[], int len) {
  for (int i = (len / 2) - 1; i >= 0; --i) {
    heapify(arr, len, i);
  }

  for (int i = len - 1; i >= 0; i--) {
    swap(arr, 0, i);

    heapify(arr, i, 0);
  }
}

int main(int argc, const char *argv[]) {

  int arr[] = {11, 2, 5, 7, 1, 14, 6, 19};
  int len = sizeof(arr) / sizeof(int);

  heap_sort(arr, len);
  print_array(arr, len);

  return 0;
}