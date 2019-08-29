#include <iostream>

using namespace std;

struct tree {
  int value;
  tree *left;
  tree *right;

  tree(int v, tree *l, tree *r) : value(v), left(l), right(r) {}
};

void print_inorder(tree *btree) {

  if (btree == nullptr)
    return;

  print_inorder(btree->left);
  cout << btree->value << " ";
  print_inorder(btree->right);
}

void print_preorder(tree *btree) {

  if (btree == nullptr)
    return;

  cout << btree->value << " ";
  print_preorder(btree->left);
  print_preorder(btree->right);
}

void print_postorder(tree *btree) {

  if (btree == nullptr)
    return;

  print_postorder(btree->left);
  print_postorder(btree->right);
  cout << btree->value << " ";
}

void insert(int value, tree *&btree) {
  if (btree == nullptr) {
    btree = new tree(value, nullptr, nullptr);
  } else if (btree->value < value) {
    if (btree->left == nullptr) {
      btree->left = new tree(value, nullptr, nullptr);
    } else {
      insert(value, btree->left);
    }

  } else if (btree->value >= value) {
    if (btree->right == nullptr) {
      btree->right = new tree(value, nullptr, nullptr);
    } else {
      insert(value, btree->right);
    }
  }
}

int main(int argc, char const *argv[]) {

  tree *btree = nullptr;

  insert(2, btree);
  insert(3, btree);
  insert(4, btree);
  insert(5, btree);
  insert(6, btree);
  insert(7, btree);
  insert(8, btree);
  insert(9, btree);

  print_inorder(btree);
  cout << endl;

  print_postorder(btree);
  cout << endl;

  print_preorder(btree);
  cout << endl;

  return 0;
}