#include <iostream>
using namespace std;

int main()
{
    int x, i = 0, c = 0, res;
    cout << "Enter the number" << endl;
    do
    {

        if (i == 3)
        {
            res = x;
            do
            {
                res /= 10;
                c++;

            } while (res > 0);

            cout << "\nThird positive number is " << x << ". There are " << c << " numbers in it.\n";
            i = 0;
            c = 0;
        }
        cout << "--> ";
        cin >> x;
        if (x > 0)
        {
            i++;
        }

    } while (x != 0);
}