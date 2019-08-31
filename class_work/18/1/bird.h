#pragma once;
#include "animal.h"

class Bird : public Animal
{
public:
    Bird(const string &n);
    void move();
    ~Bird();
};
