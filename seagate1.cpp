
#include <stdio.h>

void functionA(unsigned char a)
{
	
	char mask = 8;
	char arr[] = {0, 0, 0, 0, 0, 0, 0, 0, 0}; 


	for (int i = 0; i <= 7; ++i)
	{
		if (a & mask)
		{
			arr[i] = '1';		
		}
		else
		{		
			arr[i] = '0';
		}
		mask = mask << 1;
	}

	printf("%s\n", arr);

}


int main()
{
	functionA('7');
	return 0;
}
