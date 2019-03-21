#include <stdio.h>
#include <iostream>
#include <iomanip> //форматирование вывода
#include <ctime>
using namespace std;

// Написать игру «Пятнашки». Программа должна содержать следующие функции:
// ➢ заполнение поля числами в случайном порядке;
// ➢ вывод поля на экран;
// ➢ поиск позиции нуля;
// ➢ перестановки элементов(Left, Right, Up, Down);
// ➢ проверки окончания игры.

typedef enum Direction
{
    Up,
    Down,
    Right,
    Left
} Direction;
short Field[4][4];
short CurX, CurY;

//Создание игровой площадки
void Create_Field()
{
    short arr[16], n, i, buf, k = 0, max = 17, min = 1;
    bool flag = false;
    srand(time(0));
    for (n = 0; n < 16;)
    {
        flag = false;
        buf = rand() % (max - min) + min; // формула диапазона
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

// Организация перемещений
void Move(Direction dir)
{
    switch (dir)
    {
    case Up:
        if (CurY > 0)
        {
            Field[CurY][CurX] = Field[CurY - 1][CurX];
            Field[CurY - 1][CurX] = 0;
            CurY--;
        }
        else
        {
            cout << "ERROR OUT FROM BEYOND THE PLAYING FIELD \n\n";
            system("sleep 1");
        }
        break;
    case Down:
        if (CurY < 3)
        {
            Field[CurY][CurX] = Field[CurY + 1][CurX];
            Field[CurY + 1][CurX] = 0;
            CurY++;
        }
        else
        {
            cout << "ERROR OUT FROM BEYOND THE PLAYING FIELD \n\n";
            system("sleep 1");
        }
        break;
    case Right:
        if (CurX < 3)
        {
            Field[CurY][CurX] = Field[CurY][CurX + 1];
            Field[CurY][CurX + 1] = 0;
            CurX++;
        }
        else
        {
            cout << "ERROR OUT FROM BEYOND THE PLAYING FIELD \n\n";
            system("sleep 1");
        }
        break;
    case Left:
        if (CurX > 0)
        {
            Field[CurY][CurX] = Field[CurY][CurX - 1];
            Field[CurY][CurX - 1] = 0;
            CurX--;
        }
        else
        {
            cout << "ERROR OUT FROM BEYOND THE PLAYING FIELD \n\n";
            system("sleep 1");
        }
        break;
    }
}

//ВЫВОД ПОЛЯ
void Cout_Arr()
{
    system("clear");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << setw(6) << Field[i][j];
        }
        cout << "\n\n";
    }
    //return;
}

//Проверка на выигрыш
bool total()
{
    short k = 1;
    bool flag = true;
    for (short i = 0; i < 4; i++)
    {
        for (short j = 0; j < 4; i++)
        {
            if (Field[i][j] != k % 16)
                flag = true;
            else
            {
                flag = false;
                break;
            }
            k++;
        }
    }
    return flag;
}

int main()
{
    Create_Field();
    Cout_Arr();
    cout << "Choose a direction 'w,a,s,d' or 'exit'/arrows for exit\n";
    while (!total())
    {
        char key = getchar();
        switch (key)
        {
        case 119:
            Move(Up);
            break;
        case 115:
            Move(Down);
            break;
        case 100:
            Move(Right);
            break;
        case 97:
            Move(Left);
            break;
        case 27:
            cout << "Good bye\n";
            return 0;
            break;
        }
        Cout_Arr();
    }
    cout << " ====Congratulations! Press Esc to exit====  ";
    return 0;
}
