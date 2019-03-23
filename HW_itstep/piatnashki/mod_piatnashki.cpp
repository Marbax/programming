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
short CurX, CurY;

//Создание игровой площадки

void Fill_Array(short Field[][4], short row, short col)
{
    short n = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            n++;
            Field[i][j] = n;
        }
    }
}

void Shuffle(short Field[][4], short row, short col)
{
    srand(time(0));
    int x, y;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            x = rand() % col;
            y = rand() % col;
            swap(Field[i][x], Field[i][y]);
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (Field[i][j] == 16)
            {
                Field[i][j] = 0;
                CurX = i;
                CurY = j;
            }
        }
    }
}

// Организация перемещений
void Move(Direction dir, short Field[][4])
{
    switch (dir)
    {
    case Up:
        if (CurY > 0)
        {
            swap(Field[CurY][CurX], Field[CurY - 1][CurX]);
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
            swap(Field[CurY][CurX], Field[CurY + 1][CurX]);
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
            swap(Field[CurY][CurX], Field[CurY][CurX + 1]);
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
            swap(Field[CurY][CurX], Field[CurY][CurX - 1]);
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
void Cout_Arr(short Field[][4], short row, short col)
{
    system("clear");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << setw(6) << Field[i][j];
        }
        cout << "\n\n";
    }
}

//Проверка на выигрыш
bool total(short Field[][4], short row, short col)
{
    short n = 0;
    bool flag = true;
    for (short i = 0; i < row; i++)
    {
        for (short j = 0; j < col; i++)
        {
            n++;
            if (Field[i][j] == n || Field[i][j] == n - 1)
                flag = true;
            else
            {
                flag = false;
                break;
            }
        }
    }
    return flag;
}

int main()
{
    const short row = 4, col = 4;
    short Field[row][col]{};
    Fill_Array(Field, row, col);
    Shuffle(Field, row, col);
    Cout_Arr(Field, row, col);
    cout << "Choose a direction 'w,a,s,d' or 'exit'/arrows for exit\n";
    while (!total(Field, row, col))
    {
        char key = getchar();
        switch (key)
        {
        case 119:
            Move(Up, Field);
            break;
        case 115:
            Move(Down, Field);
            break;
        case 100:
            Move(Right, Field);
            break;
        case 97:
            Move(Left, Field);
            break;
        case 27:
            cout << "Good bye\n";
            return 0;
            break;
        }
        Cout_Arr(Field, row, col);
    }
    cout << " ====Congratulations! Press Esc to exit====  ";
    return 0;
}
