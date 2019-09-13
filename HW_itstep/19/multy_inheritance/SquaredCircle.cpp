
#include "SquaredCircle.h"

SquaredCircle::SquaredCircle(const string &name, float centerX, float centerY, float r, float x1, float y1, float side) : Circle(name, centerX, centerX, r), Square(name, x1, y1, side)
{
}

SquaredCircle::SquaredCircle(const string &name, Point p1, float side) : Square(name, p1, side) //, Circle(name, static_cast<float>(p1.x + side / 2), static_cast<float>(p1.y + side / 2), static_cast<float>(side / 2))
{
    this->setName(name);
    this->setR(static_cast<float>(side / 2));
    this->setX(static_cast<float>(p1.x + side / 2));
    this->setY(static_cast<float>(p1.y + side / 2));

    //Circle(name, static_cast<float>(p1.x + side / 2), static_cast<float>(p1.y + side / 2), static_cast<float>(side / 2));
}
