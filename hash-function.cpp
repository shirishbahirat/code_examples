#include <iostream>

using namespace std;

const uint32_t p1 = 1301081;
const uint32_t p2 = 105619;
const uint32_t p3 = 1117;
const uint32_t p0 = 199;

uint32_t hash_function(string str)
{
   uint32_t hash = p0;
   string::iterator it = str.begin();

   while (*it) {
     hash = (hash * p1) ^ (*it * p2);
     it++;
   }
   return hash;
}


int main(int argc, const char* argv[])
{

	string hstring = "test";

	if (argc > 1)
		hstring = argv[1];

	cout << "hash of " << hstring << " " << hash_function(hstring) << endl;

	return 0;
}



