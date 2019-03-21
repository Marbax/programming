
#include <iostream>
#include <ctime>
#include <iomanip> //форматирование вывода
using namespace std;

int main()
{
    srand(time(0));
    const int row = 3, col = 4;
    int max = 10, min = -20;
    int arr[row][col]{};
    int count = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr[i][j] = rand() % (max - min) + min; // формула диапазона

            if (arr[i][j] < 0)
            {
                count++;
            }

            cout << setw(5) << arr[i][j];
        }
        cout << endl;
    }
    cout << "\nAmmount of negative numbers = " << count << endl;
}
