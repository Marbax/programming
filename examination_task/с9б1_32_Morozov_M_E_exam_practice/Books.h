#pragma once

struct Books
{
    unsigned int publ_date_day : 5;     // Дата издания.День
    unsigned int publ_date_month : 4;   // Дата издания.Месяц
    unsigned int publ_date_year : 11;   // Дата издания.Год
    char title_book[50];                // Название.
    char author_name[20];               // Автор.Имя
    char author_surname[20];            // Автор.Фамилия
    char author_middle_name[20];        // Автор.Отчество
    char genres[50];                    // Жанр.
    double price;                       // Стоимость.(за месяц оренды (29 дней))
    float rating;                       // Рейтинг.
    unsigned int id_book;               // ID номер книги.
    bool status = true;                 // статус книги ,на руках = фолс ,в библиотеке = тру
    char owner[100] = "Library";        // у кого находится книга (можно попробовать через айдишник юзера ,если он будет позицией - будет быстрее)
    unsigned int fine_days = 0;         // Текущее кол-во просроченых дней по книге
    float fine_money = 0;               // Текущий денежный долг по книге
    unsigned int return_date_day : 5;   // Дата сдачи.День
    unsigned int return_date_month : 4; // Дата сдачи.Месяц
    unsigned int return_date_year : 11; // Дата сдачи.Год
};
