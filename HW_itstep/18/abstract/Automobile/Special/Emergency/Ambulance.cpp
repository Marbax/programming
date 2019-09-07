#include "Ambulance.h"

Ambulance::Ambulance(string number) : Emergency(number) {}

Ambulance::Ambulance(string number, string organization) : Emergency(number, organization) {}

Ambulance::~Ambulance()
{
}

void Ambulance::signal() { cout << "viu-viu ambulance" << endl; }
