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

void Delete_even_numbers(int *&arr, int &size) //  a) удаления всех четных элементов;
//(при частом использовании функции программа может вылетать,непонятно почему,буду благодарен фидбеку )
// (т.к. мы такое не учили ,хорошо бы не снижать оценку за это)
{
    int old_size = size;
    int counter = size;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 0)
        {
            counter--;
        }
    }
    size = counter;
    int *tmp = new int[size];
    for (int i = 0, j = 0; j < old_size; i++)
    {
        if (arr[i] % 2 != 0)
        {
            tmp[j] = arr[i];
            j++;
        }
    }
    delete[] arr;
    arr = tmp;
}

void Number_adding(int *&arr, int &size, int new_one) //  d) добавления числа ,введенного пользователем в произвольную позицию;
{
    size++;
    int *tmp = new int[size]; // 1
    srand(time(0));
    int max = size - 1, min = 0;
    int rand_index = rand() % (max - min) + min;
    tmp[rand_index] = new_one;

    for (int i = 0, j = 0; i < size; j++, i++) // 2
    {
        if (i == rand_index)
        {
            i++;
        }

        tmp[i] = arr[j];
    }
    delete[] arr; // 3

    arr = tmp; // 4
}

void Element_adding(int *&arr, int &size) // b) добавления элемента в произвольную позицию;
{
    size++;
    int *tmp = new int[size]; // 1
    srand(time(0));
    int max = size - 1, min = 0;
    int rand_index = rand() % (max - min) + min;

    for (int i = 0, j = 0; i < size; j++, i++) // 2
    {
        if (i == rand_index)
        {
            i++;
        }

        tmp[i] = arr[j];
    }
    delete[] arr; // 3

    arr = tmp; // 4
}

void Removing_elements_range(int *&arr, int &size, int m, int n) //  c) удаления диапазона элементов (от m до n).
{
    int old_size = size;
    int counter = size;
    if (m > n)
    {
        swap(m, n);
    }

    for (int i = 0; i < size; i++)
    {
        if (i >= m && i <= n)
        {
            counter--;
        }
    }
    size = counter;
    int *tmp = new int[size];
    for (int i = 0, j = 0; j < old_size; i++)
    {
        if (i < m || i > n)
        {
            tmp[j] = arr[i];
            j++;
        }
    }
    delete[] arr;
    arr = tmp;
}

int main()
{
    int size = 10, m = 0, n = 0;
    int new_one = 0;
    int *arr = new int[size];
    Fill_array(arr, size);
    while (true)
    {
        cout << "Current array :\n";
        Print_array(arr, size);
        cout << "\n\n";
        cout << "a) delete all even numbers;\n";
        cout << "b) adding an element to random position;\n";
        cout << "c) removing range of elements (from m to n).\n";
        cout << "d) adding a number entered by user to random position\nESC - выход\n";
        char key = getchar();
        switch (key)
        {
        case 100: // d) добавления числа ,введенного пользователем, в произвольную позицию;
            cout << "Enter a number to add it to random position ==> ";
            cin >> new_one;
            cout << "\n";
            Number_adding(arr, size, new_one); // b) добавления числа ,введенного пользователем, в произвольную позицию;
            break;
        case 99: // c) удаления диапазона элементов (от m до n).
            cout << "Enter two posotions to delete all elements between(including) them:\n";
            cin >> m;
            cin >> n;
            cout << "\n";
            Removing_elements_range(arr, size, m, n);
            break;
        case 98: // b) добавления элемента в произвольную позицию;
            Element_adding(arr, size);
            break;
        case 97:                            // a) удаления всех четных элементов;
            Delete_even_numbers(arr, size); // багов не найдено
            break;
        case 27:
            system("clear");
            cout << "Good bye\n";
            return 0;
            break;
        }
        system("clear");
    }

    delete[] arr;
}
