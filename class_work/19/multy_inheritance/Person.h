#pragma once
#include <iostream>
#include <string>
using namespace std;
class Person
{
    string name="Masha";
    int age = 19;
public:
    Person();
    Person(const string&, int );

    const string &getName() const;

    void setName(const string &name);

    int getAge() const;

    void setAge(int age);
};