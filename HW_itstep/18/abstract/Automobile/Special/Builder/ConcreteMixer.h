#pragma once
#include <iostream>
#include <string>
#include "../Builder.h"

using namespace std;

class ConcreteMixer : public Builder
{
private:
public:
    ConcreteMixer() = default;
    ConcreteMixer(string number);
    ConcreteMixer(string number, string organization);
    ~ConcreteMixer();
    void work();
};
