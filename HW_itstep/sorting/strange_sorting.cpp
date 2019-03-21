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
    int max = 20, min = 1;
    for (int i = 0; i < size; i++)
    {
        arr[i] = i+1; // формула диапазона
    }
}
void Shuffle(int arr[], int size)
{
    srand(time(0));
    int x, y;
    int temp;
    for (int i = 0; i < size; i++)
    {
        x = rand() % size;
        y = rand() % size;
        temp = arr[x];
        arr[x] = arr[y];
        arr[y] = temp;
    }
}
int Find_index(int arr[], int size)
{
    int min_min = arr[0], min_index = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            if (arr[i] < min_min)
            {
                min_min = arr[i];
                min_index = i;
            }
        }
    }
    return min_index;
}

void Sorted_Array(int arr[], int size, int min_index, int max_index)
{
    int start, end;
    (min_index < max_index) ? start = min_index : start = max_index;
    (min_index < max_index) ? end = max_index : end = min_index;
    cout << "\n\nSorted array\n";
    for (int i = start; i < end; i++)
    {
        for (int j = end - 1; j > i; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                swap(arr[j], arr[j - 1]); // своп меняет местами елеменеты
            }
        }
        cout << setw(5) << arr[i];
    }
}

void Print_Array(int arr[], int size)
{
    cout << "\nDeffault array\n";
    for (int i = 0; i < size; i++)
    {
        cout << setw(5) << arr[i];
    }
}

int main()
{
    const int size = 20;
    int num;
    int arr[size]{};
    Fill_Array(arr, size);
    Shuffle(arr,size);
    Print_Array(arr, size);
    cout<<"Enter an number from which sort ==> ";
    cin>> num;
    cout << "\n\n";
    //Sliced_Array(arr, size, min_index, max_index);
    //Sort_minimum(arr, size, min_index, max_index);
}
