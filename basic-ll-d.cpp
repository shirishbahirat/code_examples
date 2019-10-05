#include <iostream>

using namespace std;

struct node {
  int data;
  node *next;
};

void print_nodes(node *head) {
  while (head) {
    cout << head->data << " ";
    head = head->next;
  }

  cout << endl;
}

void append(node **head, int data) {
  if ((*head) == nullptr) {
    (*head) = new node();
    (*head)->data = data;
    (*head)->next = nullptr;
    return;
  }

  node *pnode = (*head);

  while ((*head)->next) {
    (*head) = (*head)->next;
  }

  (*head)->next = new node();
  (*head) = (*head)->next;
  (*head)->data = data;
  (*head)->next = nullptr;

  (*head) = pnode;

  return;
}

int main(int argc, char const *argv[]) {

  node *head = nullptr;

  append(&head, 111111);
  append(&head, 222222);
  append(&head, 333333);
  append(&head, 444444);

  print_nodes(head);

  return 0;
}