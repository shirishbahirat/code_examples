#include <iostream>

using namespace std;


string reverse_string(string str)
{

	string rstr = str;
	uint32_t len = str.length() - 1;

	for(int i = len, j=0; i >= 0; --i, j++)
	{
        rstr[j] = str[i];
	}

	return rstr;
}




int main(int argc, char const *argv[])
{
	cout << reverse_string("shirish") << endl;

	return 0;
}