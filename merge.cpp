#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{

  uint32_t a[] = {2, 5, 8, 9, 11};
  uint32_t b[] = {1, 3, 4, 7};
  uint32_t as = sizeof(a) / sizeof(a[0]);
  uint32_t bs = sizeof(b) / sizeof(b[0]);
  uint32_t cs = as + bs;
  uint32_t c[cs];

  uint32_t i = 0, j = 0, k = 0;

  while ((i < as) && (j < bs))
  {
    if (a[i] < b[j])
    {
      c[k++] = a[i++];
    }
    else
    {
      c[k++] = b[j++];
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

  for (uint32_t m = 0; m < cs; ++m)
  {
    cout << c[m] << " ";
  }
  cout << endl;

  return 0;
}