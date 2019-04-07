#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstring>
using namespace std;

// 1. Пользователь вводит строку с клавиатуры в статический массив. Необходимо
// проверить, cколько элементов массива теперь занято и сколько свободно(элемент
// содержащий нуль символ считается занятым ).

int main() // кирилица считается вдвойне на линуксах ,приемлимое решение не найдено,нужно как то менять кодировку
{
    int size = 50;
    char buf[size];
    cout << "Enter line ==> ";
    cin.getline(buf, size);
    int len = strlen(buf) + 1;
    int empty = size - len;
    cout << "There is " << len << " symbols.";
    cout << "There is " << empty << " emty cells.";
}