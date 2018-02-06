#include <iostream>
#include <queue>

using namespace std;

template<typename T>
class my_queue
{
public:
    my_queue():q_not_empty(NULL),
               q_not_full(NULL),
               q_entry_pending(NULL) {}

    ~my_queue(){}

    void enqueue(T item) {
        my_q.push(item);
        if (q_not_empty) {
            if (my_q.size() == 1) {
                q_not_empty();
            }
        }
    }

    T dequeue() {
        my_q.pop();
        if (q_entry_pending) {
            if (my_q.size() > 0) {
                q_entry_pending();
            }
        }    
    }
    T peek() {return my_q.front();}

    void (*q_not_empty)();
    void (*q_not_full)();
    void (*q_entry_pending)();

private:
    queue<T> my_q;

};


struct data {
    int value;
    int count;
};


void callback_func_not_empty()
{
    cout << "callback_func_not_empty" << endl;
}

void callback_func_entry_pending()
{
    cout << "callback_func_entry_pending" << endl;
}


int main(int argc, char* argv[])
{
    my_queue<data*> qdt;
    
    qdt.q_not_empty = callback_func_not_empty;
    qdt.q_entry_pending = callback_func_entry_pending;

    data* my_data1 = new data;
    my_data1->value = 100;
    my_data1->count = 1;

    qdt.enqueue(my_data1);

    data* my_data2 = new data;
    my_data2->value = 200;
    my_data2->count = 2;

    qdt.enqueue(my_data2);

    data* my_data3 = new data;
    my_data3->value = 300;
    my_data3->count = 3;

    qdt.enqueue(my_data3);

    qdt.dequeue();
    qdt.dequeue();
    qdt.dequeue();

    return 0;
}
