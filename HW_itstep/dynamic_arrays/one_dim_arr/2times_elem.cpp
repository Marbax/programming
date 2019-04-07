#include <iostream>
#include <ctime>
#include <iomanip> //форматирование вывода
using namespace std;

// 6. Программа должна создать динамический массив из 20 случайных
// элементов из диапазона [1;9] и вывести его на экран. Далее программа должна
// скопировать во второй динамический массив только те элементы, которые в
// первом массиве встретились ровно 2 раза (если такие будут) и вывести второй
// массив на экран на отдельной строке.

void Fill_array(int *arr, int size)
{
    srand(time(0));
    int max = 9, min = 1;
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % (max - min) + min;
    }
}

void Print_array(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << setw(3) << arr[i] << " ";
    }
    cout << endl;
}

int Counter(int *f_arr, int size)
{
    int n = 0;
    for (int i = 0; i < size; i++)
    {
        int k = 0;
        for (int j = 0; j < size; j++)
        {
            if (f_arr[i] == f_arr[j])
            {
                k++;
            }
        }
        if (k == 2)
        {
            for (int l = i - 1; l >= 0; l--)
            {
                if (f_arr[i] == f_arr[l])
                {
                    k++;
                }
            }
            if (k == 2)
            {
                n++;
            }
        }
    }
    return n;
}

void Fill_dynamic_array(int *r_arr, int *f_arr, int size)
{
    int n = 0;
    for (int i = 0; i < size; i++)
    {
        int k = 0;
        for (int j = 0; j < size; j++)
        {
            if (f_arr[i] == f_arr[j])
            {
                k++;
            }
        }
        if (k == 2)
        {
            for (int l = i - 1; l >= 0; l--)
            {
                if (f_arr[i] == f_arr[l])
                {
                    k++;
                }
            }
            if (k == 2)
            {
                r_arr[n] = f_arr[i];
                n++;
            }
        }
    }
}

int main()
{
    int static_size = 20;
    int f_arr[static_size]{};
    Fill_array(f_arr, static_size);
    cout << "Starting array :\n";
    Print_array(f_arr, static_size);
    int size = Counter(f_arr, static_size);
    int *r_arr = new int[size];
    Fill_dynamic_array(r_arr, f_arr, static_size);
    cout << "\nDynamycaly created array from elements that occur only twice :\n ";
    Print_array(r_arr, size);
    delete[] r_arr;
}
