#include <iostream>


uint32_t data[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

uint32_t binary_search(uint32_t data[], uint32_t max, uint32_t min, uint32_t value)
{
	uint32_t index = -1;

	if (max >= 1)
	{
		uint32_t mid = min + (max - min)/2;

		std::cout << "mid " << mid << std::endl; 

		if (data[mid] == value)
			return mid;

		if (data[mid] > value)
			return binary_search(data, mid-1, min, value);
		else
			return binary_search(data, max, mid+1, value);


	}


	return index;
}


int main(int argc, const char* argv[])
{

	std::cout << binary_search(data, 10, 0, 7) << std::endl;

	return 0;
}