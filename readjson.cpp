#include <iostream>
#include <fstream>
#include "./jsoncpp/json/json.h"


int main()
{
    Json::Value root;

    std::ifstream file("readData.json");
    file >> root;
    
    unsigned int w1 = root["smith"]["zipCode"].asUInt();
    
    std::cout << w1 << std::endl;
    
    const Json::Value& scars = root["smith"]["cars"];

    for (int i = 0; i < scars.size(); ++i)
        std::cout << scars[i] << std::endl;


    unsigned int w2 = root["john"]["zipCode"].asUInt();

    std::cout << w2 << std::endl;
    
    const Json::Value& jcars = root["john"]["cars"];

    for (int i = 0; i < jcars.size(); ++i)
        std::cout << jcars[i] << std::endl;


    return 0;
}

