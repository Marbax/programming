//#pragma once
#ifndef PENGUIN_H
#define PENGUIN_H
#include "bird.h"

class Penguin : public Bird
{
public:
    Penguin(const string &n);
    void move()override;
    ~Penguin()override;
};

#endif
