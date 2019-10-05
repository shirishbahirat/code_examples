#include <iostream>

using namespace std;

struct node {
  int data;
  node *next;
};

void append(node **head, int data) {

  if ((*head) == nullptr) {

    (*head) = new node();
    (*head)->data = data;
    (*head)->next = nullptr;
    cout << "1st node" << endl;

    return;
  }

  node *new_head = *head;

  while ((*head)->next != nullptr) {
    (*head) = (*head)->next;
  }

  (*head)->next = new node();
  (*head) = (*head)->next;

  (*head)->data = data;
  (*head)->next = nullptr;

  (*head) = new_head;
}

void print_nodes(node *head) {
  while (head) {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}

int main(int argc, char const *argv[]) {

  node *head = nullptr;

  append(&head, 10);
  print_nodes(head);

  cout << "done" << endl;
  append(&head, 20);
  print_nodes(head);

  cout << "done" << endl;
  append(&head, 30);
  print_nodes(head);

  cout << "done" << endl;
  append(&head, 40);
  print_nodes(head);

  cout << "done" << endl;
  append(&head, 50);
  print_nodes(head);

  return 0;
}