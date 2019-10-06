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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *new_node = nullptr;
    ListNode *prev_node = nullptr;
    int carry = 0;
    ListNode *head = nullptr;

    while (l1 || l2 || carry) {

      new_node = new ListNode(0);
      if (head == nullptr) {
        head = new_node;
      }
      if (prev_node)
        prev_node->next = new_node;
      prev_node = new_node;

      if (l1 && l2) {
        int sum = (l1->val + l2->val + carry);
        new_node->val = sum % 10;
        carry = sum / 10;
      }

      if (l1 && (l2 == nullptr)) {
        int sum = (l1->val + carry);
        new_node->val = sum % 10;
        carry = sum / 10;
      }

      if (l2 && (l1 == nullptr)) {
        int sum = (l2->val + carry);
        new_node->val = sum % 10;
        carry = sum / 10;
      }

      if ((l2 == nullptr) && (l1 == nullptr) && carry) {
        new_node->val = carry;
        carry = 0;
      }

      if (l1)
        l1 = l1->next;
      if (l2)
        l2 = l2->next;
    }

    return head;
  }
};

int main(int argc, char const *argv[]) {

  ListNode *l1 = nullptr;
  ListNode *l2 = nullptr;
  ListNode *l3 = nullptr;

  Solution *s = new Solution();
  /*
    append(&l1, 9);

    append(&l2, 1);
    append(&l2, 9);
    append(&l2, 9);
    append(&l2, 9);
    append(&l2, 9);
    append(&l2, 9);
    append(&l2, 9);
    append(&l2, 9);
    append(&l2, 9);
    append(&l2, 9);
  */

  append(&l1, 0);
  append(&l2, 0);

  l3 = s->addTwoNumbers(l1, l2);

  print_node(l1);
  print_node(l2);
  print_node(l3);

  return 0;
}