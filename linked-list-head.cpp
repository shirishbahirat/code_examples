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

    if (head == NULL)
      tail = n;
    n->data = data;
    n->next = head;
    head = n;

    size++;
  }

  virtual void addLast(T data) {
    node<T> *n = new node<T>();

    n->data = data;

    if (tail == NULL) {
      head = n;
    } else {
      tail->next = n;
    }
    n->next = NULL;
    tail = n;
  }

  virtual void reverse() {
    if ((head == NULL) || (head->next == NULL))
      return;

    node<T> *current = head;
    node<T> *previous = NULL;
    node<T> *next = current->next;

    tail = current;

    while (current) {
      next = current->next;
      current->next = previous;
      previous = current;
      current = next;
    }

    head = previous;
  }

  virtual void print_nodes() {

    node<T> *temp = head;

    while (temp) {
      cout << temp->data << " " << flush;
      temp = temp->next;
    }

    cout << endl;
  }

  virtual void removeLast() {
    node<T> *temp = head;

    while (temp->next->next) {
      temp = temp->next;
    }
    tail = temp;
    delete temp->next;
    temp->next = NULL;
  }

  virtual void removeFirst() {
    node<T> *temp = head;

    head = head->next;

    delete temp;
  }

private:
  node<T> *head;
  node<T> *tail;
  uint32_t size;
};

int main(int argc, const char *argv[]) {

  linked_list<uint32_t> *llist = new linked_list<uint32_t>();

  llist->addLast(1);

  llist->addFirst(5);
  llist->addFirst(10);
  llist->addFirst(15);
  llist->addFirst(20);

  llist->addLast(30);

  llist->addFirst(40);

  llist->print_nodes();

  llist->reverse();

  llist->print_nodes();

  llist->removeLast();

  llist->print_nodes();

  llist->removeFirst();

  llist->print_nodes();

  return 0;
}