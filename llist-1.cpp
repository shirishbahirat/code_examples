#include <iostream>

using namespace std;

struct node {
	int data;
	node* next;
};

node* gen_node(int data)
{

	node* new_node = new node();
	new_node->data = data;
	new_node->next = NULL;

	return new_node;
}

void insert_tail(node** instance, int data)
{

	node* new_node = gen_node(data);

	node* current = *instance;

	if (*instance == NULL)
	{
		(*instance) = new_node;
		return;
	}

	while(current->next != NULL)
	{
		current = current->next;
	}

	current->next = new_node;

	return;
}

void insert_head(node** head, int data)
{

	node* new_node = gen_node(data);

	if (*head == NULL)
	{
		(*head) = new_node;
		return;
	}

	new_node->next = (*head);
	(*head) = new_node;

}


void print_nodes(node* head)
{
	node* current = head;

	while(current != NULL)
	{
		cout << current->data << " ";
		current = current->next;
	}

	cout << endl;
}

void insert_at(node** head, int insert_after, int data)
{

	if (*head == NULL) return;

	node* new_node = gen_node(data);

	node* current = *head;

	while(current->data != insert_after)
	{
		current = current->next;
	}

	new_node->next = current->next;
	current->next = new_node;

	return;
}

void delete_node(node** head, int data)
{

	if (*head == NULL) return;

	cout << "deleting" << endl;

	node* current = *head;

	bool data_found = true;

	while(current->next->data != data)
	{
		current = current->next;
		cout << current->data << endl;

		if (current->next->next == NULL)
		{
			data_found = false;
			break;
		}
	}

	if (data_found)
	{
		node* removed = current->next;
		current->next = current->next->next;
		delete removed;
	}

	return;

}

void invert(node** head)
{

	if (*head == NULL)  return;

	node* prev = NULL;
	node* current = NULL;
	node* next = NULL;

	current = *head;
	next = current->next;

	while(current->next != NULL)
	{
		current->next = prev;
		prev = current;
		current = next;
		next = current->next;
	}

	*head = current;
	current->next = prev;

}


int main(int argc, const char* argv[])
{

	node* head = NULL;

	for (int i = 0; i < 10; ++i)
	{
		insert_tail(&head, 100 + (i*10));		
	}

	for (int i = 0; i < 5; ++i)
	{
		insert_head(&head, 90 - (i*10));		
	}

	insert_at(&head, 80, 85);
	insert_at(&head, 180, 185);

	print_nodes(head);

	delete_node(&head, 85);

	print_nodes(head);

	delete_node(&head, 185);

	print_nodes(head);

	invert(&head);

	print_nodes(head);


	return 0;
}