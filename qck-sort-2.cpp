#include <iostream>

using namespace std;

void print_arry(int *parr, int len) {

  for (int i = 0; i < len; ++i) {
    cout << *parr << " " << flush;
    parr++;
  }
  cout << endl;
}

void swap(int arr[], int from, int to) {
  if (arr[from] == arr[to])
    return;

  arr[from] ^= arr[to] ^= arr[from] ^= arr[to];
}

void quick_sort(int arr[], int lo, int hi) {

  if (hi < lo)
    return;

  int pvt = hi;
  int idx = lo;
  int anc = lo;

  for (int i = lo; i < hi; ++i) {
    if (arr[idx] < arr[pvt]) {
      swap(arr, idx, anc);
      ++anc;
    }
    ++idx;
  }
  swap(arr, anc, pvt);
  quick_sort(arr, lo, anc - 1);
  quick_sort(arr, anc + 1, hi);
}

int main(int argc, const char *argv[]) {
  int arr[] = {3, 10, 2, 7, 12, 9, 6, 5};
  int len = sizeof(arr) / sizeof(arr[0]);

  quick_sort(arr, 0, len - 1);

  print_arry(arr, len);
}