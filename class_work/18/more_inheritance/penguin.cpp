#include "penguin.h"

Penguin::Penguin(const string &n) : Bird(n)
{
}

void Penguin::move() { cout << getName() << " is walking and swimming(a little)" << endl; }

Penguin::~Penguin()
{
    cout << "~Penguin" << endl;
}
