#include <iostream>
#include "./jsoncpp/json/json.h"


int main()
{

    Json::Value event;   
    Json::Value vec(Json::arrayValue);

    vec.append(Json::Value(100));
    vec.append(Json::Value(200));
    vec.append(Json::Value(300));

    event["wimbledon"]["2018"]["name"] = "Liverpool";
    event["wimbledon"]["2017"]["grass"] = 89223.9099;
    event["wimbledon"]["2016"]["player"] = "Spencer Gore";
    event["wimbledon"]["2015"]["club"] = vec;

    std::cout << event << std::endl;

    return 0;
}
