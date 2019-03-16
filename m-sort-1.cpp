#include <iostream>

using namespace std;

void merge(int arr[], int lo, int mid, int hi) {

  int len = hi - lo;
  int temp[len];
  int i = lo, j = mid, k = 0;

  while (i < mid && j < hi) {
    if (arr[i] < arr[j]) {
      temp[k++] = arr[i++];
    } else {
      temp[k++] = arr[j++];
    }
  }

  while (i < mid) {
    temp[k++] = arr[i++];
  }

  while (j < hi) {
    temp[k++] = arr[j++];
  }

  for (int m = lo, n = 0; m < hi; ++m, ++n) {
    arr[m] = temp[n];
  }
}

void merge_sort(int arr[], int lo, int hi) {

  if (hi == lo)
    return;

  int mid = (hi + lo) / 2;

  merge_sort(arr, lo, mid);
  merge_sort(arr, mid + 1, hi);

  merge(arr, lo, mid, hi);
}

int main(int argc, const char *argv[]) {

  int arr[] = {1, 3, 6, 8, 4, 12, 9, 10, 5};
  int len = (sizeof(arr) / sizeof(int));

  merge_sort(arr, 0, len);

  for (int i = 0; i < len; ++i) {
    cout << arr[i] << " " << flush;
  }
  cout << endl;

  return 0;
}