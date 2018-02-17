#include<iostream>
#include <iomanip>
#include <bitset>

using namespace std;
 
unsigned int countSetBits(int n)
{
    unsigned int count = 0;

    while (n)
    {
      cout << bitset<16>(n) << " " << bitset<16>(n-1) << " " << bitset<16>(n&(n-1)) << endl;
      n &= (n-1) ;
      count++;
    }

    return count;
}
 
int main()
{
    int A = 0xFFFF;
    int B = 0x1111;

    int C = A ^ B;    
    cout << C << " " << countSetBits(C) << endl;

    return 0;
}
