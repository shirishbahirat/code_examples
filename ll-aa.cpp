#include <cassert>
#include <iostream>

using namespace std;

struct node {
  int data;
  node *next;
};

bool insert_node_at_tail(node *new_node, int data, node **head, node **tail) {

  assert(new_node);

  if (*head == nullptr) {
    (*head) = new_node;
    (*head)->data = data;
    (*head)->next = nullptr;
    (*tail) = new_node;
  } else {

    node *new_head = *head;

    while ((*head)->next != nullptr) {

      (*head) = (*head)->next;
    }

    (*head)->next = new_node;
    new_node->data = data;
    new_node->next = nullptr;

    (*tail) = new_node;

    (*head) = new_head;
  }

  return true;
}

bool insert_node_at_head(node *new_node, int data, node **head, node **tail) {

  assert(new_node);

  if (*head == nullptr) {
    (*head) = new_node;
    (*head)->data = data;
    (*head)->next = nullptr;
    (*tail) = new_node;
  } else {
    new_node->next = (*head);
    new_node->data = data;
    (*head) = new_node;
  }

  return true;
}

void print_all_nodes(node *head) {

  while (head != nullptr) {
    cout << head->data << endl;
    head = head->next;
  }
}

int main(int argc, char const *argv[]) {

  node *linked_list = nullptr;
  node *head = nullptr;
  node *tail = nullptr;
  node *new_node = nullptr;
  int data = 0;

  new_node = new node();
  insert_node_at_head(new_node, data++, &head, &tail);

  print_all_nodes(head);

  new_node = new node();
  insert_node_at_head(new_node, data++, &head, &tail);

  print_all_nodes(head);

  new_node = new node();
  insert_node_at_head(new_node, data++, &head, &tail);

  print_all_nodes(head);

  new_node = new node();
  insert_node_at_head(new_node, data++, &head, &tail);

  print_all_nodes(head);

  new_node = new node();
  insert_node_at_tail(new_node, data++, &head, &tail);

  cout << "After tail append" << endl;

  print_all_nodes(head);

  new_node = new node();
  insert_node_at_tail(new_node, data++, &head, &tail);

  print_all_nodes(head);

  return 0;
}