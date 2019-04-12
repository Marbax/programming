#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;

// 3. Написать программу, в которой создается двумерный динамический массив.
// Количество строк задает пользователь. Количество столбцов генерируется
// случайным образом(для каждой строки) в диапазоне от 5 до 10 элементов.
// Заполнить массив случайными числами в диапазоне [0,100] и вывести его на
// экран. Найти номер строки, сумма элементов которой является максимальной.

void Fill_array(int **arr, int max, int min, int row, int *col)
{
    srand(time(0));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col[i]; j++)
        {
            arr[i][j] = rand() % (max - min) + min;
        }
    }
}

void Print_array(int **arr, int row, int *col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col[i]; j++)
        {
            cout << setw(3) << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int Counter_of_max(int **arr, int row, int *col)
{
    int counter = 0, index = 0;
    for (int i = 0; i < row; i++)
    {
        int old_counter = 0;
        for (int j = 0; j < col[i]; j++)
        {
            old_counter += arr[i][j];
        }
        if (old_counter > counter)
        {
            counter = old_counter;
            index = i;
        }
    }
    return index;
}

int main()
{
    int row = 0, max_col = 10, min_col = 5;
    int max = 100, min = 0;
    int b_line = 0;
    int *col = new int[row];
    char key;
    cout << "Enter number of rows ==> ";
    cin >> row;
    system("clear");
    int **arr = new int *[row];
    for (int i = 0; i < row; i++)
    {
        col[i] = rand() % (max_col - min_col) + min_col;
        arr[i] = new int[col[i]];
    }
    Fill_array(arr, max, min, row, col);
    Print_array(arr, row, col);

    b_line = Counter_of_max(arr, row, col);
    cout << "\nNumber of the line with biggest sum of ellements is : " << b_line;
    for (int i = 0; i < row; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}
