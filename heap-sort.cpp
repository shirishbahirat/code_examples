#include <iostream>

using namespace std;

void swap(int arr[], int a, int b) {
  if (arr[a] != arr[b]) {
    arr[a] ^= arr[b] ^= arr[a] ^= arr[b];
  }
}

void print_arr(int arr[], int length) {

  for (int i = 0; i < length; ++i) {
    cout << arr[i] << " ";
  }

  cout << endl;
}

void heapify(int arr[], int index, int length) {
  int largest = index;
  int left = 2 * index + 1;
  int right = 2 * index + 2;

  if ((left < length) && (arr[left] > arr[largest]))
    largest = left;

  if ((right < length) && (arr[right] > arr[largest]))
    largest = right;

  if (largest != index) {
    swap(arr, largest, index);
    heapify(arr, largest, length);
  }
}

void heap_sort(int arr[], int length) {

  int parent = (length - 1) / 2;

  for (int index = parent; index >= 0; --index) {
    heapify(arr, index, length);
  }

  for (int idx = length - 1; idx >= 0; --idx) {
    swap(arr, 0, idx);
    heapify(arr, 0, idx);
  }
}

int main(int argc, char const *argv[]) {
  int arr[] = {10, 3, 4, 5, 6, 11, 8, 12};

  heap_sort(arr, sizeof(arr) / sizeof(arr[0]));

  print_arr(arr, sizeof(arr) / sizeof(arr[0]));
  return 0;
}