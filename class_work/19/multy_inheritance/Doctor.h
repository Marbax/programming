#pragma once

#include "Person.h"

class Doctor:virtual public Person
{
    string spec;
public:
    Doctor(const string &n, int a, const string&s);

    const string &getSpec() const;

    void setSpec(const string &spec);
};

