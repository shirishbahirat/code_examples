#include <iostream>

using namespace std;

void swap(uint32_t arr[], uint32_t a, uint32_t b) {
  if (arr[a] != arr[b]) {
    arr[a] ^= arr[b] ^= arr[a] ^= arr[b];
  }
}

void print_array(uint32_t arr[], uint32_t length) {

  for (uint32_t i = 0; i < length; ++i) {
    cout << arr[i] << " ";
  }

  cout << endl;
}

uint32_t partation(uint32_t arr[], uint32_t low, uint32_t high) {

  uint32_t pivot = arr[high];
  uint32_t index = low;

  for (uint32_t j = low; j < high; ++j) {
    if (arr[j] <= pivot) {
      swap(arr, index, j);
      ++index;
    }
  }

  swap(arr, index, high);

  cout << pivot << " - ";
  print_array(arr, 10);

  return index;
}

void quick_sort(uint32_t arr[], uint32_t low, uint32_t high) {
  if (low < high) {
    uint32_t pivot = partation(arr, low, high);
    if (pivot > 0)
      quick_sort(arr, low, pivot - 1);
    if (pivot < high)
      quick_sort(arr, pivot + 1, high);
  }
}

int main(int argc, const char *argv[]) {
  uint32_t arr[] = {10, 3, 4, 3, 5, 6, 11, 8, 12, 1, 7};
  quick_sort(arr, 0, (sizeof(arr) / sizeof(uint32_t)) - 1);
  print_array(arr, (sizeof(arr) / sizeof(uint32_t)));
  return 0;
}
