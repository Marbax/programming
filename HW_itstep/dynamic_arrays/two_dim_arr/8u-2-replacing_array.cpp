#include <iostream>
#include <time.h>
#include <iomanip> //форматирование вывода
using namespace std;

// 2. Написать программу, в которой создается двумерный динамический массив.
// Количество строк и столбцов задает пользователь. Массив заполняется
// случайными числами в диапазоне [3,12].
// Задание:
// a. Поменять местами четные и нечетные строки;
// b. Поменять местами четные и нечетные столбцы.

void Fill_array(int **arr, int max, int min, int row, int col)
{
    srand(time(0));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr[i][j] = rand() % (max - min) + min;
        }
    }
}

void Print_array(int **arr, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << setw(3) << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void Collums_replace(int **arr, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (j % 2 == 0 && j < col - 1)
            {
                swap(arr[i][j], arr[i][j + 1]);
            }
        }
    }
}

void Rows_replace(int **arr, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i % 2 == 0 && i < row - 1)
            {
                swap(arr[i][j], arr[i + 1][j]);
            }
        }
    }
}

int main()
{
    int row = 0, col = 0;
    int max = 12, min = 3;
    char key;
    cout << "Enter number of rows ==> ";
    cin >> row;
    cout << "\nAnd numuber of collums ==> ";
    cin >> col;
    system("clear");
    int **arr = new int *[row];
    for (int i = 0; i < row; i++)
    {
        arr[i] = new int[col];
    }
    Fill_array(arr, max, min, row, col);
    while (true)
    {
        Print_array(arr, row, col);
        cout << "\na) replace even rows with not even\n";
        cout << "b) replace even collums with not even\nESC - выход\n";
        cin >> key;
        switch (key)
        {
        case 98:
            Collums_replace(arr, row, col);
            break;
        case 97:
            Rows_replace(arr, row, col);
            break;
        case 27:
            system("clear");
            cout << "Good bye\n";
            return 0;
            break;
        }
    }
    for (int i = 0; i < row; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}
