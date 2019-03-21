#include <iostream>
using namespace std;
// 1. Написать шаблон функции для поиска среднего арифметического значений
// массива.
template <typename T>
T Arifmet(T arr[], int size)
{
    T res = 0;
    int n = 0;
    for (int i = 0; i < size; i++)
    {
        res += arr[i];
        n++;
    }
    res /= n;
    return res;
}
int main()
{
    const int size = 10;
    int arr[size] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
    cout << Arifmet(arr, size) << endl;
}
