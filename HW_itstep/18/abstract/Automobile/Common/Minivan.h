#pragma once
#include <iostream>
#include <string>
#include "../Common.h"

using namespace std;

class Minivan:public Common
{
private:
public:
    Minivan() = default;
    Minivan(string number);
    Minivan(string number, string color);
    ~Minivan();
};
