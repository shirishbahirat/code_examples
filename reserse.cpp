#include <iostream>
#include <cstring>
#include <algorithm>
#include <bits/stdc++.h> 

using namespace std;

int revse(int x)
{
    uint32_t int_max = 2147483647;
    uint64_t xabs;

    int multiplier = 1;

    if (x < 0) multiplier = -1;

    xabs = (uint64_t)x*(uint64_t)multiplier;

    uint64_t xrev = static_cast<uint64_t>(xabs);

    stringstream ss;
    ss << xrev;
    string str = ss.str();

    std::reverse(str.begin(), str.end());

    xrev = stol(str);
        
    if (xrev > int_max)
        return 0;       

    x = static_cast<int>(xrev);

    return x*multiplier;
}



int main()
{
    
    cout << revse(-2147483647) << endl;

    return 0;
}
    