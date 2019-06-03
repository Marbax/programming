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
    int tmp = 0;         // промежуточная переменная для битовых полей
    float tmp_float = 0; // промежуточная переменная для проверки дробных полей
    cout << "\nThe day when the book were published ==> ";
    cin >> tmp;
    cin.ignore();
    while (tmp < 1 || tmp > 31)
    {
        system("clear");
        cout << "\n\t\tError!Wrong day!\nThe day when the book were published ==> ";
        cin >> tmp;
    }
    book.publ_date_day = tmp; // Дата издания.День
    cout << "\nThe month when the book were published ==> ";
    cin >> tmp;
    cin.ignore();
    while (tmp < 1 || tmp > 12)
    {
        system("clear");
        cout << "\n\t\tError!Wrong month!\nThe month when the book were published ==> ";
        cin >> tmp;
    }
    book.publ_date_month = tmp; // Дата издания.Месяц
    cout << "\nThe year when the book were published ==> ";
    cin >> tmp;
    cin.ignore();
    while (tmp < 1 || tmp > 2048)
    {
        system("clear");
        cout << "\n\t\tError!Wrong year!\nThe year when the book were published ==> ";
        cin >> tmp;
    }
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
    cin >> tmp_float;
    cin.ignore();
    while (tmp_float < 0)
    {
        cout << "\n\t\tError!Can't be negative!\nRent per month == > ";
        cin >> tmp_float;
        cin.ignore();
    }
    book.price = tmp_float; // Стоимость.(за день оренды)
    cout << "\nBook's rating ==> ";
    cin >> tmp_float;
    cin.ignore();
    while (tmp_float > 10.0 || tmp_float < 0)
    {
        system("clear");
        cout << "\n\t\tError!Rating cant be more than 10 or less than 0!";
        cout << "\nBook's rating ==> ";
        cin >> tmp_float;
        cin.ignore();
    }
    book.rating = tmp_float; // Рейтинг.
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
int Position_choose(const int books_count) // Просит ввести позицию желаемого эллемента, пока не будет введен существующий
{
    int pos = NULL, tmp = NULL;
    cout << "\nEnter id of the book ==> ";
    cin >> tmp;
    cin.ignore();
    cout << endl;
    while (tmp < 0 || tmp >= books_count)
    {
        system("clear");
        cout << "\n\t\tError! Wrong id !\nEnter id of the book ==> ";
        cin >> tmp;
        cin.ignore();
    }
    pos = tmp;
    return pos;
}
void Remove_book(Books *&book, int &books_count) //Удаление книги.
{
    int pos = Position_choose(books_count);
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
void Edit_book(Books *&book, int &books_count) //Редактирование полное и частичное.
{
    int pos = Position_choose(books_count); // выбор книги для редактирования
    bool flag = true;                       // проверка выхода из цикла
    while (flag)
    {
        int tmp = 0;         // промежуточная переменная для битовых полей
        float tmp_float = 0; // промежуточная переменная для проверки дробных полей
        system("clear");
        Print_book(book[pos]);
        cout << "\n\t\tWhat would you want to do ?" << endl;
        cout << "\na) Fully edit information about the book;" << endl;
        cout << "b) Edit the publication date;" << endl;
        cout << "c) Edit the book's title;" << endl;
        cout << "d) Edit the author;" << endl;
        cout << "e) Edit genres of the book;" << endl;
        cout << "f) Edit the price of the book;" << endl;
        cout << "g) Edit rating of the book;\nESC to exit" << endl;
        cout << "\nYour choice ==>  " << endl;
        char key = getchar();
        cin.ignore();
        if (int(key) == 97 || int(key) == 98) // полное или 'b' (редактирование даты издания)
        {
            system("clear");
            cout << "\nCurrent day when the book were published ==> " << book[pos].publ_date_day;
            cout << "\nThe day when the book were published ==> ";
            cin >> tmp;
            cin.ignore();
            while (tmp < 1 || tmp > 31)
            {
                system("clear");
                cout << "\n\t\tError!Wrong day!\nThe day when the book were published ==> ";
                cin >> tmp;
            }
            book[pos].publ_date_day = tmp; // Дата издания.День
            cout << "\nCurrent month when the book were published ==> " << book[pos].publ_date_month;
            cout << "\nThe month when the book were published ==> ";
            cin >> tmp;
            cin.ignore();
            while (tmp < 1 || tmp > 12)
            {
                system("clear");
                cout << "\n\t\tError!Wrong month!\nThe month when the book were published ==> ";
                cin >> tmp;
            }
            book[pos].publ_date_month = tmp; // Дата издания.Месяц
            cout << "\nCurrent year when the book were published ==> " << book[pos].publ_date_year;
            cout << "\nThe year when the book were published ==> ";
            cin >> tmp;
            cin.ignore();
            while (tmp < 1 || tmp > 2048)
            {
                system("clear");
                cout << "\n\t\tError!Wrong year!\nThe year when the book were published ==> ";
                cin >> tmp;
            }
        }
        if (int(key) == 97 || int(key) == 99) // полное или 'c' (редактирование названия книги)
        {
            system("clear");
            cout << "\nCurrent title of the book ==> " << book[pos].title_book << endl;
            cout << "\nNew title of the book ==> ";
            cin.getline(book[pos].title_book, 50);
        }
        if (int(key) == 97 || int(key) == 100) // полное или 'd' (редактирование автора книги)
        {
            system("clear");
            cout << "Current name of the author ==> " << book[pos].author_name << endl;
            cout << "\nNew name of the author ==> ";
            cin.getline(book[pos].author_name, 20);
            cout << "Current surname of the author ==> " << book[pos].author_surname << endl;
            cout << "\nNew surname of the author ==> ";
            cin.getline(book[pos].author_surname, 20);
            cout << "Current middle name of the author ==> " << book[pos].author_middle_name << endl;
            cout << "\nNew middle name of the author ==> ";
            cin.getline(book[pos].author_middle_name, 20);
        }
        if (int(key) == 97 || int(key) == 101) // полное или 'e' (редактирование жанров книги)
        {
            system("clear");
            cout << "Current genres of the book ==> " << book[pos].genres << endl;
            cout << "\nNew genres of the book ==> ";
            cin.getline(book[pos].genres, 50);
        }
        if (int(key) == 97 || int(key) == 102) // полное или 'f' (редактирование цены книги)
        {
            system("clear");
            cout << "Current price of the book ==> " << book[pos].price << " (per day)" << endl;
            cout << "\nRent per month == > ";
            cin >> tmp_float;
            cin.ignore();
            while (tmp_float < 0)
            {
                cout << "\n\t\tError!Can't be negative!\nRent per month == > ";
                cin >> tmp_float;
                cin.ignore();
            }
            book[pos].price = tmp_float; // Стоимость.(за день оренды)
        }
        if (int(key) == 97 || int(key) == 103) // полное или 'g' (редактирование рейтинга книги)
        {
            system("clear");
            cout << "Current rating of the book ==> " << book[pos].rating << endl;
            cout << "\nNew rating of the book ==> ";
            cin >> tmp_float;
            cin.ignore();
            while (tmp_float > 10.0 || tmp_float < 0)
            {
                system("clear");
                cout << "\n\t\tError!Rating cant be more than 10 or less than 0!";
                cout << "\nNew rating of the book  ==> ";
                cin >> tmp_float;
                cin.ignore();
            }
        }
        if (int(key) == 27)
        {
            flag = false;
        }
    }
}
void Print_book(Books book) // Вывод конкретной книги
{
    cout << "==================================================================" << endl;
    cout << "Id : " << book.id_book << endl;
    cout << "Publication date : " << book.publ_date_day << "." << book.publ_date_month << "." << book.publ_date_year << endl;
    cout << "Title : " << book.title_book << " \nAuthor : " << book.author_surname << " " << book.author_name << " " << book.author_middle_name << endl;
    cout << "Genres : " << book.genres << endl;
    cout << "Cost : " << book.price << " (per day)" << endl;
    cout << "Rating : " << book.rating << "/10" << endl;
    cout << "==================================================================" << endl;
}
void Print_sort_book(Books *&book, int books_count); //Поиск и сортировка по автору, названию, жанру, популярности.

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
