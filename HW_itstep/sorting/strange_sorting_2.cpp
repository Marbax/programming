#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
void Func(int a[], int size)
{
    srand(time(NULL));
    //Создаем 2 переменные, которые будут хранить случайные индексы
    int x, y;
    //Создаем переменную в которой будет хранится элемент масива, который мы будем меснять местом
    int temp;
    //В цыкле мы делаем 20 перестановок
    for (int i = 0; i < 20; i++)
    {
        //генерируем случайные индексы
        x = rand() % size;
        y = rand() % size;
        //меняем местами элемент с индексом х и элемент с индексом у
        temp = a[x];
        a[x] = a[y];
        a[y] = temp;
    }
}
void selectSort1(int a[], int size)
{
    long i, k, j;
    int x;

    for (i = 0; i < size; i++)
    {
        k = i;
        x = a[i];
        for (j = i + 1; j < size; j++)
            if (a[j] > x)
            {
                k = j;
                x = a[j];
            }
        a[k] = a[i];
        a[i] = x;
    }
}
void selectSort2(int a[], int size)
{
    long i, k, j;
    int x;
    for (i = 0; i < size; i++)
    {
        k = i;
        x = a[i];
        for (j = i + 1; j < size; j++)
            if (a[j] < x)
            {
                k = j;
                x = a[j];
            }
        a[k] = a[i];
        a[i] = x;
    }
}
int main()
{
    int a[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    for (int i = 0; i < 20; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n\n";

    Func(a, 20);
    for (int j = 0; j < 20; j++)
    {
        cout << a[j] << " ";
    }
    cout << "\n\n";

    int size1 = 0;
    int size2 = 0;
    int j = 0;
    srand(time(NULL));
    j = rand() % 20;
    cout << j << "-e chislo " << a[j] << "\n\n";

    selectSort1(a, j);
    cout << "Sortirovka sleva: "
         << "\n";
    for (int y = 0; y < a[j]; y++)
    {
        cout << a[y] << " ";
    }
    cout << "\n\n";

    selectSort2(a, j);
    cout << "Sortirovka sprava: "
         << "\n";
    for (int x = j + 1; x < 20; x++)
    {
        cout << a[x] << " ";
    }
    cout << "\n\n";
}
