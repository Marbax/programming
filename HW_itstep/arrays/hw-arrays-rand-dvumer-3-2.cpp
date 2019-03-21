#include <iostream>
#include <ctime>
#include <iomanip> //форматирование вывода
using namespace std;

int main()
{
    srand(time(0));
    const int row = 6, col = 6;
    int max = 10, min = 0;
    int arr[row][col]{}, brr[row]{};
    for (int i = 0; i < row; i++)
    {
        brr[i] = rand() % (max - min) + min;
        for (int j = 0; j < col; j++)
        {
            arr[i][j] = rand() % (max - min) + min; // формула диапазона

            cout << setw(3) << arr[i][j];
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < row; i++)
    {
        cout << setw(3) << brr[i];
    }
    cout << "\n\n Modified massive :" << endl;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i % 2 != 0)
            {
                arr[i][j] = brr[j];
            }
            cout << setw(3) << arr[i][j];
        }
        cout << endl;
    }
}
