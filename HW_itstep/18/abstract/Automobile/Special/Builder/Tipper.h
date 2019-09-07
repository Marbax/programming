#pragma once
#include <iostream>
#include <string>
#include "../Builder.h"

using namespace std;

class Tipper : public Builder
{
private:
public:
    Tipper() = default;
    Tipper(string number);
    Tipper(string number, string organization);
    ~Tipper();
    void work();
};
