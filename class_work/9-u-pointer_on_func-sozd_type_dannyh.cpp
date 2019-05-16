#include <iostream>
#include <iomanip>
#include <ctime>
#include <string.h>
#include <math.h>
using namespace std;

//
/* 
void hello() // тип данных - пустой войд
{
    cout << "Hello\n";
}

int main()
{
    cout << (void *)hello << "\n\n"; // выводит адресс в памяти
    void (*pt)();                    // создание указателя на ф-ю ,которая ничего не принимает и ничего не возвращает
    pt = hello; // передача указателя 
    pt();
}
 */
//-----------------------------------------------------------------------------------------------
//                      пример вызова ф-й в других ф-ях
//-----------------------------------------------------------------------------------------------
/* 
int Counter(int *arr, int size, bool (*pt)(int))
{
    int n = 0;
    for (int i = 0; i < size; i++)
    {
        if (pt(arr[i]))
        {
            n++;
        }
    }
    return n;
}

bool is_even(int val)
{
    return val % 2 == 0;
}

bool is_positive(int val)
{
    return val > 0;
}

void Fill_array(int *arr, int size, int (*pt)())
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = pt();
    }
}

void Print_array(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int my_rand()
{
    return rand() % 15;
}

int main()
{
    bool (*pt)(int); // всегда берется в скобочки ,для понимания что это указатель
    int const size = 10;
    int arr[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Fill_array(arr, size, my_rand);
    Print_array(arr, size);
    cout << Counter(arr, size, is_even) << endl;
    cout << Counter(arr, size, is_positive) << endl;
}
 */
//-----------------------------------------------------------------------------------------------
/* 
int Calc(int a, int b, int (*operation)(int, int)) // хз че орет ,вроде точно
{
    return operation(a, b);
}
int Sum(int a, int b)
{
    return a + b;
}
int Dif(int a, int b)
{
    return a - b;
}
int Prod(int a, int b)
{
    return a * b;
}
int Quot(int a, int b)
{
    return a / b;
}
int Mod(int a, int b)
{
    return a % b;
}
int main()
{
    cout << Calc(12, 4, Sum) << endl;
    cout << Calc(12, 4, Dif) << endl;
    cout << Calc(12, 4, Prod) << endl;
    cout << Calc(12, 4, Quot) << endl;
    cout << Calc(12, 4, Mod) << endl;
    cout << "Liambda ==> " << Calc(12, 4, [](int a, int b) -> int { return pow(a, b); }) << endl; // лямбда выражения
    cout << "\n\n\n";
    //-----------------------------------------------------
    // создание статического массива указателей на ф-ю
    //----------------------------------------------------
    int (*arr[5])(int, int);
    arr[0] = Sum;
    arr[1] = Dif;
    arr[2] = Prod;
    arr[3] = Quot;
    arr[4] = Mod;
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i](12, 4) << endl;
    }

    // typedef int my_type; // псевдоним для int
    typedef int (*f_type)(int,int);// ключевое слово(псевдоним) f_type для всей конструкции 
    f_type *arr = new f_type[5];
    
}
 */
//-----------------------------------------------------------------------------------------------
//                      Создание типов данных.Структуры
//-----------------------------------------------------------------------------------------------
/* 
struct Point // структура для точки в плоскости
{
    int x;
    int y;
}; // точка с запятой структурах в конце !!!

int main()
{
    // int a_x=12;
    // int a_y=34;
    // int b_x=1;
    // int b_y=9; 
    // правильный аналог ниже
    Point a;
    a.x = 12; // инициализация (создаются внутри Point)
    a.y = 45;
    Point b;
    b.x = 3;
    b.y = 10;
    Point arr[10]; // структура - группировка для упрощения
    //понимания и уменьшения  кода
    cout << sizeof(a) << endl; // показывает сколько памяти выделено в памяти (выравнивает
    // внутри все по максимальному размеру(зависит от порядка создания ,можно сделать меньше))

    Point *pa = &a; // указатель
    // (*pa).x=23;// сложный укаатель ,не очень
    pa->x = 23;
    pa->y = 34; // селектор (оператор выбора) Нужно чтобы там что то былo ,
    // или будет ошибка . Вариант по лучше ,того что выше
}
 */
