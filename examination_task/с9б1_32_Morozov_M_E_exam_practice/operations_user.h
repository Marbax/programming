#pragma once
#include <iostream>
#include <string.h>
#include "operations_book.h"
#include "Users.h"
#include "Books.h"

using namespace std;
int Position_choose_user(const int users_count); // Просит ввести позицию желаемого эллемента, пока не будет введен существующий

void Print_user(Users user); // Вывод конкретного пользователя

void Add_user(Users *&user, int &users_count); // Добавление.

void Set_user(Users &user); // Описание пользователя.

void Remove_user(Users *&user, int &users_count); // Удаление.

void Edit_user(Users *&user, int &users_count); // Редактирование полное и частичное

// !! IN PROGRESS !!

void Print_sort_user(Users *&user, int &users_count); // Поиск и сортировка по ФИО, количеству прочитанных книг, ID, номеру паспорта.

void Print_most_active_users(Users *&user, int &users_count); // Вывод информации на экран о самых активных читателях.

// Вывод информации о читателях с просроченной датой возврата книги, - в операциях по книге !
