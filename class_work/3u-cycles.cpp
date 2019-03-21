#include <iostream>
using namespace std;
int main()
/* {
    int i = 0;
    while (i < 10)
    {
        cout << ++i << endl;
    }
}
 */
/* { //считает кол-во чисел
    int num, i = 1;
    cout << "Enter number :";
    cin >> num;
    while (num > 9)
    {
        num = num / 10;
        i++;
    }
    cout << i;
} */
/* //провверить простое число или составное , простое делится ТОЛЬКО на себя и на один
    //простой способ,но много итераций {
    int num, n = 0, i = 1;
    cout << "Input the number : ";
    cin >> num;
    while (i <= num)
    {
        if (num % i == 0)
            n++;
        i++;
    }
    (n == 2) ? cout << "The number is prime" : cout << "The number is Composite";
} */

/*
{
    // for (созд пер;условие;изм пер)
//{тело} 
    for (int i = 0; i < 10; i++)//итерация происходит после тела цикла
    {
        cout << i << endl;
    }
} */

/* {
    //1. Написать программу, которая выводит на экран числа от 0 до 20.
    for (int i = 0; i < 21; i++)
    {
        cout << i << endl;
    }
} */

/* {
    //2. Написать программу, которая выводит на экран первые 10 четных чисел.
    int num,chetn;
    cout << "Enter the number :";
    cin >> num;
        for (int i = 0; i <= 10; i++)
    {
        if (i%2==0){
            chetn =i;
            cout << chetn<<endl;
        }
    }
} */

/* {    //3. Написать программу, которая выводит на экран все числа в диапазоне указанном пользователем.

    int num1,num2;
    cout << "Enter the first numbers :";
    cin >> num1;
    cout << "Enter the second numbers :";
    cin >> num2;


        for (int i = num1; i <= num2; i++)
    {
        cout << i<<endl;
}
} */

/* {    //Написать программу, которая выводит на экран ряд из символов, который указывает пользователь. Количество выводимых символов также указывает пользователь.

    int num;
    char cym;
    cout << "Enter the amount :";
    cin >> num;
    cout << "Enter the cymbol :";
    cin >> cym;
    for (int i = 0; i < num; i++)
    {
        cout << cym;
    }
} */

/* { //простые и слоденые числа фором ,легкая версия
    int num, n = 0;
    cout << "Enter the numer :";
    cin >> num;
    for (int i = 1; i <= num; i++)
    {
        if (num % i == 0)
            n++;
    }
    (n == 2) ? cout << "Prime" : cout << "Composite";
} */

/* { //сложная версия
    int num;
    bool f = true;
    cout << "Enter the numer :";
    cin >> num;
    for (int i = 2; i <= sqrt(num); i++) //нужна библиотека , корень обрезает кучу ненужных итераций
    {
        if (num % i == 0)
            f = false;
        break;
    }
    (f) ? cout << "Prime" : cout << "Composite";
} */

/* { // do while
    
        int i = 0;
        do
        {
            cout << "Hello world";
            i++;
        } while (i < 0);
    
} */

/* { //считывает числа ,пока пользователь не введет ноль
    int num;
    do
    {
        cout << "Enter num : ";
        cin >> num;
    } while (num != 0);
} */

/* { //полз вводит два числа найти наименьшее общее кратное 4 и 2 = 4 , 3 & 5 = 15 , 4 & 6 =12 , мой вариант 
    int num1, num2;
    cout << "Enter two numbers : ";
    cin >> num1 >> num2;

    for (int i = 1; i <= num1 * num2; i++)
    {
        if ((i % num1 == 0) && (i % num2 == 0)){
            cout << i << endl;
            break;
        }
    }
} */

/* { //полз вводит два числа найти наименьшее общее кратное 4 и 2 = 4 , 3 & 5 = 15 , 4 & 6 =12
    int num1, num2, max, nok;
    cout << "Enter two numbers : ";
    cin >> num1 >> num2;
    max = num1 > num2 ? num1 : num2;

    for (int i = max; i <= num1 * num2; i += max)
    {
        if ((i % num1 == 0) && (i % num2 == 0))
        {
            nok = i;
            break;
        }
    }
    cout << nok << endl;
} */

/* {// continue;
    for (int i =0; i<10;i++)
    {
        if (i==5)
            continue; //не выведет 5 только ,равносильно if i!=5
        cout <<i<<endl;

    }
} */

/* { //вложеный цикл с рисованием 
    for (int i = 0; i < 5; i++)
    {
        for (int c = 0; c < 5; c++)
        {
            if (i == 0 || i == 4 || c == 0 || c == 4 || i + c == 4 || i == c)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << endl;
    }
} */

/* { //вложеный цикл с рисованием линии и треуголника
    for (int i = 0; i < 5; i++)
    {
        for (int c = 0; c < 5; c++)
        {
            if (i == c) //линия , а (i>=c )треугольник
                cout << "* ";
            else
                cout << "  ";
        }
        cout << endl;
    }
} */

/* { //вложеный цикл с рисованием пирамиды
    for (int i = 0; i < 4; i++)
    {
        for (int c = 0; c < 7; c++)
        {
            if (i + c >= 3 && i >= c - 3) // пирамида , а так перевернутая пирамида (i <= c && i +c <7)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << endl;
    }
} */