#include "Automobile.h"

Automobile::Automobile(const string number) : number(number)
{
}

Automobile::~Automobile()
{
}

string Automobile::getNumber() const { return number; }

void Automobile::setNumber(string number) { this->number = number; }