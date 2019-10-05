#include <iostream>

using namespace std;

struct node {
  int data;
  node *next;
};

void print_nodes(node *head) {
  while (head) {
    cout << head->data << " ";
    head = head->next;
  }
}

int main(int argc, char const *argv[]) { return 0; }