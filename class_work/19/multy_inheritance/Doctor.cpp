#include "Doctor.h"

Doctor::Doctor(const string &n, int a, const string &s):Person(n,a)
{
    spec = s;
}

const string &Doctor::getSpec() const
{
    return spec;
}

void Doctor::setSpec(const string &spec)
{
    Doctor::spec = spec;
}
