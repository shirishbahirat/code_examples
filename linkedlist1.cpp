#include <iostream>


struct node {
    void* data;
    node* next;
};


void addnodeFront(node **head, void* payload, size_t size)
{
	node* new_node = new node();

	new_node->data = payload;
	new_node->next = (*head);

	(*head) = new_node;

	std::cout << *(int*) new_node->data << std::endl;

}

void addnodeBack(node **head, void* payload, size_t size)
{
	node* new_node = new node();
	node* last_head;

    while ((*head) != NULL)
    {

		std::cout << "add back " << *(int*) (*head)->data << std::endl;
		(*head) = (*head)->next;
		last_head = (*head);

    }

    new_node->data = payload;
    new_node->next = last_head;
    last_head->next->next = new_node;

}


void loopList(node* head)
{

    while (head != NULL)
    {

		std::cout << *(int*) head->data << std::endl;
		head = head->next;

    }

}



int main()
{
    node* head = NULL;
    unsigned payload_a = 1000;
    unsigned payload_b = 2000;
    unsigned payload_x = 1001;

    addnodeFront(&head, &payload_a, sizeof(payload_a));
    addnodeFront(&head, &payload_b, sizeof(payload_b));
    addnodeBack(&head, &payload_x, sizeof(payload_x));

    loopList(head);
    loopList(head);
}

