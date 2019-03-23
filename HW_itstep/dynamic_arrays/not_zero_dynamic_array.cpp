#include <iostream>
using namespace std;

// 2. Создать статический массив на 10 элементов и заполнить его случайными
// числами из диапазона [0;5]. Подсчитать количество элементов не равных нулю.
// Создать динамический массив соответствующего размера и скопировать в него
// все ненулевые элементы.

void Fill_array(int *arr, int size)
{
    srand(time(0));
    int max = 5, min = 0;
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % (max - min) + min;
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
    int n = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] != 0)
        {
            n++;
        }
    }
    return n;
}

void Fill_dynamic_array(int *f_arr, int *s_arr, int size)
{
    for (int i = 0, j = 0; i < size; i++)
    {
        if (f_arr[i] != 0)
        {
            s_arr[j] = f_arr[i];
            j++;
        }
    }
}

int main()
{
    int f_arr[10]{};
    Fill_array(f_arr, 10);
    cout << "Starting array ==> ";
    Print_array(f_arr, 10);
    int size = Counter(f_arr, 10);
    int *s_arr = new int[size];
    Fill_dynamic_array(f_arr, s_arr, 10);
    cout << "\nDynamycaly created array from not zero values of started array ==> ";
    Print_array(s_arr, size);
    delete[] s_arr;
}
