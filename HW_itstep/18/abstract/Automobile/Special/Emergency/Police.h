#pragma once
#include <iostream>
#include <string>
#include "../Emergency.h"

using namespace std;

class Police : public Emergency
{
private:
public:
    Police() = default;
    Police(string number);
    Police(string number, string organization);
    ~Police();
    void signal();
};
