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

  node *phead = (*head);

  while ((*head)->next) {
    (*head) = (*head)->next;
  }

  (*head)->next = new node();
  (*head) = (*head)->next;

  (*head)->data = data;
  (*head)->next = nullptr;

  (*head) = phead;
}

int main(int argc, char const *argv[]) {

  node *head = nullptr;

  append(&head, 1000);
  append(&head, 2000);
  append(&head, 3000);
  append(&head, 4000);
  append(&head, 5000);

  print_nodes(head);

  return 0;
}