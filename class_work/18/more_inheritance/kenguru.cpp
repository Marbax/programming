#include "kenguru.h"

Kenguru::Kenguru(const string &n) : Animal(n)
{
}

void Kenguru::move() { cout << getName() << " is jumping" << endl; }

Kenguru::~Kenguru()
{
    cout << "~Kenguru" << endl;
}
