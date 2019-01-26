#include <iostream>
using namespace std;
#include <gtest/gtest.h>

void heap_sort(uint32_t arr[], uint32_t length);

TEST(heap_sort, sort_array) {
  uint32_t arr[] = {23, 32, 43, 16, 77, 32, 10, 87, 99};
  uint32_t length = sizeof(arr) / sizeof(uint32_t);

  heap_sort(arr, length);

  EXPECT_EQ(arr[0], 10);
  EXPECT_EQ(arr[1], 16);
  EXPECT_EQ(arr[2], 23);
  EXPECT_EQ(arr[3], 32);
}

void print_array(uint32_t arr[], uint32_t length) {

  for (uint32_t i = 0; i < length; ++i) {
    cout << arr[i] << " " << flush;
  }
  cout << endl;
}

void swap(uint32_t arr[], uint32_t l, uint32_t h) {
  if (l != h) {
    arr[l] ^= arr[h] ^= arr[l] ^= arr[h];
  }
}

void max_heap(uint32_t arr[], uint32_t length, uint32_t index) {
  uint32_t parent = index;
  uint32_t left = 2 * index + 1;
  uint32_t right = 2 * index + 2;

  if (left < length && arr[left] > arr[parent])
    parent = left;
  if (right < length && arr[right] > arr[parent])
    parent = right;

  if (parent != index) {
    swap(arr, parent, index);
    cout << "swap "
         << "index " << index << " " << flush;
    print_array(arr, length);
    max_heap(arr, length, parent);
  }
}

void heap_sort(uint32_t arr[], uint32_t length) {

  for (int i = length / 2 - 1; i >= 0; --i) {
    max_heap(arr, length, (uint32_t)i);
    cout << "heap " << flush;
    print_array(arr, length);
  }

  for (int i = length - 1; i >= 0; --i) {
    swap(arr, 0, (uint32_t)i);
    max_heap(arr, (uint32_t)i, 0);
    cout << "sort " << flush;
    print_array(arr, length);
  }
}
int main(int argc, char **argv) {
  uint32_t arr[] = {23, 32, 43, 16, 77, 32, 10, 87, 99};
  uint32_t length = sizeof(arr) / sizeof(uint32_t);

  print_array(arr, length);
  heap_sort(arr, length);

  print_array(arr, length);

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}