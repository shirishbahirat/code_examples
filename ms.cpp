#include <iostream>

using namespace std;

void merge(int data[], int low, int mid, int high) {

  int idx = low;
  int idy = mid + 1;
  int idm = 0;

  int temp[high - low + 1];

  while ((idx <= mid) && (idy <= high)) {

    if (data[idx] < data[idy]) {
      temp[idm++] = data[idx++];
    } else {
      temp[idm++] = data[idy++];
    }
  }

  for (; idx <= mid;) {
    temp[idm++] = data[idx++];
  }

  for (; idy <= high;) {
    temp[idm++] = data[idy++];
  }

  for (int i = low, j = 0; i <= high;) {
    data[i++] = temp[j++];
  }
}

void merge_sort(int data[], int low, int high) {

  cout << low << " " << high << ":"
       << " ";
  for (int i = low; i <= high; ++i) {
    cout << data[i] << " ";
  }
  cout << endl;

  if (high > low) {
    int mid = (low + high) / 2;
    merge_sort(data, low, mid);
    merge_sort(data, mid + 1, high);
    merge(data, low, mid, high);
  }
}

int main(int argc, char const *argv[]) {

  int data[] = {7, 3, 2, 4, 14, 8, 9, 12, 1, 5, 7, 13, 6, 10, 11};
  int len = (sizeof(data) / sizeof(data[0])) - 1;

  merge_sort(data, 0, len);

  for (int i = 0; i <= len;) {
    cout << data[i++] << " ";
  }
  cout << endl;

  return 0;
}