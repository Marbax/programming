
#include "Figure.h"

Figure::Figure() = default;

Figure::Figure(const string &name) : name(name) {}

Figure::~Figure() {}

const string &Figure::getName() const { return name; }

void Figure::setName(const string &name)
{
    Figure::name = name;
}
