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
  ListNode *deleteDuplicates(ListNode *head) {

    ListNode *old_head = head;

    while (head) {
      while ((head->next) && ((head->val) == (head->next->val))) {
        head->next = head->next->next;
      }
      head = head->next;
    }

    return old_head;
  }
};
int main(int argc, char const *argv[]) {

  ListNode *head = nullptr;

  Solution *s = new Solution();

  append(&head, 1);
  append(&head, 1);
  append(&head, 1);
  append(&head, 2);
  append(&head, 3);
  append(&head, 3);

  ListNode *nodup = s->deleteDuplicates(head);

  print_node(nodup);

  return 0;
}