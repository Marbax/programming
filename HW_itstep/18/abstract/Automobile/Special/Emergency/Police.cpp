#include "Police.h"

Police::Police(string number) : Emergency(number) {}

Police::Police(string number, string organization) : Emergency(number, organization) {}

Police::~Police()
{
}

void Police::signal() { cout << "piu-piu this is poooolice" << endl; }