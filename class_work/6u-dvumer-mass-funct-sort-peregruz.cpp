#include <iostream>
using namespace std;
/*  Классы памяти - определяют время жизни и область видимости переменной 
4 вида :
1. auto область видимости локальная ,время жизни временно (*неиспользуется !!!)
2. static область видимости локальна,время жизни постоянно 
3. extern область видимости глобальна, время жизни постоянно 
4. register область видимости локальна, время жизни временно , (рекомендация)

auto - способ создания переменных ,сам определяет и понимает тип данных для переменной , нужно сразу инициализировать переменную
decltype - способ создания переменных , создает переменные по типу другой переменной decltype (a)b
 */

//----------------------------------------------------------------------------------------
// Dmurn massiv
/* 
void fill_array(int arr[][4], int row, int col) //второй параметр в определении массива ОБЯЗАТЕЛЕН(чтобы мог понять 
// когда переходить на новую строчку,переменную ставить нельзя ,только литерал )
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr[i][j] = rand() % 10;
        }
    }
}
void print_array(int arr[][4], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int const row = 3, col = 4;
    int arr[row][col];
    fill_array(arr, row, col);
    print_array(arr, row, col);
}
 */
//----------------------------------------------------------------------------------------
// max element
/* 
void fill_array(int arr[][4], int row, int col) //второй параметр в определении массива ОБЯЗАТЕЛЕН(чтобы мог понять когда 
// переходить на новую строчку,переменную ставить нельзя ,только литерал )
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr[i][j] = rand() % 10;
        }
    }
}
void print_array(int arr[][4], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int max_elem(int arr[][4], int row, int col)
{
    int max = arr[0][0];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] > max)
            {
                max = arr[i][j];
            }
        }
    }
    return max;
}

int main()
{
    int const row = 3, col = 4;
    int arr[row][col];
    fill_array(arr, row, col);
    print_array(arr, row, col);
    cout << "\nMax is ==> " << max_elem(arr, row, col);
}
 */
//----------------------------------------------------------------------------------------
// Сортировка
// Пузырьковая bubblesort  самая простая и самая НЕеффективная
/* 
void bubblesort(int arr[], int size)
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
 */
//----------------------------------------------------------------------------------------
// Сортировка выбором selectsort совсем немного быстрее чем бабл ,тоже n квадрат
/* 
void sellectsort(int arrp[],int size)
{

}
 */
//----------------------------------------------------------------------------------------
// Сортировка вставкой insertsort , самая эффективная из n квадрат
/* 
void insertsort(int arrp[],int size)
{

}
 */
//----------------------------------------------------------------------------------------
// Быстрая сортировка quicksort , она быстрая и рекурсивная
/* 
void quicksort(int arrp[], int size)
{
}
 */
//----------------------------------------------------------------------------------------
// Перегрузка ф-й и шаблоны ф-й
// Перегрузка (не перезагрузка) - создавать несколько ф-й с одним именем, перегружать можно по типу кол-ву или  порядку принимаемым параметрам
/* 
int Sum(int a, int b)
{
    return a + b;
}
double Sum(double a, double b)
{
    return a + b;
}
float Sum(float a, float b)
{
    return a + b;
}
double Sum(double a, int b)
{
    return a + b;
}

int main()
{
    cout << Sum(5.4, 5);
}
 */
//----------------------------------------------------------------------------------------
// Шаблон - позволяет написать одну ф-ю для разных типов
/* 
template <typename T1, typename T2>
//T1 Sum(T1 a, T2 b) //от первого типа зависит тип возвращаемого значения
auto Sum(T1 a, T2 b)
{
    return a + b;
}

template <typename T>
T my_rand()
{
    return rand() % 100 / 10.;
}

int main()
{
    srand(time(0));
    cout << Sum(12, 23) << endl;
    cout << Sum(1.2, 2.3) << endl;
    cout << Sum(12, 2.3) << endl;
    cout << Sum(1.2, 23) << endl;
    cout << Sum('h', 2.1) << endl;
    cout << Sum(2.1, 'h') << endl;
    cout << my_rand<int>() << endl;
    cout << my_rand<double>() << endl;
}
 */
//----------------------------------------------------------------------------------------
//ф-я которая умеет суммировать все еллементы массива неависимо от типа

template <typename T>
T Mass_sum(T arr, int size)
{
    T sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main()
{
    int const size = 10;
    int arr1[size]{12, 34, 23, 45, 23, 45, 67, 34, 23, 54};
    double arr2[size]{1.2, 3.4, 2.3, 4.5, 2.3, 4.5, 6.7, 3.4, 2.3, 5.4};
    cout << Mass_sum(arr1, size) << endl;
    cout << Mass_sum(arr2, size) << endl;
}

//----------------------------------------------------------------------------------------
