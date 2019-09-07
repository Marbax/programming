#include "Emergency.h"

Emergency::Emergency(string number) : Special(number) {}

Emergency::Emergency(string number, string organization) : Special(number, organization) {}

Emergency::~Emergency()
{
}
