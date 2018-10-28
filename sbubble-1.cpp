#include <iostream>


uint32_t arr[] = {90, 23, 24, 34, 89, 4, 5};


void swap(uint32_t *xp, uint32_t *yp) 
{ 
    uint32_t temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 


int main(int argc, const char* argv[])
{

	int i = 0, j = 0;

	for (i = 0; i < 7; ++i)
	{

       for (j = 0; j < 7-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swap(&arr[j], &arr[j+1]); 

	}

	for (int n=0; n < 7; ++n)
		std::cout << arr[n] << " ";
	std::cout << std::endl;

	return 0;
}