#include <iostream>

using namespace std;

void print_array(int *arr, int len) {
  for (int i = 0; i < len; ++i) {
    cout << *arr << " " << flush;
    ++arr;
  }
  cout << endl;
}

void swap(int arr[], int l, int h) {
  if (l != h) {
    arr[l] ^= arr[h] ^= arr[l] ^= arr[h];
  }
}

void heapify(int arr[], int index, int len) {
  int largest_index = index;
  int left = index * 2 + 1;
  int right = index * 2 + 2;

  if ((left < len) && (arr[left] > arr[largest_index])) {
    largest_index = left;
  }

  if ((right < len) && (arr[right] > arr[largest_index])) {
    largest_index = right;
  }

  if (largest_index != index) {
    swap(arr, index, largest_index);
    heapify(arr, largest_index, len);
  }
}

int main(const int argc, const char *argv[]) {

  int arr[] = {9, 8, 6, 11, 2, 5, 7};

  return 0;
}
