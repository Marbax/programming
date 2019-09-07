#pragma once
#include <iostream>
#include <string>
#include "../Emergency.h"

using namespace std;

class FireEngine : public Emergency
{
private:
public:
    FireEngine() = default;
    FireEngine(string number);
    FireEngine(string number, string organization);
    ~FireEngine();
    void signal();
};
