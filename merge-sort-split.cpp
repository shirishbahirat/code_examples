#include <iostream>
using namespace std;

void merge(uint32_t arr[], uint32_t low, uint32_t mid, uint32_t high) {
  uint32_t len = high - low;
  uint32_t temp[len];
  uint32_t i = low, j = mid, k = 0;

  while (i < mid && j < high) {
    if (arr[i] < arr[j]) {
      temp[k++] = arr[i++];
    } else {
      temp[k++] = arr[j++];
    }
  }

  while (i < mid) {
    temp[k++] = arr[i++];
  }
  while (j < high) {
    temp[k++] = arr[j++];
  }

  for (uint32_t m = low, n = 0; m < high; ++m, ++n) {
    arr[m] = temp[n];
  }
  cout << "main "
       << " len " << len << " "
       << " high " << high << " mid " << mid << " low " << low << flush;

  for (uint32_t i = 0; i < len; ++i)
    cout << " " << temp[i] << flush;

  cout << endl;
}

void split(uint32_t arr[], uint32_t low, uint32_t high) {

  if (high == low)
    return;

  int mid = (low + high) / 2;

  split(arr, low, (uint32_t)mid);
  split(arr, (uint32_t)mid + 1, high);
  merge(arr, low, (uint32_t)mid, high);
}

void merge_sort(uint32_t arr[], uint32_t len) { split(arr, 0, len); }

int main(int argc, char const *argv[]) {

  uint32_t arr[] = {0, 4, 3, 9, 7, 1, 6, 5, 2, 8, 10, 11};
  uint32_t len = 11;

  merge_sort(arr, len);

  for (uint32_t i = 0; i <= len; ++i) {
    cout << arr[i] << " " << flush;
  }
  cout << endl;

  return 0;
}