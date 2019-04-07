#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstring>
using namespace std;

// Написать программу, в которой пользователь вводит строку текста, слово, которое он хочет
// заменить в этой строке(word_1) и слово для замены(word_2). Каждая из введенных строк должна
// сохраняться в отдельном динамическом массиве. Произвести замену всех слов word_1 на word_2 и
// вывести результат на экран.

int main()
{
    char buf[50];
    cout << "Enter a line ==> ";
    cin.getline(buf, 100);
    int len = strlen(buf) + 1;
    char *str1 = new char[len];
    strcpy(str1, buf);
    cout << "Enter a word which you wont to change ==> ";
    cin.getline(buf, 20);
    len = strlen(buf) + 1;
    char *word_1 = new char[len];
    strcpy(word_1, buf);
    cout << "Enter a word on which replace ==> ";
    cin.getline(buf, 20);
    len = strlen(buf) + 1;
    char *word_2 = new char[len];
    strcpy(word_2, buf);
    //system("clear");

    // НЕ РОБИТ ДАЛЬШЕ

    strcpy(strstr(str1, word_1), word_2);// до первого вхождения работает,дальше забивает
    cout << "Result is ==> " << str1;
    

    delete[] str1;
    delete[] word_1;
    delete[] word_2;
}