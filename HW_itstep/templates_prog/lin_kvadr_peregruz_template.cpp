#include <iostream>
#include <math.h>
using namespace std;
// 2. Написать перегруженные шаблоны функций для нахождения корней линейного
// (a*x + b = 0) и квадратного (a*x^2 +b*x + c = 0) уравнений. Замечание: в функции
// передаются коэффициенты уравнений.

int Linear_equation(int a, int b) // (a*x + b = 0)
{

    double res;
    res = (-b) / a;
    return res;
}

double Linear_equation(double a, double b) // (a*x + b = 0)
{

    double res;
    res = (-b) / a;
    return res;
}

double Linear_equation(double a, int b) // (a*x + b = 0)
{

    double res;
    res = (-b) / a;
    return res;
}

void Quadratic_equation(double a, double b, double c) // (a*x^2 +b*x + c = 0)
{

    double x1, x2, d;
    d = (b * b) - (4 * a * c);
    if (d > 0)
    {

        x1 = ((-b) + sqrt(d)) / (2 * a);
        x2 = ((-b) - sqrt(d)) / (2 * a);
        cout << "Answer for Quadratic equation: x1 = " << x1 << "\n";
        cout << "Answer for Quadratic equation: x2 = " << x2 << "\n";
    }
    else if (d < 0)
    {

        cout << "There no roots for Quadratic equation\n";
    }
    else if (d == 0)
    {

        x1 = ((-b) + sqrt(d)) / (2 * a);
        cout << "Answer for Quadratic equation: x1 = " << x1 << "\n";
    }
}
int main()
{
    int a = 2, b = 7, c = 2, lin = 0;
    //double a = 2, b = 2, c = 2, lin = 0;
    lin = Linear_equation(a, b);
    cout << "Answer for linear equation: x=" << lin << endl << endl;
    Quadratic_equation(a, b, c);
}
/* 
int main()
{
    int choose;
    do
    {
        double a, b, c;
        //int a, b, c;
        cout << "Press 1 - for linear equation (a*x + b = 0)\n or press 2 - for quadratic equation (a*x^2 + b*x + c = 0) .\n";
        cin >> choose;
        switch (choose)
        {
        case 1:
            cout << "Enter an coefficient a - ";
            cin >> a;
            cout << "Enter an coefficient b - ";
            cin >> b;
            cout << "Answer for linear equation: x = " << Linear_equation(a, b) << "\n";
            break;
        case 2:
            cout << "Enter an coefficient a - ";
            cin >> a;
            cout << "Enter an coefficient b - ";
            cin >> b;
            cout << "Enter an coefficient c - ";
            cin >> c;
            Quadratic_equation(a, b, c);
            break;
        }
        cout << "If you want to repeat , press - 1:";
        cin >> choose;

    } while (choose == 1);
} */
