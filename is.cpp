#include <iostream>

using namespace std;

void swap(int data[], int x, int y) {
  int temp = data[x];
  data[x] = data[y];
  data[y] = temp;
}

int main(int argc, char const *argv[]) {

  int data[] = {4, 3, 2, 22, 14, 8, 9, 12, 1, 5, 0, 13, 6, 10, 11, 25};
  int len = (sizeof(data) / sizeof(data[0]));

  if (len <= 1)
    return 0;

  for (int index = 1; index < len; index++) {
    int jndex = index;

    while (jndex >= 1) {
      if (data[jndex] < data[jndex - 1]) {
        swap(data, jndex, jndex - 1);
      }
      --jndex;
    }
  }

  for (int i = 0; i < len; ++i)
    cout << data[i] << " ";
  cout << endl;

  return 0;
}