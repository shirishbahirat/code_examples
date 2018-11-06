#include <iostream>
#include <deque>
#include <climits>
#include <vector>
using namespace std;


struct b_tree {

	uint32_t data;
	b_tree* left;
	b_tree* right;
	b_tree* parent;
};


b_tree* create_new_node(uint32_t data)
{
	b_tree* new_node = new b_tree();
	new_node->data = data;
	new_node->left = new_node->right = new_node->parent = NULL;

	return new_node;
}


b_tree* insert_node(b_tree* node, uint32_t data)
{
	static b_tree* parent_node = NULL;

	if (node == NULL)
	{
		b_tree* new_node = create_new_node(data);
		new_node->parent = parent_node;
		return new_node;
	}

	parent_node = node;

	if (node->data > data)
	{
		node->right = insert_node(node->right, data);
	}
	else if (node->data <= data)
	{
		node->left = insert_node(node->left, data);
	}

	return node;
}

void reverse_oder_print(b_tree* node)
{

	if(node == NULL) return;

	if(node->left == NULL && node->right == NULL) {
		cout << node->data << " " << endl;
		return;
	}
	
	reverse_oder_print(node->left);
	cout << node->data << " " << endl;
	reverse_oder_print(node->right);
}

void forward_oder_print(b_tree* node)
{

	if(node == NULL) return;

	if(node->left == NULL && node->right == NULL) {
		cout << node->data << " " << endl;
		return;
	}
	
	forward_oder_print(node->right);
	cout << node->data << " " << endl;
	forward_oder_print(node->left);
}

void post_order_print(b_tree* node)
{
	if(node == NULL) return;

	post_order_print(node->left);
	post_order_print(node->right);
	cout << node->data << " ";
}

void pre_order_print(b_tree* node)
{
	if(node == NULL) return;

	cout << node->data << " ";
	post_order_print(node->left);
	post_order_print(node->right);
}

void delete_tree(b_tree *node)
{
	if(node != NULL) {
		cout << "deleting " << node->data << endl;
	    delete_tree(node->left);
	    delete_tree(node->right);
	    delete node;
	}
}

uint32_t get_level(b_tree* node, uint32_t data, uint32_t level)
{
	if(node == NULL) return level;

	if(data == node->data)
	{
	    return level;
	}
	else if(data < node->data)
	{
	    return get_level(node->left, data, ++level);
	}
	else
	{ 
	    return get_level(node->right, data, ++level);
	}
}

void mirror_tree(b_tree* root)
{
	if(root == NULL) return;
	
	b_tree* tmp;
	mirror_tree(root->left);
	mirror_tree(root->right);

	tmp = root->right;
	root->right = root->left;
	root->left = tmp;
}

b_tree *get_node(b_tree *node, uint32_t data)
{
	if(node == NULL) return node;

	if(data < node->data) 
		return get_node(node->left,data);
	else if( data > node->data)
		return get_node(node->right, data);
	else
		return node;
}

uint32_t tree_max(b_tree *node)
{
	while(node->right) {
		node = node->right;
	}
	return node->data;
}

uint32_t predecessor_in_order(b_tree *node)
{
	if(node->left) 
		return tree_max(node->left);

	b_tree *y = node->parent;
	while(node == y->left) {
		node = y;
		y = y->parent;
	}

	return y->data;
}

void delete_node(b_tree *root, uint32_t data)
{

	b_tree *node, *p, *child, *pred;

	node = get_node(root, data);

	if(node->left == NULL && node->right == NULL) {
		if(node->parent) p = node->parent;
		if(node == p->left) 
			p->left = NULL;
		else
			p->right = NULL;
		delete node;
		return;
	}

	if(node->left && node->right) {
		uint32_t ch_pred = predecessor_in_order(node);
		pred = get_node(root, ch_pred);
		if(pred->parent->left == pred) 
			pred->parent->left = NULL;
		else if(pred->parent->right == pred) 
			pred->parent->right = NULL;
		node->data = pred->data;
		delete pred;
		return;
	}

	if(node->left) 
		child = node->left;
	else if(node->right)
		child = node->right;
	p = node->parent;
	if(p->left && p->left == node) {
		p->left = child;
	}
	else if (p->right && p->right == node) {
		p->right = child;
	}
	child->parent = p;
	delete node;

}


int main(int argc, const char* argv[])
{

	char arr[5] = {1, 3, 4, 5, 6};

	b_tree *root = create_new_node(4);
	insert_node(root,5);
	insert_node(root,6);
	insert_node(root,3);
	insert_node(root,1);

	cout << "node 1 level " << get_level(root, 1, 0) << endl;
	cout << "node 3 level " << get_level(root, 3, 0) << endl;
	cout << "node 4 level " << get_level(root, 4, 0) << endl;
	cout << "node 5 level " << get_level(root, 5, 0) << endl;
	cout << "node 6 level " << get_level(root, 6, 0) << endl;

	cout << "reverse_oder_print" << endl;
	reverse_oder_print(root);
	cout << "forward_oder_print" << endl;
	forward_oder_print(root);

	cout << "post_order_print" << endl;
	post_order_print(root);
	cout << "pre_order_print" << endl;
	pre_order_print(root);

	cout << "forward_oder_print" << endl;
	forward_oder_print(root);
	mirror_tree(root);
	cout << "forward_oder_print" << endl;
	forward_oder_print(root);

	cout << "delete_node" << endl;
	delete_node(root, 1);
	forward_oder_print(root);


	delete_tree(root);



}