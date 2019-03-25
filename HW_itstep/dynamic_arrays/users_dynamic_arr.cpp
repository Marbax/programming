#include <iostream>
using namespace std;

// 1. Создать динамический массив, размер которого пользователь вводит с
// клавиатуры. Заполнить его случайными числами из диапазона [10;20] и вывести
// его на экран.

void Fill_array(int *arr, int size)
{
    srand(time(0));
    int max = 20, min = 10;
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

int main()
{
    int size = 0;
    cout << "Enter array's size" << endl;
    cin >> size;
    int *arr = new int[size];
    Fill_array(arr, size);
    Print_array(arr, size);
    delete[] arr;
}
