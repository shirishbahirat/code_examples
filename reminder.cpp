#include <iostream>
using namespace std;
#include <utility>
#include <map>


map <string, size_t> animal_population{
   {"human", 10000},
   {"chikan", 20000},
   {"dogs", 23000}
};

template <typename ... Ts>
auto mult(Ts ... ts )
{
	return (ts * ... * 10);
}


pair<int, int> divide_reminder(int a,int b)
{
	pair<int, int> results;

	results.first = a/b;
	results.second = a%b;
    return results;

}

int main(int argv, const char* argc[])
{
	

   auto [frac, remi] = divide_reminder(16,3);
   cout << frac << " " << remi << endl;

   for (const auto &[anm, pop] : animal_population)
   {
   	   cout << anm << " " << pop << endl; 
   }

   cout << mult(2,3) << endl;


	return 0;
}