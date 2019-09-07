#include "Pickup.h"

Pickup::Pickup(string number) : Common(number) {}

Pickup::Pickup(string number, string color) : Common(number, color) {}

Pickup::~Pickup()
{
}
