#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

void print_array(uint32_t *parr, uint32_t len);

void print_array(uint32_t *parr, uint32_t len) {
  for (uint32_t i = 0; i < len; ++i) {
    cout << *parr << " " << flush;
    ++parr;
  }

  cout << endl;
}

void swap(uint32_t arr[], uint32_t l, uint32_t h) {
  if (l != h) {
    arr[l] ^= arr[h] ^= arr[l] ^= arr[h];
  }
}

void heapify(uint32_t arr[], uint32_t len, uint32_t i) {
  uint32_t largest = i;
  uint32_t l = 2 * i + 1;
  uint32_t r = 2 * i + 2;

  if (l < len && arr[l] > arr[largest])
    largest = l;

  if (r < len && arr[r] > arr[largest])
    largest = r;

  if (largest != i) {
    swap(arr, i, largest);
    heapify(arr, len, largest);
  }
}

void heap_sort(uint32_t arr[], uint32_t len) {

  for (int i = (len - 1) / 2; i >= 0; i--) {
    heapify(arr, len, (uint32_t)i);
  }

  for (int i = len - 1; i > 0; i--) {
    swap(arr, 0, (uint32_t)i);

    heapify(arr, (uint32_t)i, 0);
  }
}

uint32_t rnd() { return (uint32_t)rand() % 15; }

void arry_with_random_length(uint32_t arr[], uint32_t len) {
  for (uint32_t i = 0; i < len; ++i) {
    arr[i] = rnd();
  }
}

int main(int argc, const char *argv[]) {

  srand(time(NULL));
  uint32_t len = (uint32_t)(rand() % 15 + 7);
  uint32_t arr[len];

  arry_with_random_length(arr, len);

  print_array(arr, len);

  heap_sort(arr, len);
  print_array(arr, len);

  return 0;
}
