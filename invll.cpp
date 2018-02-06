#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

typedef unsigned int uint32_t;

struct node {
    void* data;
    node* next;
};

ostream & operator << (ostream &out, const node *head)
{
    out << "data " << *(int*)head->data;
    return out;
}

class linkedList
{

public:
    linkedList():number_of_nodes(0){};
    ~linkedList(){};

    void add1stNode(node *head, void* data, size_t siz)
    {
        head->data = malloc(siz);
        memcpy(head->data, data, siz);
        head->next = NULL;
        cout << "input " << *(int*) data << " node " << head << " size " << (int)siz << endl;
    }

    void addNodeFront(node** head, void* data, size_t siz)
    {
        node* new_node = new node();        
        new_node->data = malloc(siz);
        memcpy(new_node->data, data, siz);
        new_node->next = *head;
        cout << "input " << *(int*) data << " node " << new_node << " size " << (int)siz << endl;

        *head = new_node;
        ++number_of_nodes;
    }

    void printNodes(node *head)
    {
    	node *list = head;
	    while(list) {
		    cout << list << " " << endl;
		    list = list->next;
	    }
    }

    void deleteAllNodes(node **head)
    {
    	node *tmpNode = *head;
    	while(tmpNode) {
            cout << *head << endl;
            delete *head;
    	    *head = tmpNode->next;
            tmpNode = *head;}
    }

    void inverseNodes(node** head) 
    {
    	node *current = *head;
	    node *next = current->next;
	    node *previous = NULL;

	    while(next) {
	        //current->next = previous;
	        //previous = current;
	        current = current->next;
	        next = current;
	    }
	    //*head = next;

	}

private:
    uint32_t number_of_nodes;


};


int main(void)
{

    node* head = new node();
    uint32_t data;
 
    linkedList* llist = new linkedList();
    cout << "add node 1" << endl;
    data = 1000;
    llist->add1stNode(head, (void*)&data, sizeof(data));

    cout << "add node 2" << endl;
    data = 1001;
    llist->addNodeFront(&head, (void*)&data, sizeof(data));

    cout << "add node 3" << endl;
    data = 1003;
    llist->addNodeFront(&head, (void*)&data, sizeof(data));

    cout << "add node 4" << endl;
    data = 1004;
    llist->addNodeFront(&head, (void*)&data, sizeof(data));

    cout << "add node 5" << endl;
    data = 1005;
    llist->addNodeFront(&head, (void*)&data, sizeof(data));

    cout << "print nodes" << endl;
    llist->printNodes(head);

    cout << "inverse nodes" << endl;
    llist->inverseNodes(&head);

    cout << "print inversed nodes" << endl;
    llist->printNodes(head);

    cout << "delete all nodes" << endl;
    llist->deleteAllNodes(&head);

    cout << "print nodes" << endl;
    llist->printNodes(head);
   return (0);
}
