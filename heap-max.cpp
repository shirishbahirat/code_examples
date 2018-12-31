#include <algorithm>
#include <iostream>

using namespace std;

// height of trre at given node log2(n+1) - 1
// children based on parent 2*parent + 1, 2*parent +2
// parent based on children floor((child-1)/2)

class max_heap {
public:
  max_heap() : current_position(0), max_position(100) {
    for (uint32_t i = 0; i < max_position; ++i) {
      arr[i] = 0;
    }
  }

  ~max_heap() {}

  virtual void trickle_up(uint32_t position) {

    if (!position)
      return;

    uint32_t parent = (position - 1) / 2;

    if (arr[parent] < arr[position])
      swap(arr[parent], arr[position]);

    trickle_up(parent);
  }

  virtual void add(uint32_t element) {
    if (current_position < max_position)
      arr[current_position] = element;

    trickle_up(current_position);

    ++current_position;
  }

  virtual void print_heap() {
    for (uint32_t i = 0; i < current_position; ++i)
      cout << arr[i] << " " << flush;
    cout << endl;
  }

  virtual void heap_sort() {
    uint32_t index = current_position - 1;

    for (uint32_t i = 0; i < current_position; ++i) {
      swap(arr[i], arr[index]);
      trickle_up(index);
    }

    swap(arr[index - 1], arr[index]);
  }

private:
  uint32_t current_position;
  uint32_t max_position;
  uint32_t arr[];
};

int main(int argc, const char *argv[]) {

  max_heap *heap = new max_heap();

  heap->add(100);
  heap->add(200);
  heap->add(20);
  heap->add(40);
  heap->add(400);

  heap->print_heap();

  heap->heap_sort();

  heap->print_heap();

  return 0;
}