#include <iostream>
#include <ctime>
#include <iomanip> //форматирование вывода
using namespace std;

// 2. Дан массив из 20 целых чисел со значениями от 1 до 20.
//      Необходимо:
// a) написать функцию, разбрасывающую элементы массива произвольным
// образом;
// b) создать случайное число из того же диапазона и найти позицию этого
// случайного числа в массиве;
// c) отсортировать элементы массива, находящиеся слева от найденной позиции
// по убыванию, а элементы массива, находящиеся справа от найденной
// позиции по возрастанию.

void Fill_Array(int arr[], int size)
{
    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        arr[i] = i + 1;
    }
}
void Shuffle(int arr[], int size)
{
    srand(time(0));
    int x, y;
    for (int i = 0; i < size; i++)
    {
        x = rand() % size;
        y = rand() % size;
        swap(arr[x], arr[y]);
    }
}
int Find_index(int arr[], int size, int num)
{
    int index = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == num)
        {
            index = i;
        }
    }
    return index;
}

void Sort_Array(int arr[], int size, int index)
{
    for (int i = index + 1; i < size; i++)
    {
        for (int j = size - 1; j > i; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                swap(arr[j], arr[j - 1]); // своп меняет местами елеменеты
            }
        }
    }
    for (int i = 0; i < index - 1; i++)
    {
        for (int j = index - 1; j > i; j--)
        {
            if (arr[j] > arr[j - 1])
            {
                swap(arr[j], arr[j - 1]); // своп меняет местами елеменеты
            }
        }
    }
}

void Print_Array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << setw(5) << arr[i];
    }
    cout << endl;
}

int main()
{
    const int size = 20;
    int index, num;
    int arr[size]{};
    Fill_Array(arr, size);
    Shuffle(arr, size);
    Print_Array(arr, size);
    cout << "\n\nEnter an number from which sort ==> ";
    cin >> num;
    cout << "\n";
    index = Find_index(arr, size, num);
    cout << "\nSorted array :" << endl;
    Sort_Array(arr, size, index);
    Print_Array(arr, size);
}
