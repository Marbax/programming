#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstring>
using namespace std;

// 4. Пользователь вводит фамилию, имя и отчество в отдельные динамические массивы.
// Программа должна создать массив «fio» и записать в него фамилию, имя и отчество
// через пробел.

int main()
{
    char buf[50];
    cout << "Enter a name ==> ";
    cin.getline(buf, 50);
    int len = strlen(buf) + 1;
    int a_len = len;
    char *str1 = new char[len];
    strcpy(str1, buf);
    cout << "Enter a surname ==> ";
    cin.getline(buf, 50);
    len = strlen(buf) + 1;
    a_len += len;
    char *str2 = new char[len];
    strcpy(str2, buf);
    cout << "Enter a middle name ==> ";
    cin.getline(buf, 50);
    len = strlen(buf) + 1;
    a_len += len;
    char *str3 = new char[len];
    strcpy(str3, buf);
    char *str4 = new char[a_len];
    strcpy(str4, str2);
    strcat(str4, " ");
    strcat(str4, str1);
    strcat(str4, " ");
    strcat(str4, str3);
    system("clear");
    cout << "Full name is ==> " << str4;
    delete[] str1;
    delete[] str2;
    delete[] str3;
    delete[] str4;
}