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
  bool isPalindrome(ListNode *head) {
    if (head == nullptr)
      return true;

    vector<int> values;
    ListNode *revhead = head;

    while (revhead) {
      values.push_back(revhead->val);
      cout << revhead->val << " ";
      revhead = revhead->next;
    }

    cout << endl;

    for (int i = 0, j = values.size(); i < j; ++i, --j) {
      if (values.at(i) != values.at(j - 1)) {
        return false;
      }
    }

    return true;
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

  bool status = s->isPalindrome(head);

  print_node(head);

  return 0;
}