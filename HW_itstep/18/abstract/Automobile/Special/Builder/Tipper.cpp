#include "Tipper.h"

Tipper::Tipper(string number) : Builder(number) {}

Tipper::Tipper(string number, string organization) : Builder(number, organization) {}


Tipper::~Tipper()
{
}

void Tipper::work() { cout << "Tripper" << endl; }
