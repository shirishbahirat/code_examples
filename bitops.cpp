// https://graphics.stanford.edu/~seander/bithacks.html

#include <iostream>
#include <cstdlib>

int get_sign(int value, const int method = 0)
{
    int sign;
    switch(method)
    {
        case 0:
            sign = -(value < 0);
            break;
         case 1:
            sign = -(int)((unsigned int)((int)value) >> (sizeof(int) * sizeof(char) - 1));
            break;
         case 2:
            sign = value >> (sizeof(int) * sizeof(char) - 1);
            break;
         case 3:
            sign = +1 | (value >> (sizeof(int) * sizeof(char) - 1));
            break;
         case 4:
            sign = (value != 0) | -(int)((unsigned int)((int)value) >> (sizeof(int) * sizeof(char) - 1));
            break;
         case 5:
            sign = (value != 0) | (value >> (sizeof(int) * sizeof(char) - 1));
            break;
        case 6:
            sign = (value > 0) - (value < 0);
            break;
        case 7:      
            sign = 1 ^ ((unsigned int)value >> (sizeof(int) * sizeof(char) - 1));
            break;
        default:
            sign = false;
            break;
    }
    return sign;  

}



int main(int argc, const char* argv[])
{

    std::cout << get_sign(std::atoi(argv[1]), std::atoi(argv[2]))  << std::endl;

    return 0;
}
