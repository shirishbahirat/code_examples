#include <iostream>


int main(int argc, const char* argv[])
{

	int arr[] = {0,1,2,3,4,5,6,7,8,9};

	for (int i = 0, j = 9; i < j; ++i, --j)
	{
		std::cout << arr[i] << " " << arr[j] << std::endl;
	}


	return 0;
}
