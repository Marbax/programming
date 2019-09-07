#pragma once
#include <iostream>
#include <string>
#include "../Builder.h"

using namespace std;

class TruckCrane : public Builder
{
private:
public:
    TruckCrane() = default;
    TruckCrane(string number);
    TruckCrane(string number, string organization);
    ~TruckCrane();
    void work();
};
