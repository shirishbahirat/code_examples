#include <iostream>

using namespace std;

struct node {
	int data;
	struct node* left;
	struct node* right;
};


static int lookup(struct node* node, int data)
{
	if (node == NULL) return false;
	if (node->data == data) return true;
	if (data < node->data) return(lookup(node->left, data));
	if (data > node->data) return(lookup(node->right, data));
	return 0;
}

struct node* newNode(int data)
{
	struct node* node = new (struct node);

	node->data = data;
	node->left = NULL;
	node->left = NULL;

	return node;
}

struct node* insert(struct node* node, int data)
{
	if (node == NULL) return newNode(data);

	if (data <= node->data) node->left = insert(node->left, data);
	else node->right = insert(node->right, data);

	return node;
}


int main(int argc, const char* argv[])
{

	struct node* node = NULL;

	node = insert(node, 10);

	cout << lookup(node, 10) << endl;

	node = insert(node, 5);

	cout << lookup(node, 5) << endl;

	node = insert(node, 15);

	cout << lookup(node, 15) << endl;


	return 0;
}
