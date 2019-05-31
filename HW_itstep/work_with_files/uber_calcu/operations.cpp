#include "operations.h"

float Sum(float a, float b)
{
    return a + b;
}

float Sub(float a, float b)
{
    return a - b;
}

float Mult(float a, float b)
{
    return a * b;
}

float Div(float a, float b)
{
    return a / b;
}

void Input(float &a, float &b)
{
    cout << "\tEnter two numbers\na = ";
    cin >> a;
    cin.ignore();
    cout << "b = ";
    cin >> b;
    cin.ignore();
}