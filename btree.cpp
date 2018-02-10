#include <iostream>
#include <cstdlib>


struct node {
    int value;
    struct node *left, *right;
};


node* add_new_node(int value)
{
    node* newNode = new node();    
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

node* add_node(node* nextNode, int value)
{

    if (nextNode == NULL) return add_new_node(value);

    if (value < nextNode->value)
        nextNode->left  = add_node(nextNode->left, value);
    else if (value > nextNode->value)
        nextNode->right = add_node(nextNode->right, value);   
 
    return nextNode;
}

void print_inorder(node *root)
{
    if (root != NULL)
    {
        print_inorder(root->left);
        std::cout << root->value << std::endl;
        print_inorder(root->right);
    }
}

int main(int argc, char* argv[])
{

    struct node *root = NULL;
    root = add_node(root, 5);
    add_node(root, 3);
    add_node(root, 2);
    add_node(root, 4);
    add_node(root, 1);
    add_node(root, 7);
    add_node(root, 6);
    add_node(root, 8);
    add_node(root, 10);
    add_node(root, 9);
  
    print_inorder(root);

    return 0;
}

