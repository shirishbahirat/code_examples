#include <iostream>


int main()
{

    int arr[] = {100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110};

    for (int i = 0, j = 10; i != j; ++i, --j)
    {
    
        std::cout << i << " " << j << std::endl;
        arr[i] ^= arr[j] ^= arr[i] ^= arr[j];
    }

    for (int i = 0; i < 10; ++i)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}
