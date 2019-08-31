//#pragma once
#ifndef BIRD_H
#define BIRD_H
#include "animal.h"

class Bird : public Animal
{
public:
    Bird(const string &n);
    void move();
    ~Bird();
};

#endif
