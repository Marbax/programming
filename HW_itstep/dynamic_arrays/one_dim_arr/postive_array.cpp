#include <iostream>
#include <ctime>
#include <iomanip> //форматирование вывода
using namespace std;

// 4. Программа должна создать два статических массива со случайными
// элементами из диапазона [-25;25], по 10 элементов в каждом массиве, вывести
// каждый массив на экран на отдельной строке. Затем программа должна создать
// динамический массив нужного размера и скопировать в него все
// положительные элементы из первых двух массивов. Вывести получившийся
// динамический массив на экран на отдельной строке.

void Fill_array(int *arr, int size)
{
    srand(time(0));
    int max = 25, min = -25;
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

int Counter(int *arr, int size)
{
    int n = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] >= 0)
        {
            n++;
        }
    }
    return n;
}

void Fill_dynamic_array(int *r_arr, int *f_arr, int *s_arr, int size)
{
    int j = 0;
    for (int i = 0; i < size; i++)
    {
        if (f_arr[i] >= 0)
        {
            r_arr[j] = f_arr[i];
            j++;
        }
    }
    for (int i = 0; i < size; i++)
    {
        if (s_arr[i] >= 0)
        {
            r_arr[j] = s_arr[i];
            j++;
        }
    }
}

int main()
{
    int f_arr[10]{};
    int s_arr[10]{};
    Fill_array(f_arr, 10);
    system("sleep 1");
    Fill_array(s_arr, 10);
    cout << "Starting arrays :\n";
    Print_array(f_arr, 10);
    Print_array(s_arr, 10);
    int size = Counter(f_arr, 10) + Counter(s_arr, 10);
    int *r_arr = new int[size];
    Fill_dynamic_array(r_arr, f_arr, s_arr, 10);
    cout << "\nDynamycaly created array from postive numbers of 2 another arrays :\n ";
    Print_array(r_arr, size);
    delete[] r_arr;
}
