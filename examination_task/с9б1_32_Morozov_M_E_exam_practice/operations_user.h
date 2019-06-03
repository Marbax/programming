#pragma once
#include <iostream>
#include <string.h>
#include "Users.h"

using namespace std;

void Add_user(Users *&user, int &users_count); // Добавление.

void Remove_user(Users *&user, int &users_count, int pos); // Удаление.

void Edit_user_fully(Users *&user, int &users_count, int pos); // Редактирование полное

void Edit_user_field(Users *&user, int &users_count, int pos); // Редактирование частичное

void Print_sort_user(Users *&user, int &users_count); // Поиск и сортировка по ФИО, количеству прочитанных книг, ID, номеру паспорта.

void Print_most_active_users(Users *&user, int &users_count); // Вывод информации на экран о самых активных читателях.

// Вывод информации о читателях с просроченной датой возврата книги, - в операциях по книге !
