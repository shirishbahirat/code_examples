#include <iostream>

using namespace std;

struct node {
	int data;
	struct node* next;
};

int length(struct node* node)
{
	int count = 0;
	
	if (node == NULL) return 0;

	struct node* current = node;

	while(current != NULL)
	{
		current = current->next;
		count++;
	}

	return count;
}


void push(struct node** headRef, int data)
{
	struct node* newNode = new (struct node);

	newNode->data = data;

	newNode->next = (*headRef);

	(*headRef) = newNode;

}

int main(int argc, const char* argv[])
{

	struct node* head = NULL;

	push(&head, 6);
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);

	cout << length(head) << endl;

    return 0;
}
