#pragma once
#include <iostream>
#include <string>
#include "../Emergency.h"

using namespace std;

class Ambulance: public Emergency
{
private:
public:
    Ambulance() = default;
    Ambulance(string number);
    Ambulance(string number, string organization);
    ~Ambulance();
    void signal();
};
