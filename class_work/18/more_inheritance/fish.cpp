#include "fish.h"

Fish::Fish(const string &n) : Animal(n)
{
}

void Fish::move() { cout << getName() << " is swiming" << endl; }

Fish::~Fish()
{
}
