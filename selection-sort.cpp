#include <iostream>

using namespace std;


int main(int argc, const char* argv[])
{
	uint32_t arr[] = {60, 20, 90, 70, 50, 100, 40, 80, 30, 10};
	uint32_t len = sizeof(arr)/sizeof(uint32_t);

	for (int i = 0; i < len; ++i)
	{
		uint32_t min_number = 0xFFFFFFFF;
		uint32_t min_index = 0xFFFFFFFF;

		for (int j = i; j < len; ++j)
		{
			if (arr[j] < min_number)
			{
				min_number = arr[j];
				min_index = j;
			}

		}
		cout << arr[min_index] << endl;
		uint32_t temp = arr[i];
		arr[i] = arr[min_index];
		arr[min_index] = temp;
	}

	for (int i = 0; i < len; ++i)
	{
		cout << arr[i] << " " << flush;
	}

	cout << endl;

	return 0;
}