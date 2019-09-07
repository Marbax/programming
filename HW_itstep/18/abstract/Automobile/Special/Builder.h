#pragma once
#include <iostream>
#include <string>
#include "../Special.h"

using namespace std;

class Builder : public Special
{
private:
public:
    Builder() = default;
    Builder(string number);
    Builder(string number, string organization);
    ~Builder();
    virtual void work() = 0;
};
