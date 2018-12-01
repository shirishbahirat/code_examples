#include <iostream>
#include <iterator>
using namespace std;

bool reached_limit(uint32_t index1, uint32_t index2, uint32_t index3,
	               uint32_t lenght1, uint32_t lenght2, uint32_t lenght3)
{

	cout << index1 << " " << index2 << " " << index3 << endl;
     return (index1 < lenght1) && (index2 < lenght2) && (index3 < lenght3);
}


int main(int argc, char const *argv[])
{
	uint32_t arr1[] = {2, 4, 6, 7, 8, 9, 11, 12};
	uint32_t arr2[] = {3, 4, 5, 6, 8, 9, 13, 14};
	uint32_t arr3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	uint32_t index1 = 0, index2 = 0, index3 = 0;

	uint32_t lenght1 = sizeof(arr1)/sizeof(uint32_t);
	uint32_t lenght2 = sizeof(arr2)/sizeof(uint32_t);
	uint32_t lenght3 = sizeof(arr3)/sizeof(uint32_t);

	uint32_t count = 0;

	while(reached_limit(index1, index2, index3, lenght1, lenght2, lenght3))
	{
		if ((arr1[index1]==arr2[index2]) && (arr2[index2] == arr3[index3])) 
		{
			count++; 
			index1++;
			index2++;
			index3++;
		}
		else if (arr2[index2] > arr1[index1])
		{
		    index1++;
		}
		else if (arr3[index3] > arr2[index2])
		{
		    index2++;
		}
		else
		{
			index3++;
		}
        

	}

    std::cout << count << std::endl;

	return 0;
};