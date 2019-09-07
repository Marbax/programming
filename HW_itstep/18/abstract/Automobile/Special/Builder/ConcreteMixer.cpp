#include "ConcreteMixer.h"

ConcreteMixer::ConcreteMixer(string number) : Builder(number) {}

ConcreteMixer::ConcreteMixer(string number, string organization) : Builder(number, organization) {}

ConcreteMixer::~ConcreteMixer()
{
}

void ConcreteMixer::work() { cout << "Mixer" << endl; }
