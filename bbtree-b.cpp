#include <iostream>
#include <vector>

using namespace std;

struct node {
  int key;
  node *left;
  node *right;

  node(int k, node *l, node *r) : key(k), left(l), right(r) {}
};

void insert(int key, node *&root) {
  if (root == nullptr) {
    root = new node(key, nullptr, nullptr);
    return;
  }

  if (key < root->key) {
    if (root->left == nullptr) {
      root->left = new node(key, nullptr, nullptr);
    } else {
      insert(key, root->left);
    }
  } else if (key >= root->key) {
    if (root->right == nullptr) {
      root->right = new node(key, nullptr, nullptr);

    } else {
      insert(key, root->right);
    }
  }
}

void preorder_print(node *root) {
  if (root == nullptr)
    return;

  cout << root->key << " ";
  preorder_print(root->left);
  preorder_print(root->right);
}

void postorder_print(node *root) {
  if (root == nullptr)
    return;

  postorder_print(root->left);
  postorder_print(root->right);
  cout << root->key << " ";
}

void inorder_print(node *root) {
  if (root == nullptr)
    return;

  inorder_print(root->left);
  cout << root->key << " ";
  inorder_print(root->right);
}

void delete_tree(node *root) {
  if (root != NULL) {
    delete_tree(root->left);
    delete_tree(root->right);
    delete root;
  }
}

int main(int argc, char const *argv[]) {

  node *root = nullptr;
  vector<int> values = {8, 3, 10, 1, 6, 14, 4, 7, 13};

  for (int i = 0; i < values.size(); ++i) {
    insert(values.at(i), root);
  }
  preorder_print(root);
  cout << endl;

  postorder_print(root);
  cout << endl;

  inorder_print(root);
  cout << endl;

  return 0;
}