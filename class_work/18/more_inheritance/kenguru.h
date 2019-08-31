#pragma once
#include "animal.h"

class Kenguru : public Animal
{
public:
    Kenguru(const string &n);
    void move();
    ~Kenguru();
};
