#include <iostream>
#include <map>
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
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

    if ((headA == nullptr) || (headB == nullptr))
      return nullptr;

    if ((headA->next->next == nullptr) || (headB->next->next == nullptr)) {
      if (headA->next->val == headB->next->val) {
        return headA->next;
      } else {
        return nullptr;
      }
    }

    map<int, ListNode *> nodemap;

    while (headB->next) {
      nodemap[headB->next->val] = headB->next;

      headB = headB->next;
    }

    while (headA->next) {
      if (nodemap[headA->next->val] &&
          (headA->next == nodemap[headA->next->val])) {
        return headA->next;
      }

      headA = headA->next;
    }

    return nullptr;
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

  ListNode *phead = s->getIntersectionNode(head, 5);

  print_node(phead);

  return 0;
}