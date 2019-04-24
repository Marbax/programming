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

int Word_count(char *&arr, int &size, char *word_1, char *word_2) // считает кол-во повторяющихся слов (с созданием временного массива ,ибо strtok ломает текущий массив )
{
    char *tmp = new char[size];

    for (int i = 0; i < size; i++)
    {
        tmp[i] = arr[i];
    }
    int count = 0;
    char *pt = strtok(tmp, " ");

    if (strstr(pt, word_1) != 0)
    {
        count++;
    }
    while (pt)
    {
        if (strstr(pt, word_1) != 0)
        {
            count++;
        }
        pt = strtok(NULL, " ");
    }
    delete[] tmp;

    return count;
}

void Array_resizing(char *&arr, int &size, char *word_1, char *word_2, int c_word) // меняет размер массива учитывая разницу в кол-ве символов заменяемых слов
{
    int plus_size = (strlen(word_2) - strlen(word_1));
    size += plus_size * c_word;
    char *tmp = new char[size];
    for (int i = 0; i < size; i++)
    {
        tmp[i] = arr[i];
    }
    delete[] arr;
    arr = tmp;
}

void Arr_remake(char *&arr, int &size, char *word_1, char *word_2) // пересоздает массив с замененными словами
{
    char *tmp = new char[size];

    for (int i = 0; i < size; i++)
    {
        tmp[i] = arr[i];
    }

    char *pt = strtok(arr, " ");
    if (strstr(pt, word_1) != 0)
    {
        strcat(strcpy(tmp, word_2), " ");
        pt = strtok(NULL, " ");
    }
    else
    {
        strcat(strcpy(tmp, pt), " ");
        pt = strtok(NULL, " ");
    }
    while (pt)
    {
        if (strstr(pt, word_1) != 0)
        {
            strcat(strcat(tmp, word_2), " ");
        }
        else
        {
            strcat(strcat(tmp, pt), " ");
        }

        pt = strtok(NULL, " ");
    }
    delete[] arr;

    arr = tmp;
}

int main()
{
    char buf[100];
    cout << "Enter a line ==> ";
    cin.getline(buf, 100);
    int s_len = strlen(buf) + 1;
    char *str1 = new char[s_len];
    strcpy(str1, buf);
    cout << "Enter a word which you wont to change ==> ";
    cin.getline(buf, 20);
    int w1_len = strlen(buf) + 1;
    char *word_1 = new char[w1_len];
    strcpy(word_1, buf);
    cout << "Enter a word on which replace ==> ";
    cin.getline(buf, 20);
    int w2_len = strlen(buf) + 1;
    char *word_2 = new char[w2_len];
    strcpy(word_2, buf);
    //system("clear");
    int c_word = Word_count(str1, s_len, word_1, word_2);
    Array_resizing(str1, s_len, word_1, word_2, c_word);
    Arr_remake(str1, s_len, word_1, word_2);
    cout << "\n\nChanged string now is ==> " << str1;

    delete[] str1;
    delete[] word_1;
    delete[] word_2;
}
