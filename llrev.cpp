#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

void append(ListNode **head, int val) {
  if ((*head) == nullptr) {
    (*head) = new ListNode(0);
    (*head)->val = val;
    (*head)->next = nullptr;
    return;
  }

  ListNode *pnode = (*head);

  while ((*head)->next) {
    (*head) = (*head)->next;
  }

  (*head)->next = new ListNode(0);
  (*head) = (*head)->next;
  (*head)->val = val;
  (*head)->next = nullptr;

  (*head) = pnode;
}

void print_node(ListNode *head) {
  while (head) {
    cout << head->val << " ";
    head = head->next;
  }

  cout << endl;
}

class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    ListNode *prev = nullptr;
    ListNode *curr = head;
    ListNode *next = head->next;

    if (head == nullptr)
      return nullptr;
    if (head->next == nullptr)
      return head;

    while (next) {
      curr->next = prev;
      prev = curr;
      curr = next;
      next = curr->next;
    }

    curr->next = prev;
    head = curr;

    return head;
  }
};

int main(int argc, char const *argv[]) {

  ListNode *head = nullptr;

  Solution *s = new Solution();

  append(&head, 1);
  append(&head, 2);
  append(&head, 3);
  append(&head, 4);
  append(&head, 5);
  append(&head, 6);

  ListNode *middle = s->reverseList(head);

  print_node(middle);

  return 0;
}