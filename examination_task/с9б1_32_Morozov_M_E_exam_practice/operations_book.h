#pragma once
#include <iostream>
#include <string.h>
#include "Books.h"
#include "Users.h"

using namespace std;

void Add_book(Books *&book, int &books_count); //Добавление книги.

void Set_book(Books &book); // Описание книги

void Remove_book(Books *&book, int &books_count, int pos); //Удаление книги.

void Edit_book(Books *&book, int &books_count, int pos); //Редактирование полное и частичное

void Print_sort_book(Books *&book, int &books_count); //Поиск и сортировка по автору, названию, жанру, популярности.

void Print_sort_book_by_genre(Books *&book, int &books_count); //Поиск по жанру, но сортировка по рейтингу.

void Print_book_by_owner(Books *&book, int &books_count); //Вывод информации о книгах находящихся на руках у читателей (сравнивает поле owner елси не Library значит на руках)

void Take_book(Books *&book, int &books_count, int pos); // Выдача книги.(копирует ФИО юзера в овнера книги)

void Return_book(Books *&book, int &books_count, int pos); // Возврат книги.(возвращает Library в овнера книги)
// При возврате книги читателем, учитывать, что если есть просроченные дни, то выводить на экран сумму начисленной пени.

void Print_promiser(Books *&book, int &books_count); /* 
 Вывод информации о читателях с просроченной датой возврата книги,
 обязательно выводить при этом количество просроченных дней и начисленной пени.
 получает массив книг, если  return_date_* меньше текущей даты , то считать fine_days и fine_money и выводить владельца */

void Save(Books *&book, int &books_count, Users *&user, int &users_count); // сохранение базы

void Load(Books *&book, int &books_count, Users *&user, int &users_count); // загрузка базы
