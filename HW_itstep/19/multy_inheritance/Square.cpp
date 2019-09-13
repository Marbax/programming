#include "Square.h"

Square::Square(const string &name, float x1, float y1, float x4, float y4) : Figure(name)
{
    p1.x = x1;
    p1.y = y1;
    p4.x = x4;
    p4.y = y4;
    p2.x = p1.x;
    p2.y = p1.y;
    p3.x = p4.x;
    p3.y = p4.y;
    findDiagonal();
}

Square::Square(const string &name, Point p1, Point p4) : Figure(name), p1(p1), p4(p4)
{
    p2.x = p1.x;
    p2.y = p1.y;
    p3.x = p4.x;
    p3.y = p4.y;
    findDiagonal();
}

Square::Square(const string &name, float x1, float y1, float side) : Figure(name), side(side)
{
    p1.x = x1;
    p1.y = y1;
    p2.x = p1.x + side;
    p2.y = p1.y;
    p3.x = p1.x;
    p3.y = p1.y + side;
    p4.x = p2.x;
    p4.y = p3.y;
    findDiagonal();
}

Square::Square(const string &name, Point p1, float side) : Figure(name), p1(p1), side(side)
{
    p2.x = p1.x + side;
    p2.y = p1.y;
    p3.x = p1.x;
    p3.y = p1.y + side;
    p4.x = p2.x;
    p4.y = p3.y;
    findDiagonal();
}

float Square::findDiagonal()
{
    this->side = side != 0 ? p2.x - p1.x : side;
    this->diagonal = side * sqrt(2);
}


Point Square::getP1() { return p1; }

void Square::setP1(Point p1) { this->p1 = p1; }

Point Square::getP2()  { return p2; }

void Square::setP2(Point p2) { this->p2 = p2; }

Point Square::getP3()  { return p3; }

void Square::setP3(Point p3) { this->p3 = p3; }

Point Square::getP4()  { return p4; }

void Square::setP4(Point p4) { this->p4 = p4; }

float Square::getSide() const { return side; }

void Square::setSide(float side) { this->side = side; }

float Square::getDiagonal() const { return diagonal; }

void Square::setDiagonal(float diagonal) { this->diagonal = diagonal; }
