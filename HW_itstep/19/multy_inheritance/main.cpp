/* Используя понятие множественного наследования, разработайте класс
"Окружность, вписанная в квадрат" */

#include "SquaredCircle.h"
using namespace std;

int main()
{
    Circle circle("circle", 40, 50, 12);
    cout << circle.getName() << " x=" << circle.getX() << " y=" << circle.getY() << " r=" << circle.getR() << endl;

    Square square("square", 80, 80, 50);
    cout << square.getName() << " p1=" << square.getP1() << " p2=" << square.getP2() << " p3=" << square.getP3() << " p4=" << square.getP4() << " side=" << square.getSide() << " diagonal=" << square.getDiagonal() << endl;

    SquaredCircle square_cirecle("SquaredCircle", 180, 180, 40, 90, 90, 80);
    cout << square_cirecle.getName() << " p1=" << square_cirecle.getP1() << " p2=" << square_cirecle.getP2() << " p3=" << square_cirecle.getP3() << " p4=" << square_cirecle.getP4() << " side=" << square_cirecle.getSide() << " diagonal=" << square_cirecle.getDiagonal() << " rcenterX=" << square_cirecle.getX() << " rcenterY=" << square_cirecle.getY() << " r=" << square_cirecle.getR() << endl;

    Point p1(200, 200);
    SquaredCircle square_cirecle1("SquaredCircle!", p1, 100);
    cout << square_cirecle1.getName() << " p1=" << square_cirecle1.getP1() << " p2=" << square_cirecle1.getP2() << " p3=" << square_cirecle1.getP3() << " p4=" << square_cirecle1.getP4() << " side=" << square_cirecle1.getSide() << " diagonal=" << square_cirecle1.getDiagonal() << " rcenterX=" << square_cirecle1.getX() << " rcenterY=" << square_cirecle1.getY() << " r=" << square_cirecle1.getR() << endl;
}
