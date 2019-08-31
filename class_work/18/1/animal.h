#pragma once
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
    void move();
    ~Animal();
};

