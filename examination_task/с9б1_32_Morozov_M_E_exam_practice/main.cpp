#include "operations_book.h"
#include "operations_user.h"
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    unsigned int books_count = 0; // размер массива структур книг
    unsigned int users_count = 0; // размер массива структур пользователей
    Books *book = nullptr;        // инициализация массива структур книг
    Users *user = nullptr;        // инициализация массива структур пользователей
    bool flag = true;             // проверка завершения приложения
    char key;                     // выбор пункта меню

    while (flag)
    {
        system("clear");
        cout << "Welcome th Library\n\n\t\t\tWhat would you want to do :\n";
        cout << "\n\n";
        cout << "\ta) Add ,remove or edit the book;\n"; // Добавление.Удаление.Редактирование полное и частичное.Книги
        cout << "\tb) Add ,remove or edit the user;\n"; // Добавление.Удаление.Редактирование полное и частичное.Пользователя
        cout << "\tc) Information about the book;\n";   // Поиск и сортировка по автору, названию, жанру, популярности.
                                                        // Вывод информации на экран о самых популярных книгах в своем жанре.
                                                        // Вывод информации о книгах находящихся на руках у читателей.

        cout << "\td) Information about the user;\n"; // Поиск и сортировка по ФИО, количеству прочитанных книг, ID, номеру паспорта.
                                                      // Вывод информации на экран о самых активных читателях.
                                                      // Вывод информации о читателях с просроченной датой возврата книги,
                                                      // обязательно выводить при этом количество просроченных дней и начисленной пени.

        cout << "\te) ;\n"; //
        cout << "\tf) ;\n"; //
        cout << "\tg) \nESC - exit program\n";

        key = getchar();
        cin.ignore();
        switch (key)
        {
        case 97: // a) Добавление.Удаление.Редактирование полное и частичное.Книги
            system("clear");
            Work_with_book(book, books_count);
            break;

        case 98: // b) Добавление.Удаление.Редактирование полное и частичное.Пользователя
            system("clear");
            Work_with_user(user, users_count);
            break;

        case 99: // c) // Поиск и сортировка по автору, названию, жанру, популярности.
                 //Вывод информации на экран о самых популярных книгах в своем жанре.Вывод информации о книгах находящихся на руках у читателей.
            system("clear");
            Book_info(book, books_count);
            break;

        case 100: // d) Поиск и сортировка по ФИО, количеству прочитанных книг, ID, номеру паспорта.
                  // Вывод информации на экран о самых активных читателях.
                  // Вывод информации о читателях с просроченной датой возврата книги,
                  // обязательно выводить при этом количество просроченных дней и начисленной пени.
            system("clear");
            User_info(book, books_count, user, users_count);
            break;

        case 27:
            system("clear");
            flag = false;
            break;

        default:
            cout << "\n\t\tUnknown choice! Try again." << endl;
            break;
        }
    }
}
/* 
BOOK

Выдача книги.
Возврат книги.При возврате книги читателем, учитывать, что если есть просроченные дни, то выводить на экран сумму начисленной пени.


USER

 */