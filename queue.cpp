#include <iostream>
using namespace std;

static const uint32_t size = 10;

static uint32_t queue[size];
static uint32_t head;
static uint32_t tail;
static uint32_t cntr;


void init_queue()
{
   head = tail = cntr = 0;
}

bool is_full()
{
	if (cntr == size) return true;
	else return false;
}

bool is_empty()
{
	if (!cntr) return true;
	else return false; 
}

bool push(uint32_t item)
{
	if (cntr == size) return false;

	queue[tail] = item;
	tail = (tail + 1) % size;
	cntr++;

	return true;
}

void print_items()
{
	uint32_t index = head;

	for(uint32_t i = 0; i < cntr; ++i)
	{
		cout << queue[index] << endl;
		index = (index + 1) % size;
	}

}

bool pop(uint32_t &item)
{
	if (cntr == 0) return false;

	item = queue[head];
	head = (head + 1) % size;
	--cntr;

	return true;
}

int	main(int argc, const char* argv[])
{

	init_queue();

	push(20);
	push(30);
	push(40);
	push(50);

	print_items();

	uint32_t item = 0;
	pop(item);

	cout << "pop " << item << endl;

	print_items();

	return 0;
}