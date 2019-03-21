#include <iostream>
using namespace std;
// 5. Написать функцию Procent, которая возвращает процент от полученного в
// качестве аргумента числа.
float Procent(float a, float proc)
{
    float res = a / 100 * proc;
    return res;
}

int main()
{
    float a = 0, proc = 0, res;
    cout << "Enter number ==> ";
    cin >> a;
    cout << "Enter procent ==> ";
    cin >> proc;
    res = Procent(a, proc);
    cout << proc << "% of " << a << " is " << res;
}
