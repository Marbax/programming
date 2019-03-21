#include <stdio.h>
#include <iostream>
#include <ctime>
#include <iomanip> //форматирование вывода
using namespace std;

// Написать игру «Пятнашки». Программа должна содержать следующие функции:
// ➢ заполнение поля числами в случайном порядке;
// ➢ вывод поля на экран;
// ➢ поиск позиции нуля;
// ➢ перестановки элементов(Left, Right, Up, Down);
// ➢ проверки окончания игры.

//Создание игровой площадки
void Create_array(short arr[][4], short row, short col)
{
    srand(time(0));
    short max = 17, min = 0;

    for (short i = 0; i < row; i++)
    {
        for (short j = 0; j < col; j++)
        {
            arr[i][j] = rand() % (max - min) + min; // формула диапазона
        }
    }
}

void Create_Field(short arr[][4], short row, short col)
{
    short n = row * col, arr[n], i, buf, k = 0;
    bool flag = false;
    srand(time(NULL));
    for (n = 0; n < 16;)
    {
        flag = false;
        buf = rand() % n + 1;
        for (i = 0; i < n; i++)
        {
            if (arr[i] == buf)
            {
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            arr[n] = buf;
            n++;
        }
    }
    for (n = 0; n < 4; n++)
    {
        for (i = 0; i < 4; i++)
        {
            Field[n][i] = arr[k];
            k++;
        }
    }
    Field[3][3] = 0;
    CurX = 3;
    CurY = 3;
    return;
}
//ВЫВОД ПОЛЯ
void Print_array(short arr[][4], short row, short col)
{
    for (short i = 0; i < row; i++)
    {
        for (short j = 0; j < col; j++)
        {
            cout << setw(3) << arr[i][j] << " ";
        }
        cout << endl;
    }
}

//Проверка на выигрыш

int main()
{
    short const row = 3, col = 4;
    short arr[row][col];
    Create_array(arr, row, col);
    Print_array(arr, row, col);
    /*     printf("Choose a direction 'w,a,s,d'\n");
    while (!total())
    {
        char key = getchar();
        switch (key)
        {
        case 119:
            Move(up);
            break;
        case 115:
            Move(down);
            break;
        case 100:
            Move(right);
            break;
        case 97:
            Move(left);
            break;
        case 27:
            cout << "NICE TRY\n";
            return 0;
            break;
        }
        coutArr();
    }
    cout << " ====Congratulations! Press Esc to exit====  ";
    return 0; */
}
