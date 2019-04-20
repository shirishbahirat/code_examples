

class Problem {
public:
  Problem() {}
  ~Problem() {}

  ListNode *head;

  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {

    if (l1 == NULL)
      return l2;
    if (l2 == NULL)
      return l1;

    if (l1->val < l2->val) {
      head = l1;
    } else {
      head = l2;
      l2 = l1;
      l1 = head;
    }
    while (l1->next != NULL) {
      if (l1->next->val > l2->val) {
        ListNode *tmp = l1->next;
        l1->next = l2;
        l2 = tmp;
      }
      l1 = l1->next;
    }
    l1->next = l2;
    return head;
  }
};