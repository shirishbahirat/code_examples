#include <iostream>

using namespace std;

struct data{
    int value;
    data* left;
    data* right;
};



void addHead(data** head, int value)
{
    data* current_node = *head;
    
    if ((current_node->left == NULL) && (current_node->right == NULL))
        current_node->value = value;

}

void addNode(data* current_head, data** new_head, int value)
{

    data* current_node = *new_head;
    
    current_node->left = current_head;
    current_node->right = NULL;
    current_head->right = current_node;

    current_node->value = value;

}

void printNodes(data* current_head)
{
    data* temp;

    cout << "left traversal" << endl;
    while(current_head != NULL)
    {
        cout << current_head->value << endl;
        temp = current_head;
        current_head = current_head->left;
    }

    current_head = temp;
    cout << "right traversal" << endl;

    while(current_head != NULL)
    {
        cout << current_head->value << endl;
        temp = current_head;
        current_head = current_head->right;
    }

}


int main(int argc, char* argv[])
{

    data* node1 = new data();
    int value = 10;
    addHead(&node1, value);
    cout << node1->value << endl;
 
     
    data* node2 = new data();
    value = 20;   
    addNode(node1, &node2, value);
    cout << node2->value << endl;
 
    data* node3 = new data();
    value = 30;   
    addNode(node2, &node3, value);
    cout << node3->value << endl;
 
    data* node4 = new data();
    value = 40;   
    addNode(node3, &node4, value);
    cout << node4->value << endl;

    cout << "print" << endl;
    printNodes(node4);

    return 0;
}
