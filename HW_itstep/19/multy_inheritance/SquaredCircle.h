#pragma once

#include "Circle.h"
#include "Square.h"
#include "Point.h"

class SquaredCircle : public Circle, public Square
{
public:
    SquaredCircle(const string &name, float centerX, float centerY, float r, float x1, float y1, float side);
    SquaredCircle(const string &name, Point p1, float side);
};
