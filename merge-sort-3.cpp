#include <iostream>

using namespace std;

void print_arry(int *parr, int len) {

  for (int i = 0; i < len; ++i) {
    cout << *parr << " " << flush;
    parr++;
  }
  cout << endl;
}

void merge(int arr[], int lo, int md, int hi) {
  int len = hi - lo;
  int temp[len];
  int j = lo, k = md, l = 0;

  while (j < md && k < hi) {
    if (arr[j] < arr[k]) {
      temp[l++] = arr[j++];
    } else {
      temp[l++] = arr[k++];
    }
  }

  while (j < md) {
    temp[l++] = arr[j++];
  }

  while (k < hi) {
    temp[l++] = arr[k++];
  }

  for (int m = lo, n = 0; m < hi; ++m, ++n) {
    arr[m] = temp[n];
  }

  for (int i = 0; i < len; ++i)
    cout << " " << temp[i] << flush;

  cout << endl;
}

void split(int arr[], int lo, int hi) {
  if (hi == lo)
    return;

  int md = (lo + hi) / 2;

  cout << lo << " " << hi << endl;

  split(arr, lo, md);
  split(arr, md + 1, hi);
  merge(arr, lo, md, hi);
}

int main(int argc, char const *argv[]) {
  int arr[] = {2, 9, 5, 3, 8, 6, 1};
  int len = (sizeof(arr) / sizeof(arr[0]));

  split(arr, 0, len);

  print_arry(arr, len);

  return 0;
}