#include <iostream>

using namespace std;

uint32_t fibonacci(uint32_t index)
{

	if (index == 1) return 1;
	if (index <= 0) return 0;

	return fibonacci(index-1) + fibonacci(index-2);

}

int main(int argc, char const *argv[])
{
	
	for (uint32_t i = 0; i < 20; ++i)
        cout << fibonacci(i) << endl;

	return 0;
}