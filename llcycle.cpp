#include <iostream>
#include <map>

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

  int count = 0;
  map<int, int> nodes;

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
  bool hasCycle(ListNode *head) {

    map<ListNode *, int> nodes;
    map<ListNode *, int>::iterator it;
    int count = 0;

    while (head) {

      it = nodes.find(head);

      if (it == nodes.end()) {
        nodes[head] = count;
        count++;
      } else {
        return false;
      }

      head = head->next;
    }

    return false;
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

  bool status = s->hasCycle(head);

  print_node(head);

  return 0;
}