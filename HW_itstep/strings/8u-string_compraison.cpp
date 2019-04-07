#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstring>
using namespace std;

// 2. Пользователь вводит две строки, которые сохраняются в динамические массивы.
// Необходимо сравнить их и вывести на экран сообщение, совпадает ли содержимое
// строк или нет.

int main()
{
    char buf[50];
    cout << "Enter first line ==> ";
    cin.getline(buf, 50);
    int len = strlen(buf) + 1;
    char *str1 = new char[len];
    strcpy(str1, buf);
    cout << "Enter second line ==> ";
    cin.getline(buf, 50);
    len = strlen(buf) + 1;
    char *str2 = new char[len];
    strcpy(str2, buf);
    system("clear");

    if ((strcmp(str1, str2) == 0))
    {
        cout << "Strings are comparaison\n\n";
    }
    else
    {
        cout << "Strings aren't compraison\n\n";
    }
    delete[] str1;
    delete[] str2;
}