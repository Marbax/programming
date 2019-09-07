#include "Builder.h"

Builder::Builder(string number) : Special(number) {}

Builder::Builder(string number, string organization) : Special(number, organization) {}

Builder::~Builder()
{
}
