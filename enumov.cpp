#include <iostream>



enum car
{
    van,
    suv,
    mpv = 10,
    pku
};


std::ostream& operator<<(std::ostream& os, car c)
{
    switch(c)
    {
        case van   : os << "mini van";    break;
        case suv   : os << "sport utility vehicle"; break;
        case mpv   : os << "multi utility vehicle";  break;
        case pku   : os << "pick up";   break;
        default    : os.setstate(std::ios_base::failbit);
    }
    return os;
}


int main()
{
    car model = van;
    std::cout << "car = " << model << std::endl;

    model = suv;
    std::cout << "car = " << model << std::endl;

    model = mpv;
    std::cout << "car = " << model << std::endl;

    model = pku;
    std::cout << "car = " << model << std::endl;

    return 0;
}
