#include <iostream>


template<class T>
class stat_item
{

public:
    stat_item():value(0),num_updates(0){std::cout << "new item" << std::endl;}
    ~stat_item(){}

    T value;
    unsigned num_updates;

public:
    virtual stat_item<T>& operator+=(T val) {
        value += val;
        num_updates += 1;
        std::cout << "in " << num_updates << std::endl;
        return *this;
    }

    virtual stat_item<T>& operator-=(T val) {
        value -= val;
        num_updates += 1;
        std::cout << "in " << num_updates << std::endl;
        return *this;
    }


};

class stats_base
{
public:
    stat_item<int> stat_items;



};


int main(int argc, char* argv[])
{

    stat_item<int>* cmds_executed = new stat_item<int>();
    
    stats_base stats_bases;
    
    stats_bases.stat_items += 100;
    std::cout << stats_bases.stat_items.value << std::endl;

    *cmds_executed -= 10;
    std::cout << cmds_executed->value << std::endl;

    *cmds_executed -= 10;
    std::cout << cmds_executed->value << std::endl;

    *cmds_executed -= 10;
    std::cout << cmds_executed->value << std::endl;

    return 0;
}
