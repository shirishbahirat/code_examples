#include <iostream>

using namespace std;

void merge(int data[], int low, int mid, int high)
{
  int len = high - low + 1;
  int temp[len];
  int x = low, y = mid + 1, k = 0;

  while ((x <= mid) && (y <= high))
  {
    if (data[x] < data[y])
      temp[k++] = data[x++];
    else
      temp[k++] = data[y++];
  }

  for (; x <= mid;)
    temp[k++] = data[x++];

  for (; y <= high;)
    temp[k++] = data[y++];

  for (int i = 0, j = low; i < len; ++i)
  {
    data[j++] = temp[i];
  }

  cout << low << " " << high << " : " << mid << endl;
}

void merge_sort(int data[], int low, int high)
{
  if (low < high)
  {
    int mid = (low + high) / 2;
    merge_sort(data, low, mid);
    merge_sort(data, mid + 1, high);
    merge(data, low, mid, high);
  }
}

int main(int argc, char const *argv[])
{

  int data[] = {7, 3, 4, 2, 15, 8, 9, 12, 1, 5, 0, 14, 6, 10, 11, 13};
  int len = (sizeof(data) / sizeof(data[0])) - 1;

  merge_sort(data, 0, len);

  for (int i = 0; i <= len; ++i)
    cout << data[i] << " ";
  cout << endl;

  return 0;
}