#include <iostream>

using namespace std;


int main(int argc, const char* argv[])
{
	uint32_t arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

	uint32_t high = sizeof(arr)/sizeof(uint32_t) - 1;
	uint32_t low = 0;
	uint32_t indx = 60;

	uint32_t test;

	if (argc > 1) indx = atoi(argv[1]);

	while(low <= high)
	{
		uint32_t mid = (low + high) >> 1;

		test = arr[mid];

		if (test == indx)
		{
			break;
		}
		else if (test > indx)
		{
			high = mid - 1;
		}
		else if (test < indx)
		{
			low = mid + 1;
		}

	}

	if (test != indx)
	{
		cout << "not found" << endl;
	}
	else
	{
		cout << test << endl;
	}

	return 0;
	

}