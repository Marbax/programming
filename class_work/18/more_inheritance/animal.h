//#pragma once
#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
#include <string>

using namespace std;

class Animal
{
private:
    string name;

public:
    Animal(const string &n);
    void setName(const string &name);
    const string &getName() const;
    virtual void move() = 0; //чисто виртуальная ф-я
    virtual ~Animal();
};

#endif
