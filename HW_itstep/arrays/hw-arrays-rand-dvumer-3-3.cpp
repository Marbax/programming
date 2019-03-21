#include <iostream>
#include <ctime>
#include <iomanip> //форматирование вывода
using namespace std;

int main()
{
    srand(time(0));
    const int row = 3, col = 4;
    int max = 4, min = 0;
    int arr[row][col]{};
    int count = 1;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr[i][j] = rand() % (max - min) + min; // формула диапазона
            if (arr[i][j] != 0)
            {
                count *= arr[i][j];
            }
            cout << setw(3) << arr[i][j];
        }
        cout << endl;
    }
    cout << "\nProduct of not zero numbers --> " << count << endl;
}
