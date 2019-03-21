#include <iostream>
#include <ctime>
#include <iomanip> //форматирование вывода
using namespace std;
//меняет основную диагональ массива с побочной 
int main()
{
    srand(time(0));
    const int row = 5, col = 5;
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

            if (i + j == row - 1)
            {
                cout << setw(3) << arr[i][0 + i];
            }
            else if (i == j)
            {
                cout << setw(3) << arr[i][col - 1 - i];
            }
            else
            {
                cout << setw(3) << arr[i][j];
            }
        }
        cout << endl;
    }
}
