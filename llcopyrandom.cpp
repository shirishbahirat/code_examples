#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
  int val;
  Node *next;
  Node *random;

  Node() {}

  Node(int _val, Node *_next, Node *_random) {
    val = _val;
    next = _next;
    random = _random;
  }
};

void append(Node **head, int val) {
  if ((*head) == nullptr) {
    (*head) = new Node(0, nullptr, nullptr);
    (*head)->val = val;
    (*head)->next = nullptr;
    return;
  }

  Node *pnode = (*head);

  while ((*head)->next) {
    (*head) = (*head)->next;
  }

  (*head)->next = new Node(0, nullptr, nullptr);
  (*head) = (*head)->next;
  (*head)->val = val;
  (*head)->next = nullptr;

  (*head) = pnode;
}

void link_random(Node **head, int src, int des) {

  Node *src_node = nullptr;
  Node *des_node = nullptr;

  Node **shead = head;

  Node *phead = (*head);

  while ((*shead)->val != src) {
    (*shead) = (*shead)->next;
  }
  src_node = (*shead);
  (*head) = phead;

  Node **dhead = head;

  while ((*dhead)->val != des) {
    (*dhead) = (*dhead)->next;
  }
  des_node = (*dhead);

  cout << src_node->val << " " << des_node->val << endl;

  src_node->random = des_node;

  (*head) = phead;
}

void print_node(Node *head) {

  while (head) {
    cout << head->val << " ";
    head = head->next;
  }

  cout << endl;
}

class Solution {
public:
  Node *copyRandomList(Node *head) {

    Node *new_node = nullptr;
    Node *phead = head;

    while (head) {
      new_node = new Node(head->val, head->next, nullptr);
      head->next = new_node;
      head = head->next->next;
    }

    head = phead;

    while (head) {
      head->next->random = head->random;
      head = head->next->next;
    }

    head = phead;

    Node *prev_node = nullptr;
    Node *new_head = phead->next;

    prev_node = head;
    head = head->next;
    delete prev_node;

    while (head->next) {
      prev_node = head->next;
      head->next = prev_node->next;
      delete prev_node;
      head = head->next;
    }

    return new_head;
  }
};

int main(int argc, char const *argv[]) {

  Node *head = nullptr;

  Solution *s = new Solution();

  append(&head, 1);
  append(&head, 2);
  append(&head, 3);
  append(&head, 4);
  append(&head, 5);
  append(&head, 6);

  link_random(&head, 1, 4);
  link_random(&head, 2, 1);
  link_random(&head, 3, 2);
  link_random(&head, 4, 6);
  link_random(&head, 5, 3);
  link_random(&head, 6, 5);

  Node *phead = s->copyRandomList(head);

  print_node(phead);

  return 0;
}