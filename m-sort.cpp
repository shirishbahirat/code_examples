#include <iostream>

using namespace std;

void merge(int data[], int low, int mid, int high) {

  int i = low;
  int j = mid + 1;
  int k = 0;
  int as = mid - low + 1;
  int bs = high - mid;
  int len = as + bs;

  cout << "merge " << len << endl;

  int temp[len];

  while ((i <= mid) && (j <= high)) {
    if (data[i] < data[j]) {
      temp[k++] = data[i++];
    } else {
      temp[k++] = data[j++];
    }
  }

  cout << k << " " << j << " " << low << " " << high << endl;

  for (; i <= mid;) {
    temp[k++] = data[i++];
  }

  for (; j <= high;) {
    temp[k++] = data[j++];
  }

  cout << "mdone ";
  for (int x = low, y = 0; y < len; ++x, ++y) {
    data[x] = temp[y];
    cout << data[x] << " ";
  }
  cout << endl;
}

void merge_sort(int data[], int low, int high) {

  int mid = (low + high) / 2;

  if (mid >= high)
    return;

  cout << "call " << low << " " << mid << " " << high << endl;

  for (int i = low; i <= high; ++i) {
    cout << data[i] << ' ';
  }
  cout << endl;

  merge_sort(data, low, mid);
  merge_sort(data, mid + 1, high);
  merge(data, low, mid, high);
}

int main(int argc, char const *argv[]) {

  int data[] = {3, 4, 5, 11, 12, 8, 7, 6, 9, 2};
  int len = (sizeof(data) / sizeof(int)) - 1;

  merge_sort(data, 0, len);

  for (int i = 0; i <= len; ++i) {
    cout << data[i] << ' ';
  }
  cout << endl;

  return 0;
}