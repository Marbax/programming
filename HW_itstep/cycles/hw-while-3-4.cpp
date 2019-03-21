#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int end, fib = 1, fib1 = 0, ans = 0;
    cout << "Enter the value to which the fibonacci numbers should be counted : ";
    cin >> end;
    cout << "\nFibonacci array :" << endl;

    while (ans <= end)
    {
        cout << ans << "  ";
        ans = fib + fib1;
        fib = fib1;
        fib1 = ans;
    }
}