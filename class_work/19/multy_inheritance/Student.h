#pragma once

#include "Person.h"
class Student:virtual public Person
{
    int id;
public:
    Student(const string &n, int a, int id);

    int getId() const;

    void setId(int id);
};
