#include <iostream>
#include <vector>
#include <algorithm>


void for_each(const std::vector<int>& values, void(*func)(int))
{
    for (int value:values)
    {
        func(value);
    }

}


int main(int argc, char* argv[])
{
    std::vector<int> values = {1,3,5,4,9,6,7};
    
    auto lambda = [](int value){std::cout << "value: " << value << std::endl; };

    for_each(values, lambda);

    return 0;
}

