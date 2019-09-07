#pragma once
#include <iostream>
#include <string>
#include "../Automobile.h"

using namespace std;

class Special : public Automobile
{
private:
    string organization = "";

public:
    Special() = default;
    Special(string number);
    Special(string number, string organization);
    virtual ~Special() = 0;

    virtual string getOrganization();

    virtual void setOrganization(const string organization);
};
