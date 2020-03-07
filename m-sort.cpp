#include <iostream>

using namespace std;

void print(int arr[], int len) {
  for (int i = 0; i < len; ++len) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int merge_sort(int arr[], int low, int high) {
  if (low < high) {
    int mid = low + ((high - low) / 2);
    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);
  }
}

int main(int argc, char const *argv[]) {

  int arr[] = {9, 6, 3, 7, 4, 2, 8, 1, 5};

  int len = sizeof(arr) / sizeof(arr[0]);

  merge_sort(arr, 0, (len - 1));

  print(arr, len);

  return 0;
}