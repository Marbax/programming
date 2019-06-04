#pragma once
#include "operations_user.h"

using namespace std;

int Position_choose_user(const int users_count) // Просит ввести позицию желаемого эллемента, пока не будет введен существующий
{
    int pos = NULL, tmp = NULL;
    cout << "\nEnter id of the user ==> ";
    cin >> tmp;
    cin.ignore();
    cout << endl;
    while (tmp < 0 || tmp >= users_count)
    {
        system("clear");
        cout << "\n\t\tError! Wrong id !\nEnter id of the user ==> ";
        cin >> tmp;
        cin.ignore();
    }
    pos = tmp;
    return pos;
}
void Add_user(Users *&user, int &users_count); // Добавление.

void Remove_user(Users *&user, int &users_count, int pos); // Удаление.

void Edit_user(Users *&user, int &users_count, int pos); // Редактирование полное и частичное

void Print_sort_user(Users *&user, int &users_count); // Поиск и сортировка по ФИО, количеству прочитанных книг, ID, номеру паспорта.

void Print_most_active_users(Users *&user, int &users_count); // Вывод информации на экран о самых активных читателях.

// Вывод информации о читателях с просроченной датой возврата книги, - в операциях по книге !
