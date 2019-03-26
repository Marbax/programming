#include <iostream>
#include <time.h>
using namespace std;

// 3. Программа должна создать два статических массива со случайными
// элементами из диапазона [0;10], по 10 элементов в каждом массиве,
// отсортировать эти массивы по возрастанию и вывести каждый массив на экран
// на отдельной строке. Затем программа должна создать динамический массив
// нужного размера и скопировать в него все элементы из первых двух массивов в
// неубывающем порядке(сортировать результирующий массив нельзя). Вывести
// получившийся динамический массив на экран на отдельной строке.

void Fill_array(int *arr, int size)
{
    srand(time(0));
    int max = 10, min = 0;
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % (max - min) + min;
    }
}

void Print_array(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Sort_Array(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = size - 1; j > i; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                swap(arr[j], arr[j - 1]); // своп меняет местами елеменеты
            }
        }
    }
}

void Fill_dinamyc_array(int *res, int *mas1, int *mas2, int size) // ПОХОДУ,ПРОЛЕТАЮТ ИНДЕКСЫ ,ИБО КОНЧАЮТСЯ ЭЛЛЕМЕНТЫ МАССИВА ,ПАААААЧИМУ????
{
    for (int i = 0, j = 0, n = 0; n < size; n++)
    {
        if (mas1[i] < mas2[j])
        {
            res[n] = mas1[i];
            i++;
        }
        else if (mas2[j] <= mas1[i])
        {
            res[n] = mas2[j];
            j++;
        }
        else if (mas2[j] == mas1[i])
        {
            res[n] = mas2[j];
            n++;
            j++;
            res[n] = mas1[i];
            i++;
        }
        else if (mas2[j] == 0 && mas1[i] == 0)
        {
            res[n] = 0;
            n++;
            j++;
            res[n] = 0;
            i++;
        }
    }
}

int main()
{
    int s_size = 10;
    int mas1[s_size]{};
    int mas2[s_size]{};
    Fill_array(mas1, s_size);
    system("sleep 1");
    Fill_array(mas2, s_size);
    Sort_Array(mas1, s_size);
    Sort_Array(mas2, s_size);
    Print_array(mas1, s_size);
    Print_array(mas2, s_size);
    int size = s_size * 2;
    int *res = new int[size];
    Fill_dinamyc_array(res, mas1, mas2, size);
    Print_array(res, size);
    delete[] res;
}
