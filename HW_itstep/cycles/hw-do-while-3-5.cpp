#include <iostream>
using namespace std;

int main()
{
    int x, dob = 1;
    cout << "Enter array of numbers to product them : ";
    do
    {
        cin >> x;
        if (x > 0)
        {
            dob *= x;
        }

    } while (x != 0);
    cout << "Result is: " << dob;
}