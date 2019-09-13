#pragma once

#include "Figure.h"
#include "Point.h"
#include <math.h>

class Square : virtual public Figure
{
    Point p1, p2, p3, p4;
    float side = 0, diagonal = 0;

public:
    Square(const string &name, float x1, float y1, float x4, float y4);
    Square(const string &name, Point p1, Point p4);
    Square(const string &name, float x1, float y1, float side);
    Square(const string &name, Point p1, float side);

    float findDiagonal();

    Point getP1();

    void setP1(Point p1);

    Point getP2();

    void setP2(Point p2);

    Point getP3();

    void setP3(Point p3);

    Point getP4();

    void setP4(Point p4);

    float getSide() const;

    void setSide(float side);

    float getDiagonal() const;

    void setDiagonal(float diagonal);
};
