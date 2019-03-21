#include <iostream>
using namespace std;
// 1.Написать функцию, которая возвращает произведение двух целых чисел,
// полученных в качестве аргумента.
int Prod(int a, int b)
{
    if (a && b != 0)
    {
        return a * b;
    }
    return 0;
}

int main()
{
    int a = 0, b = 0, res = 0;
    cout << "Enter two numbers ti product ==> ";
    cin >> a >> b;
    res = Prod(a, b);
    cout << res;
}
