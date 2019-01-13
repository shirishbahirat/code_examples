#include <iostream>
using namespace std;

void print_array(uint32_t arr[], uint32_t length) {

  for (uint32_t i = 0; i < length; ++i) {
    cout << arr[i] << " " << flush;
  }
  cout << endl;
}

void swap(uint32_t arr[], uint32_t l, uint32_t h) {
  if (l != h) {
    arr[l] ^= arr[h] ^= arr[l] ^= arr[h];
  }
}

void quicksort(uint32_t arr[], uint32_t low, uint32_t high) {
  if (low >= high)
    return;

  uint32_t counter = low;
  uint32_t pivot = arr[high];

  for (uint32_t i = low; i < high; ++i) {
    if (arr[i] < pivot) {
      swap(arr, i, counter);
      counter++;
    }
  }

  cout << low << " " << high << " " << counter << endl;

  swap(arr, counter, high);

  if (counter > 1)
    quicksort(arr, low, counter - 1);
  if (counter < high)
    quicksort(arr, counter + 1, high);
}

int main(int argc, char const *argv[]) {
  uint32_t arr[] = {20, 33, 55, 11, 4, 88, 56};
  uint32_t len = sizeof(arr) / sizeof(uint32_t);

  quicksort(arr, 0, len);

  print_array(arr, len);

  return 0;
}