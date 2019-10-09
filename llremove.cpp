#include <iostream>
#include <vector>

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
  ListNode *removeElements(ListNode *head, int val) {

    ListNode *new_head = nullptr;

    if (head == nullptr)
      return head;

    if (head->val == val) {
      if (head->next) {
        head = head->next;
      } else {
        return nullptr;
      }
      new_head = head->next;
    } else {
      new_head = head;
    }

    while (head->next) {
      if (head->next->val == val) {
        if (head->next) {
          head->next = head->next->next;
        } else {
          head->next = nullptr;
          break;
        }
      }
      head = head->next;
    }

    return new_head;
  }
};

int main(int argc, char const *argv[]) {

  ListNode *head = nullptr;

  Solution *s = new Solution();

  append(&head, 1);
  append(&head, 2);
  append(&head, 2);
  append(&head, 4);
  append(&head, 5);
  append(&head, 6);

  ListNode *phead = s->removeElements(head, 5);

  print_node(phead);

  return 0;
}