#include <iostream>
#include <time.h>
using namespace std;

// 1. Создать динамический массив на 10 элементов заполненный случайными
// числами. Написать функции:
//  a) удаления всех четных элементов;
//  b) добавления элемента в произвольную позицию;
//  c) удаления диапазона элементов (от m до n).

void Fill_array(int *arr, int size)
{
    srand(time(0));
    int max = 10, min = 0;
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

void Delete_chetn_numbers(int *arr, int size) //  a) удаления всех четных элементов;
{
}

void Element_adding(int *&arr, int &size, int new_one) //  b) добавления элемента в произвольную позицию;
{
    int *tmp = new int[size + 1]; // 1
    srand(time(0));
    int max = size, min = 0;
    int rand_index = rand() % (max - min) + min;
    tmp[rand_index] = new_one;

    for (int i = 0, j = 0; i < size+1; j++, i++) // 2
    {
        if (tmp[i] != 0)
        {
            i++;
        }

        tmp[i] = arr[j];
    }
    delete[] arr; // 3

    arr = tmp; // 4
    size++;
}

void Removing_elements_range(int *arr, int size, int m, int n) //  c) удаления диапазона элементов (от m до n).
{
}

int main()
{
    int size = 10;
    int new_one = 0;
    int *arr = new int[size];
    Fill_array(arr, size);
    cout << "Starting array :\n";
    Print_array(arr, size);
    while (true)
    {
        cout << "a) удаления всех четных элементов;\nb) добавления элемента в произвольную позицию;\nc) удаления диапазона элементов (от m до n).\nESC - выход\n";
        char key = getchar();
        switch (key)
        {
        case 99: // c) удаления диапазона элементов (от m до n).
            cout << "c\n";
            break;
        case 98: // b) добавления элемента в произвольную позицию;
            cout << "Enter a number to add it to random position ==> ";
            cin >> new_one;
            cout << "\n";
            Element_adding(arr, size, new_one);// после третьего вызова функции все безсмысленно плывет,значения путаются
            break;
        case 97: //  a) удаления всех четных элементов;
            cout << "a\n";
            break;
        case 27:
            cout << "Good bye\n";
            return 0;
            break;
        }
        Print_array(arr, size);
        cout << "\n\n\n";
        //system("sleep 4 && clear");
    }

    delete[] arr;
}
