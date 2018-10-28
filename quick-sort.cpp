#include <iostream>

using namespace std;


void swap(uint32_t* idx1, uint32_t* idx2) 
{ 

    uint32_t temp = *idx1; 
    *idx1 = *idx2; 
    *idx2 = temp;
}


void print_array(uint32_t *arr, uint32_t len)
{
	for (int i = 0; i < len; ++i)
	{
		cout << *arr << " " << flush;
		arr++;
	}
	cout << endl;
}

uint32_t quick_sort(uint32_t arr[], uint32_t low, uint32_t high)
{

	uint32_t pivot_current = arr[high];
	int i = low;

	if (low < high)
	{
		for (int k = low; k < high; ++k)
		{
			if (arr[k] < pivot_current)
			{
				cout << k << ": " << flush;
				swap(&arr[i], &arr[k]);
			    ++i;
				print_array(arr, 10);
			}

		}
		swap(&arr[i], &arr[high]);

	}

	return i;

}

int main(int argc, const char* argv[])
{
	uint32_t arr[] = {60, 20, 90, 70, 50, 100, 10, 80, 30, 40};
	uint32_t len = sizeof(arr)/sizeof(uint32_t);
	uint32_t next_pivot = len;

	print_array(arr, len);

	while(next_pivot)
	{
		next_pivot = quick_sort(arr, 0, next_pivot-1);
		quick_sort(arr, next_pivot,len-1);
	}

	print_array(arr, len);

	return 0;

}