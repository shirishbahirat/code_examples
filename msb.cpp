#include <iostream>
#include <iomanip>
#include <bitset>

using namespace std;

int main()
{

    int position;
    int number = 1000;

    asm ("bsrl %1, %0" 
     : "=r" (position) 
     : "r" (number));   

     cout << bitset<32>(number) << " " << position << endl;

    return 0;
}
