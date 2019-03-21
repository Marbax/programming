#include <iostream>
using namespace std;

int main()
{
    float num, step, i = 0, res;
    cout << "Enter the number : ";
    cin >> num;
    res = num;
    cout << "Enter the exponent : ";
    cin >> step;

    if (step != 0)
    {

        if (step > 0)
        {
            while (i < step - 1)
            {
                res *= num;
                i++;
            }
            cout << "\nResult of exponentiation : " << res << endl;
        }
        else
        {
            while (i > step + 1)
            {
                res *= num;
                i--;
            }
            cout << "\nResult of exponentiation : " << 1 / res << endl;
        }
    }
    else
        cout << "\nResult of exponentiation : " << 1;
}