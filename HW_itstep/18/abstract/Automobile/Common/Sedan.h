#pragma once
#include <iostream>
#include <string>
#include "../Common.h"

using namespace std;

class Sedan : public Common
{
private:
public:
    Sedan() = default;
    Sedan(string number);
    Sedan(string number, string color);
    ~Sedan();
};
