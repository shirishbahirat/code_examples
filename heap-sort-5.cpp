#include <iostream>
using namespace std;

void print_array(uint32_t arr[], uint32_t length)
{

	for (uint32_t i = 0; i < length; ++i)
	{
		cout << arr[i] << " " << flush;
	}
	cout << endl;
}

void swap(uint32_t arr[], uint32_t l, uint32_t h)
{
	if (l != h)
	{
		arr[l] ^= arr[h] ^= arr[l] ^= arr[h];
	}
}

void max_heap(uint32_t arr[], uint32_t length, uint32_t index)
{
	uint32_t parent = index;
	uint32_t left = index*2 + 1;
	uint32_t right = index*2 + 2;

	if ((left < length) && (arr[left] > arr[parent])) parent = left;
	if ((right < length) && (arr[right] > arr[parent])) parent = right;

	if (parent != index)
	{
		swap(arr, parent, index);
		max_heap(arr, length, parent);
	}

}


void heap_sort(uint32_t argc[], uint32_t length)
{
	for (int i = length/2-1; i>=0; --i)
	{
		max_heap(arr, length,(uint32_t)i);
	}

	for (int i = length -1; i >=0; (uint32_t)i)
	{
		swap(arr, 0, (uint32_t)i);
		max_heap(arr, uint32_t(i), 0);
	}

}



int main(int argc, const char* argv[])
{
	uint32_t arr[] = {10,2,4,12,25,41};
	uint32_t length = sizeof(arr)/sizeof(uint32_t);

	heap_sort(arr, length);

    print_array(arr, length);


	return 0;
}
