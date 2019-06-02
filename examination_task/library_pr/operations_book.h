#pragma once

// ПЕНЯ !!! При возврате книги читателем, учитывать, что если есть просроченные дни, то выводить на экран сумму начисленной пени.

void Add_book(Books *&book, int &books_count); //Добавление.

void Remove_book(Books *&book, int &books_count, int pos); //Удаление.

void Edit_book_fully(Books *&book, int &books_count, int pos); //Редактирование полное

void Edit_book_field(Books *&book, int &books_count, int pos); //Редактирование частичное

void Print_sort_book(Books *&book, int &books_count); //Поиск и сортировка по автору, названию, жанру, популярности.

void Print_sort_book_by_genre(Books *&book, int &books_count); //Поиск по жанру, но сортировка по рейтингу.

void Print_book_by_owner(Books *&book, int &books_count); //Вывод информации о книгах находящихся на руках у читателей (сравнивает поле owner елси не Library значит на руках)

void Take_book(Books *&book, int &books_count, int pos); // Выдача книги.(копирует ФИО юзера в овнера книги)

void Return_book(Books *&book, int &books_count, int pos); // Возврат книги.(возвращает Library в овнера книги)

void Save(Books *&book, int &books_count); // сохранение базы книг

void Load(Books *&book, int &books_count); // загрузка базы книг
