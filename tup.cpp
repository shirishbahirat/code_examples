#include <iostream>

using namespace std;

void swap(int data[], int x, int y)
{
  int temp = data[x];
  data[x] = data[y];
  data[y] = temp;
}

void trickle_down(int data[], int len)
{
  int index = 0;
  int left = 2 * index + 1;
  int right = 2 * index + 2;
  int parent;

  if (data[left] > data[right])
    parent = left;
  else
    parent = right;

  if (data[index] < data[parent])
    swap(data, index, parent);

  index = parent;
}

void trickle_up(int data[], int index)
{

  while (index)
  {

    int parent = (index - 1) / 2;

    if (data[index] > data[parent])
    {
      swap(data, index, parent);
    }

    index = parent;
  }
}

void heapify(int data[], int len)
{
  for (int i = 0; i <= len; ++i)
    trickle_up(data, i);
}

int main(int argc, char const *argv[])
{
  // int data[] = {6, 4, 8, 9, 3, 2, 10, 5};
  int data[] = {4, 8, 9, 5, 3, 2, 6, 10};
  int len = sizeof(data) / sizeof(data[0]) - 1;

  // heapify(data, len);

  trickle_down(data, len);

  for (int i = 0; i <= len; ++i)
  {
    cout << data[i] << ' ';
  }
  cout << endl;

  return 0;
}