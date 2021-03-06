#include <iostream>
#include <time.h>
using namespace std;

// 1. Написать функцию удаления элемента из одномерного динамического массива по
// заданной позиции. Предусмотреть возможность выхода указанной позиции за
// пределы массива(не удалять элемент, а выдавать сообщение об ошибке).

void Fill_array(int *arr, int size, int max, int min)
{
    srand(time(0));
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

void Ellement_removing(int *&arr, int &size, int &elem)
{
    //system("clear");
    if (elem < size)
    {
        size--;
        int *tmp = new int[size]; // 1

        for (int i = 0, j = 0; i < size; j++, i++) // 2
        {
            if (j == elem)
            {
                j++;
            }

            tmp[i] = arr[j];
        }
        delete[] arr; // 3

        arr = tmp; // 4
        Print_array(arr, size);
    }
    else
        cout << "Wrong number!";
}

int main()
{
    int size = 10, m = 0, n = 0;
    int max = 10, min = 0;
    int elem = 0;
    int *arr = new int[size];
    Fill_array(arr, size, max, min);
    Print_array(arr, size);
    cout << "Enter a number(index) of element which you want to remove ==> ";
    cin >> elem;
    Ellement_removing(arr, size, elem);

    delete[] arr;
}
