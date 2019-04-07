#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstring>
using namespace std;

// 3. Пользователь вводит предложение и слово, а программа сообщает, есть ли такое слово
// в предложении или нет.

int main()
{
    char buf[50];
    cout << "Enter a line ==> ";
    cin.getline(buf, 50);
    int len = strlen(buf) + 1;
    char *str1 = new char[len];
    strcpy(str1, buf);
    cout << "Enter a word ==> ";
    cin.getline(buf, 50);
    len = strlen(buf) + 1;
    char *str2 = new char[len];
    strcpy(str2, buf);
    system("clear");

    if ((strstr(str1, str2) != 0))
    {
        cout << "The string contains the word\n\n";
    }
    else
    {
        cout << "The string isn't contains the word\n\n";
    }
    delete[] str1;
    delete[] str2;
}