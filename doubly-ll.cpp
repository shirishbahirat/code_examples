#include<iostream>
using namespace std;

struct node {
	uint32_t data;
	node* next;
	node* prev;
};


void print_node_forward(node* head)
{
	node* current_node = head;

	while(current_node)
	{
		cout << current_node->data << endl;
		current_node = current_node->next;
	}

}

void print_node_backword(node* head)
{
	node* current_node = head;

	while(current_node->next)
	{
		current_node = current_node->next;
	}


	while(current_node)
	{
		cout << current_node->data << endl;
		current_node = current_node->prev;
	}

}


void add_node(node** head, uint32_t data)
{
	node* current_node = *head;
	node* new_node = new node();
	new_node->data = data;

	while(current_node->next)
	{
		current_node = current_node->next;
	}

	current_node->next = new_node;
	new_node->next = NULL;
	new_node->prev = current_node;
}

void delete_node(node** head, uint32_t data)
{
	node* current_node = *head;
	node* prev_node = NULL;
	node* next_node = NULL;

	while(current_node->data != data)
	{
		current_node = current_node->next;
	}

	if (current_node->prev)	prev_node = current_node->prev;
	if (current_node->next) next_node = current_node->next;

	if (prev_node)
		prev_node->next = next_node;

	if (next_node)
		next_node->prev = prev_node;

	delete current_node;

}


int main(int argc, char const *argv[])
{
	cout << "add head" << endl;
	node* head = new node();
	head->next = NULL;
	head->prev = NULL;
	head->data = 11;

	cout << "add nodes" << endl;

	add_node(&head, 2);
	add_node(&head, 8);
	add_node(&head, 16);
	add_node(&head, 32);
	add_node(&head, 64);

	cout << "forward path" << endl;
	print_node_forward(head);
	cout << "backword path" << endl;
	print_node_backword(head);

	cout << "deleting node" << endl;
	delete_node(&head, 16);
	print_node_forward(head);

	cout << "deleting node" << endl;
	delete_node(&head, 64);
	print_node_forward(head);


	return 0;
}