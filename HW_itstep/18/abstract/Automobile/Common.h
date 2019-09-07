#pragma once

#include <iostream>
#include <string>
#include "../Automobile.h"

using namespace std;

class Common : public Automobile
{
private:
    string color = "";

public:
    Common() = default;
    Common(string number);
    Common(string number, string color);
    virtual ~Common() = 0;

    virtual string getColor() const;

    virtual void setColor(const string color);
};
