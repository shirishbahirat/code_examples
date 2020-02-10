#include <iostream>

using namespace std;

void swap(int data[], int x, int y) {
  if (x >= y)
    return;

  int temp = data[x];
  data[x] = data[y];
  data[y] = temp;
}

int partition(int data[], int low, int high) {
  int pivot = data[low];
  int p = low;
  int i = low;
  int j = high;

  cout << data[low] << " " << low << " " << high << endl;

  while (i < j) {

    while (data[i] <= pivot) {
      i++;
    }

    while (data[j] > pivot) {
      j--;
    }

    for (int m = low; m <= high; ++m) {
      cout << data[m] << " ";
    }
    cout << ": " << i << " " << j;
    cout << endl;
    swap(data, i, j);
  }

  swap(data, p, j);

  cout << "m: " << i << " " << j << endl;

  return j;
}

void quick_sort(int data[], int low, int high) {

  if (high > low) {
    int mid = partition(data, low, high);
    cout << mid << endl;
    quick_sort(data, low, mid);
    quick_sort(data, mid + 1, high);
  }
}

int main(int argc, char const *argv[]) {

  int data[] = {7, 3, 2, 4, 14, 8, 9, 12, 1, 5, 0, 13, 6, 10, 11, 25};
  int len = (sizeof(data) / sizeof(data[0])) - 1;

  quick_sort(data, 0, len);

  for (int i = 0; i <= len; ++i) {
    cout << data[i] << ' ';
  }
  cout << endl;

  return 0;
}