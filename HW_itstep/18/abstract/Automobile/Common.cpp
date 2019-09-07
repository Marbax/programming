#include "Common.h"
Common::Common(string number, string color) : Automobile(number), color(color) {}

Common::Common(string color) : color(color) {}

Common::~Common()
{
}

string Common::getColor() const { return color; }

void Common::setColor(const string color) { this->color = color; }