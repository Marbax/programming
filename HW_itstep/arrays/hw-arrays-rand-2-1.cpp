#include <iostream>
#include <ctime> // библиотека времени
using namespace std;

int main()
{
    srand(time(0)); // установить от чего будет отталкиваться рандом (от времени)
    const int size = 10;
    int max = 6, min = -5;
    int arr[size]{};
    int x;
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % (max - min) + min; // формула диапазона
        cout << arr[i] << " ";
    }
    cout << "\n\nReversed massive : " << endl;
    for (int i = size - 1; i >= 0; i--)
    {
        arr[i];
        cout << arr[i] << " ";
    }
}
