#include <iostream>
#include <map>
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
    Node *prev_node = nullptr;
    Node *phead = head;
    Node *prev_head = head;
    Node *new_head = nullptr;
    Node *nhead = nullptr;

    map<Node *, Node *> node_map;

    while (head) {

      new_node = new Node(head->val, nullptr, nullptr);

      if (new_head == nullptr) {
        new_head = new_node;
        nhead = new_head;
      }

      if (prev_node)
        prev_node->next = new_node;

      prev_node = new_node;
      prev_head = head->next;
      node_map[head] = head->next;
      head->next = new_node;

      head = prev_head;
    }

    head = phead;

    while (new_head) {

      new_head->random = head->random->next;

      head = node_map[head];

      new_head = new_head->next;
    }

    new_head = nhead;

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