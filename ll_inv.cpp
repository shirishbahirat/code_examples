#include <iostream>

using namespace std;

struct node {
  node *next;
  int data;
};

void print_nodes(node *head) {

  while (head) {
    cout << head->data << endl;
    head = head->next;
  }
}

void insert(node **head, int data) {

  node *new_node = new node();
  new_node->data = data;
  new_node->next = NULL;

  if (*head == NULL) {
    *head = new_node;
  } else {
    node *current_head = *head;
    *head = new_node;
    new_node->next = current_head;
  }
}

void invert(node **head) {

  if (*head == NULL)
    return;

  node *prev = NULL;
  node *current = *head;
  node *next = current->next;

  while (current->next != NULL) {
    current->next = prev;
    prev = current;
    current = next;
    next = current->next;
  }

  *head = current;
  current->next = prev;
}

int main(int argc, char const *argv[]) {

  node *llist = NULL;

  insert(&llist, 10);
  insert(&llist, 12);
  insert(&llist, 14);

  invert(&llist);

  print_nodes(llist);

  return 0;
}