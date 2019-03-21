#include <iostream>
#include <ctime>
#include <iomanip> //форматирование вывода
using namespace std;

// 1. Дан массив случайных чисел в диапазоне от -20 до +20. Необходимо найти
// позиции крайних отрицательных элементов (самого левого отрицательного
// элемента и самого правого отрицательного элемента) и отсортировать элементы,
// находящиеся между ними.

void Fill_Array(int arr[], int size)
{
    srand(time(0));
    int max = 20, min = -20;
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % (max - min) + min; // формула диапазона
    }
}

int Find_min_index(int arr[], int size)
{
    int min_min = arr[0], min_index = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            if (arr[i] < min_min)
            {
                min_min = arr[i];
                min_index = i;
            }
        }
    }
    return min_index;
}

int Find_max_index(int arr[], int size, int min_index)
{
    int min_max = arr[min_index], max_index = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            if (arr[i] > min_max)
            {
                min_max = arr[i];
                max_index = i;
            }
        }
    }
    return max_index;
}
void Sliced_Array(int arr[], int size, int min_index, int max_index)
{
    int start, end;
    (min_index < max_index) ? start = min_index : start = max_index;
    (min_index < max_index) ? end = max_index : end = min_index;
    cout << "\nSliced array\n";
    for (int i = start; i < end; i++)
    {
        cout << setw(5) << arr[i];
    }
}

void Sort_minimum(int arr[], int size, int min_index, int max_index)
{
    int start, end;
    (min_index < max_index) ? start = min_index : start = max_index;
    (min_index < max_index) ? end = max_index : end = min_index;
    cout << "\n\nSorted array\n";
    for (int i = start; i < end; i++)
    {
        for (int j = end - 1; j > i; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                swap(arr[j], arr[j - 1]); // своп меняет местами елеменеты
            }
        }
        cout << setw(5) << arr[i];
    }
}

void Print_Array(int arr[], int size)
{
    cout << "\nDeffault array\n";
    for (int i = 0; i < size; i++)
    {
        cout << setw(5) << arr[i];
    }
}

int main()
{
    const int size = 20;
    int min_index, max_index;
    int arr[size]{};
    Fill_Array(arr, size);
    Print_Array(arr, size);
    min_index = Find_min_index(arr, size);
    max_index = Find_max_index(arr, size, min_index);
    cout << "\n\n";
    Sliced_Array(arr, size, min_index, max_index);
    Sort_minimum(arr, size, min_index, max_index);
}
