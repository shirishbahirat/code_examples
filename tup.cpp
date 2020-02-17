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
  int parent = 0;
  bool taken = true;
  while (taken)
  {
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    taken = false;

    if ((left <= len) && (right <= len))
    {
      if (data[left] > data[right])
        parent = left;
      else
        parent = right;

      if (data[index] < data[parent])
      {
        swap(data, index, parent);
        index = parent;
        taken = true;
      }
    }
  }
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
  int data[] = {6, 4, 8, 9, 3, 2, 10, 5};
  int len = sizeof(data) / sizeof(data[0]) - 1;

  heapify(data, len);

  for (int i = len; i > 0; --i)
  {
    swap(data, 0, i);
    trickle_down(data, i - 1);
  }
  swap(data, 0, 1);

  for (int i = 0; i <= len; ++i)
  {
    cout << data[i] << ' ';
  }
  cout << endl;

  return 0;
}