#include <iostream>



uint32_t arr[] = {1, 3, 5, 6, 7, 9, 10};


uint32_t lsearc_for(uint32_t *parr)
{

	int i = 0;

	for (i = 0; i < 7; ++i)
	{

		if (*parr == 9)
			break;

		parr++;

	}

	return i;

}

uint32_t lsearc_while(uint32_t *parr)
{
	uint32_t idx = 0;
	uint32_t value = 1;

	while(value)
	{
		if (*parr == 9)
			value = 0;
		else
			++idx;
		parr++;

	}

	return idx;
}

uint32_t search(uint32_t arr[])
{
	for(int i = 0; i<7; ++i)
	{
		if (arr[i] == 9)
			return i;

	}

	return -1;

}


int main(int argc, const char* argv[])
{

	std::cout << "index " << lsearc_for(&arr[0]) << std::endl;
	std::cout << "index " << lsearc_while(&arr[0]) << std::endl;
	std::cout << "index " << search(arr) << std::endl;

	return 0;
}