//-----------------------------------------------------------------------------------------------
/* 
struct Date
{
    int day;
    char month[20];
    int year;
}; // точка с запятой структурах в конце !!!

void Print_date(Date d)
{
    cout << d.day << "." << d.month << "." << d.year << endl;
}
int main()
{
    Date today;
    today.day = 20;
    // today.month="April"; // нельзя ,так можно только при создании
    strcpy(today.month, "Aprill");
    today.year = 2019;
    //cout << today.day << "." << today.month << "." << today.year << endl; // тут обьявлять
    // геморно ,лучше ф-я
    Print_date(today);
}
 */
//-----------------------------------------------------------------------------------------------
//                          вложеные структуры
//-----------------------------------------------------------------------------------------------
/* 
struct Date
{
    int day;
    char month[20];
    int year;
};

void Print_date(Date d) // нельзя сделать универсальный
{
    cout << d.day << "." << d.month << "." << d.year << endl;
}

struct Person
{
    char name[20];
    Date birthday;
};

void Set_person(Person &person)
{
    cout << "\nName ==> ";
    cin.getline(person.name, 20);
    cout << "\nDay ==> ";
    cin >> person.birthday.day;
    cin.ignore(); // всегда после сина ставить игнор
    cout << "\nMonth ==> ";
    cin.getline(person.birthday.month, 20);
    cout << "\nYear ==> ";
    cin >> person.birthday.year;
    cin.ignore();
}

void Print_person(Person person)
{
    cout << person.name << "  " << person.birthday.day << "." << person.birthday.month << "." << person.birthday.year << endl;
}

void Add_person(Person *&arr, int &size) // увеличение размера и вызов ф-и добавления персоны
{
    if (size == 0) // увеличение размера
    {
        arr = new Person[1];
    }
    else // увеличение размера
    {
        Person *tmp = new Person[size + 1];
        for (int i = 0; i < size; i++)
        {
            tmp[i] = arr[i];
        }
        delete[] arr;
        arr = tmp;
    }
    Set_person(arr[size]);
    size++;
}

void Remove_person(Person *&arr, int &size, int pos) // удаление персоны
{
    if (pos < 0 || pos >= size) // эксепшн ,защита от вылетов
    {
        return;
    }
    Person *tmp = new Person[--size];
    for (int i = 0, j = 0; i < size; j++, i++) //пересоздает массив исключая ненужную персону
    {
        if (i == pos)
        {
            j++;
        }
        tmp[i] = arr[j];
    }
    delete[] arr;
    arr = tmp;
}

int main()
{
    int size = 0;
    Person *arr = nullptr;

    Add_person(arr, size);
    Add_person(arr, size);
    for (int i = 0; i < size; i++)
    {
        Print_person(arr[i]);
    }
    Remove_person(arr, size, 0);
    for (int i = 0; i < size; i++)
    {
        Print_person(arr[i]);
    }
    if (size)
    {
        delete[] arr;
    }
}
 */
//-----------------------------------------------------------------------------------------------

struct Date
{
    int day;
    char *month;
    int year;
};

int main()
{
    Date today;
    today.day = 20;
    today.month = new char[strlen("april") + 1];
    strcpy(today.month, "april");
    today.year = 2019;
    cout << today.day << "." << today.month << "." << today.year << endl;
    Date tmp = today;
    tmp.day = 12;
    tmp.month[0] = 'A'; // КОПИРУЕТСЯ АДРЕС В МАССИВЕ, А НЕ ДЕЛАЕТСЯ НОВЫЙ ,ДЛЯ "КУЧИ" КОПИРУЕТСЯ УКАЗАТЕЛЬ
    cout << "tmp ==> " << tmp.day << "." << tmp.month << "." << tmp.year << endl;
    cout << "today ==> " << today.day << "." << today.month << "." << today.year << endl;

    // tmp.month = new char[strlen(today.month)+1]; // создать для tmp свой массив в куче - придется освобождать

    delete[] today.month; // удалит и для tmp т.к. он указывает сюда
    delete[] tmp.month;
}

//-----------------------------------------------------------------------------------------------
