#include <iostream>
#include <string.h>
#include <stdarg.h> // библиотека с макросами для работы с  ...

using namespace std;

class Point
{
private:
    int x = 0;
    int y = 0;

public:
    Point() = default;
    Point(int x, int y) : x(x), y(y) {}
    int getX() { return x; }
    int getY() { return y; }
    void Print() { cout << "x = " << x << " y = " << y; }
    ~Point() {}
};

void Hello(...) // ... значат что принимает сколько угодно аргументов (даже разных типов)
{
    cout << "HEllo" << endl;
}

int Sum(int size, ...) // кол-во еллементов и эти параметры // работает только для однотипных
{
    int sum = 0;
    va_list list;
    va_start(list, size); // принимает лист и то с чего он начинается(перемещает указатель за второй параметр)
    for (size_t i = 0; i < size; i++)
    {
        sum += va_arg(list, int); // второй параметр то ,что вытаскиваем(по 4 байта )
    }
    va_end(list);
    return sum;
}

/* 
void MyTestPrintF(const char *format, ...)
{
    va_list list;
    va_start(list, format);
    for (size_t i = 0; i != '\0'; i++)
    {
        if (va_arg(list, char) != '%')
        {
            cout << va_arg(list, char);
        }
        if (va_arg(list, char) == '%')
        {
            i++;
            if (va_arg(list, char) == 'd')
            {
                cout << va_arg(list, int);
            }
            if (va_arg(list, char) == 's')
            {
                cout<<va_arg(list,;
            }
        }
    }
}
 */
void MyPrintF(const char *format, ...)
{
    va_list list;
    va_start(list, format);
    for (const char *pt = format; *pt; pt++)
    {
        if (*pt == '%')
        {
            switch (*++pt)
            {
            case 'd':
                cout << va_arg(list, int);
                break;
            case 'f':
                cout << va_arg(list, double);
                break;
            case 's':
                cout << va_arg(list, char *);
                break;
            case '%':
                cout << "%";
                break;
            case 'p':
                //va_arg(list, Point).Print(); // в gcc  не работает (VS Studio все ок)
                va_arg(list, Point *)->Print();
                break;

            default:
                break;
            }
        }
        else
            cout << *pt;
    }
}
int main()
{
    //cout << Sum(6, 2, 3, 4) << endl; // если кол во больше действительного ,будет мусор брать
    cout << Sum(3, 2, 3, 4) << endl; // работает только для однотипных
    cout << Sum(10, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1) << endl;

    int day = 29;
    int year = 2019;
    char month[] = "June";
    MyPrintF("Today is %d %s %d\n", day, month, year);

    cout << endl;
    MyPrintF("Today is %d %s %d\n%f", day, month, year, 3.14);

    cout << endl;
    Point point(3, 5);
    MyPrintF("Today is %d %s %d\n%f and %p", day, month, year, 3.14, &point);
}