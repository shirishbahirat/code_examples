#include <iostream>


uint32_t arr[] = {90, 23, 24, 24, 89, 4, 5};


int main(int argc, const char* argv[])
{
	int i = 0,  j = 0;
	uint32_t temp;	

	for (i = 0; i < 7; ++i)
	{
		int min_idx = i;
		for (j = i; j < 7; ++j)
		{
			if (arr[j] < arr[min_idx])
				min_idx = j;
		}

		temp = arr[i];
		arr[i] = arr[min_idx];
		arr[min_idx] = temp;

	}


	for (int n=0; n < 7; ++n)
		std::cout << arr[n] << " ";
	std::cout << std::endl;


	return 0;
}