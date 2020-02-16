#include <iostream>

using namespace std;

void swap(int data[], int x, int y)
{
  int temp = data[x];
  data[x] = data[y];
  data[y] = temp;
}

int main(int argc, char const *argv[])
{

  int data[] = {0, 3, 2, 2, 14, 8, 9, 12, 1, 5, 0, 13, 6, 10, 11, 25};
  int len = (sizeof(data) / sizeof(data[0]));

  for (int index = 0; index < len; ++index)
  {
    int smallest = index;
    cout << data[smallest] << " : ";
    for (int idx = index; idx < len; ++idx)
    {
      if (data[smallest] > data[idx])
      {
        smallest = idx;
      }
      cout << data[idx] << " ";
    }
    swap(data, index, smallest);
    cout << ":" << data[smallest] << endl;
  }

  for (int i = 0; i < len; ++i)
    cout << data[i] << " ";
  cout << endl;

  return 0;
}