#include <iostream>
using namespace std;
// 3. Написать функцию, которая возвращает максимальное из двух целых чисел,
// полученных в качестве аргумента.
int Find_bigger(int a, int b)
{
    int res = 0;
    (a > b) ? res = a : res = b;
    return res;
}

int main()
{
    int a = 0, b = 0, res = 0;
    cout << "Enter two numbers to find bigger one ==> ";
    cin >> a >> b;
    res = Find_bigger(a, b);
    cout << res << " bigger";
}
