#include <iostream>

using namespace std;

void swap(int data[], int x, int y)
{

  if (x >= y)
    return;

  int temp = data[x];
  data[x] = data[y];
  data[y] = temp;
}

int partition(int data[], int low, int high)
{

  int pivot = low, i = low, j = high;

  while (i < j)
  {
    while ((data[i] <= data[pivot]) && (i < high))
      ++i;

    while ((data[j] > data[pivot]) && (j > low))
      --j;

    swap(data, i, j);
  }

  swap(data, pivot, j);

  cout << j << endl;
  return j;
}

void quick_sort(int data[], int low, int high)
{
  if (high > low)
  {
    int mid = partition(data, low, high);
    quick_sort(data, low, mid);
    quick_sort(data, mid + 1, high);
  }
}

int main(int argc, char const *argv[])
{
  int data[] = {7, 3, 4, 2, 15, 8, 9, 12, 1, 5, 0, 14, 6, 10, 11, 13};
  int len = (sizeof(data) / sizeof(data[0])) - 1;

  quick_sort(data, 0, len);

  for (int i = 0; i <= len; ++i)
    cout << data[i] << " ";
  cout << endl;

  return 0;
}