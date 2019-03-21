#include <iostream>
#include <ctime>
#include <iomanip> //форматирование вывода
using namespace std;
//меняет парные строки с непарными
int main()
{
    srand(time(0));
    const int row = 6, col = 6;
    int max = 10, min = 0;
    int arr[row][col]{};
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr[i][j] = rand() % (max - min) + min; // формула диапазона
            cout << setw(3) << arr[i][j];
        }
        cout << endl;
    }
    cout << "\nModified massive --> " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i % 2 == 0)
            {
                cout << setw(3) << arr[i + 1][j];
            }
            else
            {
                cout << setw(3) << arr[i - 1][j];
            }
        }
        cout << endl;
    }
}
