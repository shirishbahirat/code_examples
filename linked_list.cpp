#include <iostream>


struct node {
    void* data;
    node* next;
};


struct list {
    node* head;
    node* tail;
    int count;
};

void init_linked_list(list* lst)
{
    lst->head = NULL;
    lst->tail = NULL;
    lst->count = 0;
}


struct payload {
    int val;
};


void delete_node_head(list* lst)
{
    
    node* front = lst->head;
    
    lst->head = lst->head->next;
    delete front;

}

void delete_node_tail(list* lst)
{

    node* head = lst->head;

    while(lst->head->next->next)
    {
        lst->head = lst->head->next;
    }

    lst->tail = lst->head;
    delete lst->head->next;
    lst->head->next = NULL;
    lst->head = head;

}


void add_node_head(node** new_node, list* lst)
{

    if (lst->head == NULL)
    {
        lst->head = (*new_node);
        lst->tail = (*new_node);
        lst->head->next = NULL;
        lst->count++;     
    }
    else
    {    
        (*new_node)->next = lst->head;
        lst->head = (*new_node);
    }
}


void add_node_tail(node** new_node, list* lst)
{

    if (lst->head == NULL)
    {
        lst->head = (*new_node);
        lst->tail = (*new_node);
        lst->head->next = NULL;
        lst->count++;     
    }
    else
    {
        lst->tail->next = (*new_node);
        lst->tail = (*new_node);
        lst->tail->next = NULL;  
    }

}

void delete_at_position(list* lst, int pos)
{

    if (lst->head == NULL)
        return;

    node* head = lst->head;
    node* current = lst->head;

    while(pos--)
    {
        current = lst->head;
        lst->head = lst->head->next;
    }

    delete current->next;
    current->next = lst->head->next;

    lst->head = head;
}

void insert_at_position(node** new_node, list* lst, int pos)
{

    if (lst->head == NULL)
        return;

    node* head = lst->head;
    node* current = lst->head;

    while(pos--)
    {
        current = lst->head;
        lst->head = lst->head->next;
    }

    current->next = (*new_node);
    current->next->next = lst->head;

    lst->head = head;

}

node* create_node(int val)
{

    node* n = new node();
    payload* p = new payload();
    p->val = val;
    n->data = static_cast<void*>(p);

}

void print_node(list* lst)
{

    node* head = lst->head;

    while(lst->head)
    {
        payload* pld = static_cast<payload*>(lst->head->data);
        std::cout << pld->val << " ";
        lst->head = lst->head->next;
    }

    std::cout << std::endl;
    
    lst->head = head;
}

void inverse_linked_list(list* lst)
{

   node* previous = NULL;
   node* current = lst->head;
   node* next = lst->head->next;
   
   while(current)
   {
       next = current->next;
       current->next = previous;
       previous = current;
       current = next;
   }
   lst->head = previous;

}


int main(int argc, const char* argv[])
{

    list* sll = new list();
    init_linked_list(sll);
    
    for (int i = 0; i < 10; ++i)
    {
        node* n0 = create_node(10*i);
        add_node_tail(&n0, sll);    
    }

    for (int i = 0; i < 10; ++i)
    {
        node* n0 = create_node(100*i);
        add_node_head(&n0, sll);    
    }

    print_node(sll);

    node* n0 = create_node(555);
    insert_at_position(&n0, sll, 4);

    print_node(sll);

    delete_node_head(sll);

    print_node(sll);
    
    delete_node_tail(sll);

    print_node(sll);
    
    delete_at_position(sll, 3);

    print_node(sll);
    
    inverse_linked_list(sll);

    print_node(sll);

    return 0;
}

