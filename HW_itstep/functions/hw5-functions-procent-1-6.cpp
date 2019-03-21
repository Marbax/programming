#include <iostream>
using namespace std;
// 6. Написать функцию, которая, в зависимости от выбора пользователя вызывает
// функцию сложения, произведения, вычитания и деления 2-х чисел.
float Sum(float a, float b)
{
    float res = a + b;
    return res;
}
float Prod(float a, float b)
{
    float res = a * b;
    return res;
}
float Sub(float a, float b)
{
    float res = a - b;
    return res;
}
float Division(float a, float b)
{
    char err = 'Error.Division by zero';
    if (b != 0)
    {
        float res = a / b;
        return res;
    }

    return err;
}

float Calc(int num)
{
    char err = 'Error.Wrong input';
    float a = 0, b = 0, res;
    cout << "Enter number ==> ";
    cin >> a;
    cout << "Enter procent ==> ";
    cin >> b;
    switch (num)
    {
    case 1:
        return res = Sum(a, b);
        break;

    case 2:
        return res = Prod(a, b);
        break;

    case 3:
        return res = Sub(a, b);
        break;

    case 4:
        return res = Division(a, b);
        break;

    default:
        return err;
        break;
    }
}

int main()
{
    float res = 0;
    int num = 0;
    cout << "What you want to do ? \n1 - To find digits sum\n2 - To find digits product\n3 - To find digits subtraction\n4 - To find digits division" << endl;
    cin >> num;
    res = Calc(num);
    cout << res;
}
