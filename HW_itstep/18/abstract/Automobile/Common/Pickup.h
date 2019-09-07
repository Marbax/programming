#pragma once
#include <iostream>
#include <string>
#include "../Common.h"

using namespace std;

class Pickup : public Common
{
private:
public:
    Pickup() = default;
    Pickup(string number);
    Pickup(string number, string color);
    ~Pickup();
};
