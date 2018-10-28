#include <iostream>

using namespace std;

struct node {
	int data;
	node* left;
	node* right;
};


void insert_root(node** root, int data)
{


	if (((*root)->left == NULL) && ((*root)->data > data))
	{
		node* new_node = new node();
		new_node->data = data;
		new_node->left = NULL;
		new_node->right = NULL;

		(*root)->left = new_node;
		return;

	}

	if (((*root)->right == NULL) && ((*root)->data <= data))
	{
		node* new_node = new node();
		new_node->data = data;
		new_node->left = NULL;
		new_node->right = NULL;

		(*root)->right = new_node;
		return;
	}


	if (data >= (*root)->data)
	{
		insert_root(&(*root)->right, data);
	}
	else if (data < (*root)->data)
	{
		insert_root(&(*root)->left, data);
	}

}


void  print_nodes(node* root)
{
	if(root == NULL)
		return;

	if (root->left != NULL)
	{
		cout << "left " << root->left->data << endl;
		print_nodes(root->left);		
	}


	if (root->right != NULL)
	{
		cout << "right " << root->right->data << endl;
		print_nodes(root->right);		
	}



}



int main(int argc, const char* argv[])
{

	node* head = NULL;

	node* new_node = new node();
	new_node->data = 20;

	new_node->left = NULL;
	new_node->right = NULL;
	head = new_node;


	insert_root(&head, 30);
	insert_root(&head, 40);
	insert_root(&head, 10);


	print_nodes(head);




	return 0;
}