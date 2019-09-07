#pragma once
#include <iostream>
#include <string>

using namespace std;

class Automobile
{
private:
    string number = "";

public:
    Automobile() = default;
    Automobile(const string number);
    virtual ~Automobile() = 0;
    virtual string getNumber()const;
    virtual void setNumber(string number);
};
