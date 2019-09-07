#include "FireEngine.h"


FireEngine::FireEngine(string number) : Emergency(number) {}

FireEngine::FireEngine(string number, string organization) : Emergency(number, organization) {}

FireEngine::~FireEngine()
{
}

void FireEngine::signal() { cout << "vou-vou fireengine" << endl; }