#pragma once
#include <iostream>
#include <string.h>
#include "operations_user.h"
#include "Books.h"
#include "Users.h"

using namespace std;

void Add_book(Books *&book, unsigned int &books_count); //Добавление книги.

void Set_book(Books &book); // Описание книги

int Position_choose_book(const int books_count); // Выбор книги

void Remove_book(Books *&book, unsigned int &books_count); //Удаление книги.

void Edit_book(Books *&book, unsigned int &books_count); //Редактирование полное и частичное

void Print_book(Books book); // Вывод конекретной книги


int comp_auth_surname(const void *i, const void *j); // сравнение по ФАМИЛИИ автора для сортировки
int comp_title_book(const void *i, const void *j);   // сравнение по НАЗВАНИЮ книги для сортировки
int comp_genres(const void *i, const void *j);       // сравнение по ЖАНРУ книги для сортировки
int comp_owner(const void *i, const void *j);        // сравнение по ВЛАДЕЛЬЦУ книги для сортировки
int comp_popularity(const void *i, const void *j);   // сравнение по ПОПУЛЯРНОСТИ книги для сортировки
int comp_rating(const void *i, const void *j);       // сравнение по РЕЙТИНГУ книги для сортировки

void Print_sort_book(Books *&book, unsigned int &books_count); //Поиск и сортировка по автору, названию, жанру, популярности.

void Print_sort_book_by_genre(Books *&book, unsigned int &books_count); //Поиск по жанру, но сортировка по рейтингу.

void Print_book_by_owner(Books *&book, unsigned int &books_count); //Вывод информации о книгах находящихся на руках у читателей (сравнивает поле owner елси не Library значит на руках)

void Take_book(Books *&book, unsigned int &books_count, Users *&user, unsigned int &users_count); /* Выдача книги.(выбирает книгу , выбирает пользователя ,копирует ФИО юзера в овнера книги и меняет статус,
ставит дату взятия и сдачи)!! НУЖНО СДЕЛАТЬ ЮЗЕРА !! */

void Return_book(Books *&book, unsigned int &books_count, Users *&user, unsigned int &users_count); // Возврат книги.(возвращает Library в овнера книги)
// При возврате книги читателем, учитывать, что если есть просроченные дни, то выводить на экран сумму начисленной пени.

void Print_promiser(Books *&book, unsigned int &books_count, Users *&user, unsigned int &users_count); /* 
 Вывод информации о читателях с просроченной датой возврата книги,
 обязательно выводить при этом количество просроченных дней и начисленной пени.
 получает массив книг, если  return_date_* меньше текущей даты , то считать fine_days и fine_money и выводить владельца */

void Work_with_book(Books *&book, unsigned int &books_count); // Редактирование книги 3в1

void Book_info(Books *&book, unsigned int &books_count); // Информация о книге 3в1

void Save(Books *&book, unsigned int &books_count, Users *&user, unsigned int &users_count); // сохранение базы

void Load(Books *&book, unsigned int &books_count, Users *&user, unsigned int &users_count); // загрузка базы
