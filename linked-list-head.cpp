#include <iostream>
using namespace std;

template <class T> class node {
public:
  node<T>() {}
  ~node<T>() {}

  T data;
  node<T> *next;
};

template <class T> class linked_list {

public:
  linked_list<T>() : head(NULL), tail(NULL) {}
  ~linked_list<T>() {}

  virtual void addFirst(T data) {
    node<T> *n = new node<T>();
    n->data = data;
    n->next = head;
    head = n;

    size++;
  }
  virtual void addLast(T data) {}

  virtual void print_nodes() {

    node<T> *temp = head;

    while (temp) {
      cout << temp->data << endl;
      temp = temp->next;
    }
  }

private:
  node<T> *head;
  node<T> *tail;
  uint32_t size;
};

int main(int argc, const char *argv[]) {

  linked_list<uint32_t> *llist = new linked_list<uint32_t>();

  llist->addFirst(5);
  llist->addFirst(10);
  llist->addFirst(15);
  llist->addFirst(20);

  llist->print_nodes();

  return 0;
}