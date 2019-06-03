#include "operations_book.h"

using namespace std;

void Add_book(Books *&book, int &books_count) //Добавление книги.
{
    if (books_count == 0) //если пусто ,просто создать один пункт
    {
        book = new Books[1];
    }
    else // если не пусто ресайз и добавление
    {
        Books *tmp = new Books[books_count + 1];
        for (int i = 0; i < books_count; i++)
        {
            tmp[i] = book[i];
            tmp[i].id_book = i;
        }
        tmp[books_count].id_book = books_count;
        delete[] book;
        book = tmp;
    }
    Set_book(book[books_count]);
    books_count++;
}
void Set_book(Books &book) // Описание книги.
{
    int tmp; // промежуточная переменная для битовых полей
    cout << "\nThe day when the book were published ==> ";
    cin >> tmp;
    cin.ignore();
    book.publ_date_day = tmp; // Дата издания.День
    cout << "\nThe month when the book were published ==> ";
    cin >> tmp;
    cin.ignore();
    book.publ_date_month = tmp; // Дата издания.Месяц
    cout << "\nThe year when the book were published ==> ";
    cin >> tmp;
    cin.ignore();
    book.publ_date_year = tmp; // Дата издания.Год
    cout << "\nTitle of the book ==> ";
    cin.getline(book.title_book, 50); // Название книги.
    cout << "\nAuthor's name ==> ";
    cin.getline(book.author_name, 20); // Автор.Имя
    cout << "\nAuthor's surname ==> ";
    cin.getline(book.author_surname, 20); // Автор.Фамилия
    cout << "\nAuthor's middle name ==> ";
    cin.getline(book.author_middle_name, 20); // Автор.Отчество
    cout << "\nGenres of the book ==> ";
    cin.getline(book.genres, 50); // Жанры.
    cout << "\nRent per month == > ";
    cin >> book.price; // Стоимость.(за месяц оренды (29 дней))
    cin.ignore();
    cout << "\nBook's rating ==> ";
    cin >> book.rating; // Рейтинг.
    if (book.rating > 10.0 || book.rating < 0)
    {
        do
        {
            system("clear");
            cout << "Rating cant be more than 10 or less than 0!";
            cout << "\nBook's rating ==> ";
            cin >> book.rating;
        } while (book.rating > 10.0 || book.rating < 0);
    }
    //    cout << "\nId of the book ==> "; // добавляется при инициализации
    //    cin >> book.id_book;
    //    cin.ignore();
    book.status = true;            // статус книги ,на руках = фолс ,в библиотеке = тру (по дэфолту)
    strcpy(book.owner, "Library"); // book.owner = "Library";
    book.fine_days = 0;            // Текущее кол-во просроченых дней по книге
    book.fine_money = 0;           // Текущий денежный долг по книге
    book.return_date_day = 0;      // Дата сдачи.День
    book.return_date_month = 0;    // Дата сдачи.Месяц
    book.return_date_year = 0;     // Дата сдачи.Год
}
void Remove_book(Books *&book, int &books_count, int pos) //Удаление книги.
{
    if (pos < 0 || pos >= books_count) // эксепшн , если позиция за пределами ,защита от вылетов
    {
        return;
    }
    Books *tmp = new Books[--books_count];
    for (int i = 0, j = 0; i < books_count; j++, i++) //пересоздает массив исключая ненужный обьект
    {
        if (i == pos)
        {
            j++;
        }
        tmp[i] = book[j];
    }
    delete[] book;
    book = tmp;
}
void Edit_book(Books *&book, int &books_count, int pos); //Редактирование полное и частичное.

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
