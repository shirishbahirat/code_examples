#include <iostream>
#include <cstring>
#include <algorithm>
#include <bits/stdc++.h> 

using namespace std;



bool is_palindrome(int x)
{
    uint32_t int_max = INT_MAX;
    uint64_t xabs;
    int x_rev;

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

    x_rev = static_cast<int>(xrev);

    x_rev *=multiplier; 

    if  (x_rev == x) return true;

    return false;
}



int main()
{
    
    cout << reverse(214748364) << endl;

    return 0;
}
    