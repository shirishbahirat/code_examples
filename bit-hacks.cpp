#include <iostream>


/* ref: https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-172-performance-engineering-of-software-systems-fall-2010/video-lectures/lecture-2-bit-hacks/MIT6_172F10_lec02.pdf
*/


void swap(int &x, int &y)
{
    x^=y^=x^=y;
}

int min(int &x, int &y)
{
    return y ^ ((x^y) & -(x < y));
}

int mod_add(int &x, int &y, int n)
{
    int z = x + y;
    return (z - (n & -(z >= n)));
}

int lsb(int &x)
{
    return x & (-x);
}

int msb(int &x)
{
    return x & ~(-x);
}

int bit_cnt(int x)
{
    int count = 0;
    
    while(x)
    {
        ++count;
        x &= (x-1); 
    }
    return count;
}

int swap_nibble(int &x)
{
    return (((x&(0b10101010))>>1)|((x&(0b01010101))<<1));
}


int main(int argc, const char* argv[])
{
    int x = 10, y = 20;
    swap(x,y);
    std::cout << x << " " << y << std::endl;

    std::cout << min(x, y) << std::endl;

    std::cout << mod_add(x, y, 5) << std::endl;

    std::cout << lsb(x) << std::endl;

    std::cout << msb(y) << std::endl;

    std::cout << x << " " << bit_cnt(x) << std::endl;

    std::cout << x << " " << swap_nibble(x) << std::endl;

    return 0;
}
