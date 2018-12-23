#include <iostream>
#include <vector>

using namespace std;

int get_parent(int index) {

  bool right_node = false;
  int parent = 0;

  if (index % 2)
    right_node = true;

  if (right_node)
    parent = (index - 2) / 2;
  else
    parent = (index - 1) / 2;

  return parent;
}
void max_heap(vector<int> &v, int index) {

  int parent = index;
  int left = 2 * index + 1;
  int right = 2 * index + 2;

  if (left < v.size() && (v.at(left) > v.at(parent)))
    parent = left;

  if (right < v.size() && (v.at(right) > v.at(parent)))
    parent = right;

  if (parent != index) {

    swap(v[parent], v[index]);

    parent = get_parent(index);

    max_heap(v, parent);
  }
}

void remove(vector<int> &v, int element) {
  vector<int>::iterator itr = find(v.begin(), v.end(), element);

  if (itr != v.cend()) {
    int index = distance(v.begin(), itr);
    cout << "Element index " << index << endl;
    swap(v[0], v[index]);
    v.erase(v.begin());

    int parent = get_parent(index);
    max_heap(v, parent);

  } else {
    cout << "Element not found" << endl;
  }

  if (v.size() == 1)
    return;
}

void insert(vector<int> &v, int element) {

  v.push_back(element);

  if (v.size() == 1)
    return;

  int parent = get_parent(v.size());
  max_heap(v, parent);
}

int main(int argc, char const *argv[]) {

  vector<int> heap;

  insert(heap, 20);
  insert(heap, 10);
  insert(heap, 30);
  insert(heap, 50);
  insert(heap, 70);
  insert(heap, 90);
  insert(heap, 100);
  insert(heap, 15);

  for (int i = 0; i < heap.size(); ++i)
    cout << heap.at(i) << " " << flush;

  cout << endl;

  remove(heap, 20);

  for (int i = 0; i < heap.size(); ++i)
    cout << heap.at(i) << " " << flush;

  cout << endl;

  return 0;
}