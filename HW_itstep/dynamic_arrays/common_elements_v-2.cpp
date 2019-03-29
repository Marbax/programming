#include <iostream>
#include <ctime>
#include <iomanip> //форматирование вывода
using namespace std;

// 5. Программа должна создать два статических массива со случайными
// элементами из диапазона [5;20], по 10 элементов в каждом массиве, вывести
// каждый массив на экран на отдельной строке. Затем программа должна создать
// динамический массив нужного размера и скопировать в него все общие
// элементы из первых двух массивов(без повторений). Вывести получившийся
// динамический массив на экран на отдельной строке.

void Fill_array(int *arr, int size)
{
    srand(time(0));
    int max = 20, min = 5;
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

int Counter(int *f_arr, int *s_arr, int size)
{
    int n = 0;
    for (int i = 0; i < size; i++)
    {
        bool k = true;
        for (int j = 0; j < size; j++)
        {
            if (f_arr[i] == s_arr[j] && k)
            {
                for (int l = i - 1; l >= 0; l--)
                {
                    if (f_arr[i] == f_arr[l])
                    {
                        k = false;
                    }
                }
                if (k)
                {
                    n++;
                    k = false;
                }
            }
        }
    }
    return n;
}

void Fill_dynamic_array(int *r_arr, int *f_arr, int *s_arr, int size)
{
    int n = 0;
    for (int i = 0; i < size; i++)
    {
        bool k = true;
        for (int j = 0; j < size; j++)
        {
            if (f_arr[i] == s_arr[j] && k)
            {
                for (int l = i - 1; l >= 0; l--)
                {
                    if (f_arr[i] == f_arr[l])
                    {
                        k = false;
                    }
                }
                if (k)
                {
                    r_arr[n] = f_arr[i];
                    n++;
                    k = false;
                }
            }
        }
    }
}

int main()
{
    int static_size = 10;
    int f_arr[static_size]{};
    int s_arr[static_size]{};
    Fill_array(f_arr, static_size);
    system("sleep 1");
    Fill_array(s_arr, static_size);
    cout << "Starting arrays :\n";
    Print_array(f_arr, static_size);
    Print_array(s_arr, static_size);
    int size = Counter(f_arr, s_arr, static_size);
    int *r_arr = new int[size];
    Fill_dynamic_array(r_arr, f_arr, s_arr, static_size);
    cout << "\nDynamycaly created array from common ellements of 2 another arrays :\n ";
    Print_array(r_arr, size);
    delete[] r_arr;
}
