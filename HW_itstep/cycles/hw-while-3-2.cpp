#include <iostream>
using namespace std;

int main()
{
    int poly, ylop = 0;
    cout << "Enter the number to check is it palindrome or not : ";
    cin >> poly;
    int i_poly = poly;
    while (i_poly > 0) //цикл работает ,пока есть цифры в числе ,с каждой итерацией стает на одно число меньше
    {
        ylop = ylop * 10 + i_poly % 10; //добавляет знак справа и засовыет туда отрезаную цифру
        i_poly /= 10;                   // удаляет последню цифру
    }
    (poly == ylop) ? cout << "\n\nIt's palindrome!" : cout << "\n\nIt's not palindrome!";
}