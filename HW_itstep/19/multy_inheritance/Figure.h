#pragma once
#include <iostream>
#include <string>
using namespace std;
class Figure
{
    string name = "Figure";

public:
    Figure();
    Figure(const string &name);
    virtual ~Figure() = 0;
    const string &getName() const;

    void setName(const string &name);
};