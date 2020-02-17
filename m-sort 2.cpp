#include <iostream>

using namespace std;

void merge(int data[], int low, int mid, int high)
{

  int i = low;
  int j = mid + 1;
  int as = low - mid + 1;
  int bs = high - mid;
  int len = al + bl;

  int temp[len];

  while ((i < (mid + 1)) && (j < high))
  {
    if (data[i] < data[j])
    {
      temp[k++] = data[i++];
    }
    else
    {
      temp[k++] = data[j++];
    }
  }

  for (; j < bs;)
  {
    c[k++] = b[j++];
  }

  for (; i < as;)
  {
    c[k++] = a[i++];
  }
}

void merge_sort(int data[], int low, int high)
{

  int mid = (low + high) / 2;

  if (mid >= high)
    return;

  cout << "call " << low << " " << mid << " " << high << endl;

  for (int i = low; i <= high; ++i)
  {
    cout << data[i] << ' ';
  }
  cout << endl;

  merge_sort(data, low, mid);
  merge_sort(data, mid + 1, high);
  merge(data, low, mid, high);
}

int main(int argc, char const *argv[])
{

  int data[] = {3, 4, 5, 11, 12, 8, 7, 6, 5, 2};
  int len = (sizeof(data) / sizeof(int)) - 1;

  merge_sort(data, 0, len);

  return 0;
}