// Условие задачи.
// Дан массив из 20 целых чисел со значениями от 1 до 20.
// Необходимо:
// написать функцию, разбрасывающую элементы массива произвольным образом;
// создать случайное число из того же диапазона и найти позицию этого случайного числа в массиве;
// отсортировать элементы массива, находящиеся слева от найденной позиции по убыванию,
// а элементы массива, находящиеся справа от найденной позиции по возрастанию.

// Важно!!!
// Для корректного отображения русских букв в консоли
// зайдите в свойства консоли(нажав на иконке консоли в левом верхнем углу окна)
// и установите шрифт Lucida Console

#include <iostream>
#include <iomanip>
#include <time.h>
#include <windows.h>
#ifdef max
#undef max
#endif

using namespace std;

// Направление сортировки
enum direction
{
    descending = -1,
    ascending = 1
};

void mix(int *const arr, const int arrLen);
void printArr(const char *const msg, const int *const arr, const int arrLen);
void sortSubrange(int *const arr, const int loIndex, const int hiIndex, const direction dir);

int main()
{
    // Необходимо для корректного отображения русских символов. См. прим. в шапке.
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // Исходный массив
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    // Длина массива
    const int arrLen = sizeof(arr) / sizeof(arr[0]);
    // Печатаем исходный
    printArr("Исходный массив:", arr, arrLen);
    // Перемешаем
    mix(arr, arrLen);
    // Печатаем перемешанный
    printArr("Перемешанный массив:", arr, arrLen);
    // Случайное число 1..20
    int num = (int)((double)rand() / (RAND_MAX + 1) * 20) + 1;
    cout << "Ищем элемент " << num << endl;
    int pos = -1;
    // Ищем позицию такого числа в массиве
    for (int i = 0; i < arrLen; i++)
        pos = arr[i] == num ? i : pos;
    cout << "Позиция:" << pos << endl;
    // Сортируем по убыванию
    sortSubrange(arr, 0, pos - 1, descending);
    // Сортируем по возрастанию
    sortSubrange(arr, pos + 1, arrLen - 1, ascending);
    // Результат
    printArr("Массив после сортировки:", arr, arrLen);
    system("PAUSE");
    return 0;
}

// Сортировка методом пузырька. Диапазон индексов loIndex..hiIndex включительно
void sortSubrange(int *const arr, const int loIndex, const int hiIndex, const direction dir)
{
    if (loIndex < hiIndex)
    {
        for (int i = 0; i < hiIndex - loIndex; i++)
            for (int j = loIndex; j < hiIndex - i; j++)
                if ((arr[j] - arr[j + 1]) * dir > 0)
                    swap(arr[j], arr[j + 1]);
    }
}

// Печать массива
void printArr(const char *const msg, const int *const arr, const int arrLen)
{
    cout << msg << endl;
    for (int i = 0; i < arrLen; i++)
        cout << setw(4) << arr[i] << ' ';
    cout << endl;
}

// Перемешивание массива
void mix(int *const arr, const int arrLen)
{
    srand((unsigned)time(0));
    if (arrLen > 1)
    {
        for (int i = 0; i < arrLen; ++i)
        {
            int from = (int)((double)rand() / (RAND_MAX + 1) * arrLen);
            int to = (int)((double)rand() / (RAND_MAX + 1) * arrLen);
            swap(arr[from], arr[to]);
        }
    };
};
