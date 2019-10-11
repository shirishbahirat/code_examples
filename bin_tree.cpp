#include <iostream>

using namespace std;

struct node {
  int data;
  node *left;
  node *right;

  node(int d, node *l, node *r) : data(d), left(l), right(l) {}
};

node *insert_node(node *tree, int data, node *left, node *right) {
  if (tree == NULL) {
    tree = new node(data, NULL, NULL);
  } else if (tree->data < data) {
    tree = insert_node(tree->left, data, tree->left, NULL);
  } else {
    tree = insert_node(tree->right, data, NULL, tree->right);
  }

  return tree;
}

void print_node(node *tree) {

  if (tree == NULL)
    return;

  cout << tree->data << endl;

  print_node(tree->left);
  print_node(tree->right);
}

int main(int argc, char const *argv[]) {

  node *bin_tree = NULL;

  for (int i = 0; i < 10; ++i) {
    bin_tree = insert_node(bin_tree, i, NULL, NULL);
  }

  print_node(bin_tree);

  return 0;
}