#include "animal.h"

Animal::Animal(const string &n)
{
    name = n;
}

void Animal::setName(const string &name)
{
    this->name = name;
}

const string &Animal::getName() const
{
    return name;
}

/* void Animal::move()
{
    cout << getName() << " is moving" << endl;
} */
Animal::~Animal()
{
    cout << "~Animal" << endl;
}
