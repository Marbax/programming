#pragma once
#include "animal.h"

class Fish : public Animal
{
public:
    Fish(const string &n);
    void move()override;
    ~Fish()override;
};
