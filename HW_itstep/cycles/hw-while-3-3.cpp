#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    float x = -4, y;
    cout << "\tx\t|\ty\t" << endl;
    cout << "-------------------------------------" << endl;

    while (x <= 4)
    {

        y = 2 * pow(x, 2) - 5 * x - 8;
        cout << "\t" << x << "\t|\t" << y << "\t" << endl;
        x += 0.5;
    }
}