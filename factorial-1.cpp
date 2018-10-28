#include <iostream>
#include <vector> 

using namespace std;

vector <uint32_t> dpfacto_b;
vector <uint32_t> dpfacto_t;



uint32_t top_down(uint32_t idx)
{
	uint32_t last;

	for (uint32_t i = 1; i < idx; ++i)
	{
		last = dpfacto_t.at(i-1) * (i+1);
	    dpfacto_t.push_back(last);		
	}



	return last;
}


int main(int argc, const char* argev[])
{

    dpfacto_b.push_back(1);
    dpfacto_t.push_back(1);

    cout << top_down(8) << endl;


	return 0;
}
