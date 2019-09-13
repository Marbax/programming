#pragma once

#include "Figure.h"
#include "Point.h"

class Circle : virtual public Figure
{
    Point center;
    float r = 0;

public:
    Circle() = default;
    Circle(const string &name, float x, float y, float r);
    Circle(const string &name, Point center, float r);

    float getX() const;

    void setX(float x);

    float getY() const;

    void setY(float y);

    float getR() const;

    void setR(float r);
};
