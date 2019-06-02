#ifndef _USER_H // аналог pragma once
#define _USER_H

struct Users
{
    unsigned int bday_day : 5;   // Дата рождения.День
    unsigned int bday_month : 4; // Дата рождения.Месяц
    unsigned int bday_year : 11; // Дата рождения.Год
    char user_name[20];          // Имя.
    char user_surname[20];       // Фамилия.
    char user_middle_name[20];   // Отчество.
    unsigned int id_user;        // ID номер читателя.
    char pssport_num[8];         // Номер паспорта.
    unsigned int books_read;     // Количество прочитанных книг.
    char hand_books[200];        // Список книг находящихся на руках у читателя
    unsigned int fine_day = 0;   // Текущее кол-во просроченых дней
    unsigned int fine_money = 0; // Текущий денежный долг
};

#endif // !_USER_H
