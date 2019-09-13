#include "Circle.h"

Circle::Circle(const string &name, float x, float y, float r) : Figure(name), r(r)
{
    this->center.x = x;
    this->center.y = y;
}

float Circle::getX() const { return this->center.x; }

void Circle::setX(float x) { this->center.x = x; }

float Circle::getY() const { return this->center.y; }

void Circle::setY(float y) { this->center.y = y; }

float Circle::getR() const { return this->r; }

void Circle::setR(float r) { this->r = r; }