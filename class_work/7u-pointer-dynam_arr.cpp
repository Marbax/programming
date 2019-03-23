#include <iostream>
using namespace std;

/* 
int main()
{
    int a = 5;
    int *pa = &a;        // & для получения адреса в памяти
    cout << *pa << endl; // * разименование , позволяет получить содержимое переменной через
    // указатель на нее
    cout << pa << endl;
}
 */

//----------------------------------------------------------------------------------------------
// как void может возвращать значения
/* 
void Swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int main()
{
    int a = 3, b = 5;
    cout << a << " " << b << endl;
    Swap(&a, &b);
    cout << a << " " << b << endl;
}
 */
//----------------------------------------------------------------------------------------------
// для массива указатели и так используются
/* 
int main()
{
    int arr[5]{5, 4, 6, 6, 2};
    int *pt = arr;
    for (int i = 0; i < 5; i++)
    {
        cout << *(pt + i) << " "; // условно работает быстре
    }
    cout << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << pt[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << *pt + i << " "; // добавляет к первому разыменованому значению итое (всегда 5 + i)
    }
    cout << endl;
}
 */
//----------------------------------------------------------------------------------------------
/* 
int main()
{
    int *pt;
    pt = new int;
    *pt = 12;
    cout << *pt << endl;
    int *arr = new int [10000000]{};
    delete pt;
    delete[]arr;
}
 */
//----------------------------------------------------------------------------------------------
// убийца памяти
/* 
int main()
{
    int *pt;
    for (;;)
    {
        pt = new int [10000];
        system("sleep 1");
    }
    system("sleep 200");
}
 */
//----------------------------------------------------------------------------------------------
// динамические массивы
// инициализация массива и его очистка потом
/* 
void Fill_array(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 10;
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
int Counter(int *arr, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}
int main()
{
    int size = 5;
    int *arr = new int[size];
    Fill_array(arr, size);
    Print_array(arr, size);
    cout << Counter(arr, size);
    delete[] arr;
}
 */

//----------------------------------------------------------------------------------------------
// найти кол-во четных эллементов и создать новый массив с размером кол-ва четных чисел и заполнить ими
// мой рагульный не успевший вариант
/* 
void Fill_array(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 10;
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
int Counter(int *arr, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}
void New_array(int *arr, int *brr, int size)
{
    for (int i = 0, j = 0; i < size; i++, j++)
    {
        if (arr[i] % 2 == 0)
        {
            brr[j] = arr[i];
        }
    }
}
void Print_brray(int *brr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << brr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int size = 10;
    int *arr = new int[size];
    int *brr = new int;
    Fill_array(arr, size);
    Print_array(arr, size);
    //cout << Counter(arr, size);
    New_array(arr, brr,size);
    Print_brray(arr, size);

    delete[] arr;
}
 */
//----------------------------------------------------------------------------------------------
// найти кол-во четных эллементов и создать новый массив с размером кол-ва четных чисел и заполнить ими
/* 
void Fill_array(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 10;
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

void Print_mass_array(int *mas, int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << mas[i] << " ";
    }
    cout << endl;
}
int main()
{
    srand(time(0));
    int size = 10;
    int *arr = new int[size];
    int n = 0;
    Fill_array(arr, size);
    Print_array(arr, size);

    for (int i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 0)
        {
            n++;
        }
    }
    int *mas = new int[n];
    n = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 0)
        {
            mas[n] = arr[i];
            n++;
        }
    }
    Print_mass_array(mas, n);
    delete[] arr;
}
 */

//----------------------------------------------------------------------------------------------
// добавление нового эллемента , принимает массив  ,размер,и эллем ,который нужно добавить

void Fill_array(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 10;
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

void Add_to_array(int *&arr, int &size, int value)
{
    int *tmp = new int[size + 1];  // 1
    for (int i = 0; i < size; i++) // 2
    {
        tmp[i] = arr[i];
    }
    delete[] arr; // 3

    arr = tmp; // 4
    arr[size] = value;
    size++;
}
/* 
void Add_to_array_like_C(int **arr, int *size, int value) // Способ из C
{
    int *tmp = new int[*size + 1];  // 1
    for (int i = 0; i < *size; i++) // 2
    {
        tmp[i] = *(*arr + i);
    }
    delete[] * arr; // 3

    *arr = tmp; // 4
    // *(*arr+*size) = value;
    tmp[*size] = value;
    // (*size)++;
    *size = *size + 1;
}
 */

int main()
{
    srand(time(0));
    int size = 10;
    int *arr = new int[size];
    int n = 0;
    Fill_array(arr, size);
    Print_array(arr, size);
    Add_to_array(arr, size, 100);
    Print_array(arr, size);
    delete[] arr;
}

//----------------------------------------------------------------------------------------------
// ссылка
/* 
int main()
{
    int a = 5;
    int *pa = &a; // указатель
    int &ra = a;    // ссылка
    int *&pra = pa; // ссылка на указатель
    ra = 123;
    cout << a << endl;
}
 */