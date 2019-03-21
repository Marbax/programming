#include <iostream>
using namespace std;
// 4. Написать функцию, которая сравнивает два целых числа и возвращает результат
// сравнения в виде одного из знаков: >, < или =.
int Comparison(int a, int b)
{
    char res;
    (a > b) ? res = '>' : (a < b) ? res = '<' : res = '=';
    return res;
}

int main()
{
    int a = 0, b = 0;
    char res;
    cout << "Enter two numbers to find bigger one ==> ";
    cin >> a >> b;
    res = Comparison(a, b);
    cout << a << res << b;
}
