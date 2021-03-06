#include <iostream>

using namespace std;

struct node {
  int data;
  node *next;
};

void print_node(node *head) {
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
}

int main(int argc, char const *argv[]) {

  node *head = nullptr;

  append(&head, 1);
  append(&head, 11);
  append(&head, 111);
  append(&head, 1111);

  print_node(head);

  return 0;
}