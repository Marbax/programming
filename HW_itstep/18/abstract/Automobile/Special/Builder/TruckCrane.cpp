#include "TruckCrane.h"



TruckCrane::TruckCrane(string number) : Builder(number) {}

TruckCrane::TruckCrane(string number, string organization) : Builder(number, organization) {}

TruckCrane::~TruckCrane()
{
}

void TruckCrane::work() { cout << "Truck" << endl; }
