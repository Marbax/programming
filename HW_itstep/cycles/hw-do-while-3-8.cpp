#include <iostream>
using namespace std;

int main()
{
    float x, min = 1, max = 0;
    cout << "Enter the number" << endl;
    do
    {
        cout << "--> ";
        cin >> x;
        (x < 0) ? min *= x : max += x;

    } while (x != 0);
    (max > min) ? cout << "\nSumm of positive numbers are bigger " << max << ">" << min : (max < min) ? cout << "Product of negative numbers are bigger " << max << "<" << min : cout << "They are equalent " << max << "==" << min;
    //  same /|\
    //        |
    //(max > min) ? cout << "max" : (max<min) ? cout << "min" : cout << "equal";
    //
    //(max == min) ? cout << "eual " : (min < max) ? cout << "max" : cout << " min ";
}