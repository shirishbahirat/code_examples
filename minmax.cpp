#include <iostream>


#define max(a,b) \
  ({ typeof (a) _a = (a); \
      typeof (b) _b = (b); \
    _a > _b ? _a : _b; })

#define min(a,b) \
  ({ typeof (a) _a = (a); \
      typeof (b) _b = (b); \
    _a < _b ? _a : _b; })

int main()
{

    std::cout << max(10,11) << std::endl;
    std::cout << min(10,11) << std::endl;

    return 0;
}
