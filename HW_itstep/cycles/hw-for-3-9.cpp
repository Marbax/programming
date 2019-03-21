#include <iostream>
using namespace std;

int main()
{
    double x, min = 9223372036854775807.0, por;
    cout << "Enter 10 numbers " << endl;
    for (int i = 1; i <= 10; i++)
    {
        cout << "--> ";
        cin >> x;
        if (x < min)
        {
            min = x, por = i;
        }
    }
    cout << "Minimal number was --> " << min << " it's number in array was --> " << por;
}
//(max == min) ? cout << "eual " : (min < max) ? cout << "max" : cout << " min ";
