#pragma once
#include <iostream>
#include <string>
#include "../Special.h"

using namespace std;

class Emergency : public Special
{
private:
public:
    Emergency() = default;
    Emergency(string number);
    Emergency(string number, string organization);
    ~Emergency();
    virtual void signal() = 0;
};
