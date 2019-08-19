#include <iostream>

using namespace std;

class Point
{
protected: // можно будет работать из потомков private:
    int x;
    int y;

public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    void setX(int val)
    {
        Point::x = x;
    }

    void setY(int val)
    {
        Point::y = y;
    }

    int getX() const { return x; }

    int getY() const { return y; }

    void print() { cout << " X = " << x << " Y = " << y << endl; }
};

class Point3D : public Point
{
private:
    int z;

public:
    Point3D(int x, int y, int z) : Point(x, y)
    {
        this->z = z;
    }
    void print() { cout << " X = " << x << " Y = " << x << " Z = " << z << endl; }

    /* void print()
    {
        Point::print();
        cout << " Z = " << z << endl;
    } */

    // если потомку не достпуны приватные поля void print() { cout << " X = " << getX() << " Y = " << getY() << " Z = " << z << endl; }
};

int main()
{
    Point a(1, 2);
    a.print();
    Point3D b(12, 23, 34);
    b.print();
}