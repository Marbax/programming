#include <iostream>
using namespace std;

int main()
{
    int num1, num2, min, nod;
    cout << "Enter two numbers : ";
    cin >> num1 >> num2;
    min = num1 < num2 ? num1 : num2;

    for (int i = min; i > 0; i--)
    {
        cout << "----" << i << endl;
        if ((num1 % i == 0) && (num2 % i == 0))
        {
            nod = i;
            break;
        }
    }
    cout << "Nod is " << nod << endl;
}
//(max == min) ? cout << "eual " : (min < max) ? cout << "max" : cout << " min ";
