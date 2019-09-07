#include "Special.h"

Special::Special(string number) : Automobile(number) {}

Special::Special(string number, string organization) : Automobile(number), organization(organization) {}

Special::~Special()
{
}

string Special::getOrganization()
{
    return organization;
}

void Special::setOrganization(const string organization)
{
    this->organization = organization;
}