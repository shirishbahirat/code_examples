#include <iostream>
using namespace std;
int main() {
  int a1[32], a2[32], n1, i, n2;

  n1 = 9;
  n2 = 1;

  for (i = 0; i < 32; ++i) {
    a1[i] = 0;
    a2[i] = 0;
  }

  for (i = 0; n1 > 0; i++) {
    a1[i] = n1 % 2;
    n1 = n1 >> 1;
  }

  for (i = i - 1; i >= 0; i--) {
    cout << a1[i];
  }

  cout << endl;

  for (i = 0; n2 > 0; i++) {
    a2[i] = n2 % 2;
    n2 = n2 >> 1;
  }

  for (i = i - 1; i >= 0; i--) {
    cout << a2[i];
  }
  cout << endl;

  int hamming = 0;
  for (i = 0; i < 32; ++i) {
    if ((a1[i] - a2[i]) != 0) {
      hamming++;
    }
  }
  cout << "hamming " << hamming << endl;
}