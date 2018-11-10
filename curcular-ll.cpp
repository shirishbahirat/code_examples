#include <iostream>

using namespace std;

struct node {
	uint32_t data;
	node* next;
};


void insert_cursor(node** cursor,uint32_t data)
{
	node* current_node = *cursor;

	current_node->data = data;

	current_node->next = current_node;
}

void insert_node(node** cursor, uint32_t data)
{
	node* current_node = *cursor;

	node* new_node = new node();

	while(current_node->next != *cursor) current_node++;

	new_node->data = data;

	current_node->next = new_node;

	new_node->next = *cursor;

}

void print_node(node* cursor)
{
	node* current_node = cursor;

	do {
		cout << current_node->data << endl;
		current_node = current_node->next;
	} while(current_node != cursor);


}

void insert_node_after(node** cursor, uint32_t data, uint32_t ref)
{
	node* current_node = *cursor;

	node* new_node = new node();
	new_node->data = data;

	while(current_node->data != ref) current_node++;

	new_node->next = current_node->next->next;

	current_node->next = new_node;

}


void delete_node(node** cursor, uint32_t data)
{

	node* current_node = *cursor;

	while(current_node->next->data != data) current_node++;

	node* next_node = current_node->next->next;

	current_node->next->next = NULL;
	current_node->next = NULL;

	delete current_node->next;

	current_node->next = next_node;

}


int main(int argc, char const *argv[])
{
	node* cursor = new node();

	insert_cursor(&cursor, 16);
	insert_node(&cursor, 32);
	insert_node(&cursor, 64);
	insert_node(&cursor, 128);
	insert_node(&cursor, 256);
	insert_node(&cursor, 512);

	insert_node_after(&cursor, 200, 128);

	delete_node(&cursor, 32);

	print_node(cursor);

	
	return 0;
}