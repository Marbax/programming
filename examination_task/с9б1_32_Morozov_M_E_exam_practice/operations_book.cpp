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
    book.take_date_day = 0;        // Дата взятия.День
    book.take_date_month = 0;      // Дата взятия.Месяц
    book.take_date_year = 0;       // Дата взятия.Год
    book.return_date_day = 0;      // Дата сдачи.День
    book.return_date_month = 0;    // Дата сдачи.Месяц
    book.return_date_year = 0;     // Дата сдачи.Год
    book.popularity = 0;           // Популярность(количество взятий книги)
}
int Position_choose_book(const int books_count) // Просит ввести позицию желаемого эллемента, пока не будет введен существующий
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
    int pos = Position_choose_book(books_count);
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
    int pos = Position_choose_book(books_count); // выбор книги для редактирования
    bool flag = true;                            // проверка выхода из цикла
    while (flag)
    {
        int tmp = 0;         // промежуточная переменная для битовых полей
        float tmp_float = 0; // промежуточная переменная для проверки дробных полей
        system("clear");
        Print_book(book[pos]);
        cout << "==================================================================" << endl;
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
            book[pos].publ_date_year = tmp; // Дата издания.Год
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
    //cout << "==================================================================" << endl;
}
int comp_auth_surname(const void *i, const void *j) // сравнение по ФАМИЛИИ автора для сортировки
{
    return strcmp(((Books *)i)->author_surname, ((Books *)j)->author_surname);
}
int comp_title_book(const void *i, const void *j) // сравнение по НАЗВАНИЮ книги для сортировки
{
    return strcmp(((Books *)i)->title_book, ((Books *)j)->title_book);
}
int comp_genres(const void *i, const void *j) // сравнение по ЖАНРУ книги для сортировки
{
    return strcmp(((Books *)i)->genres, ((Books *)j)->genres);
}
int comp_owner(const void *i, const void *j) // сравнение по ВЛАДЕЛЬЦУ книги для сортировки
{
    return strcmp(((Books *)i)->owner, ((Books *)j)->owner);
}
int comp_popularity(const void *i, const void *j) // сравнение по ПОПУЛЯРНОСТИ книги для сортировки
{
    return (((Books *)i)->popularity) - (((Books *)j)->popularity);
}
int comp_rating(const void *i, const void *j) // сравнение по РЕЙТИНГУ книги для сортировки
{
    return (((Books *)i)->rating) - (((Books *)j)->rating);
}
void Print_sort_book(Books *&book, int books_count) //Поиск и сортировка по автору, названию, жанру, популярности(кол-во взятий ??!). !!СОРТИРОВКУ ПРОВЕРИТЬ!!
{
    char search[30];      // буфер для поиска
    float tmp_rating = 0; // для поиска по рейтингу
    bool flag = true;     // выход из цикла
    while (flag)
    {
        bool found = true; // проверка нахождения чего либо
        cout << "\t\tWhat would you want to do :" << endl;
        cout << "\n\n";
        cout << "a) Search by author;" << endl;
        cout << "b) Search by title;" << endl;
        cout << "c) Search by genre;" << endl;
        cout << "d) Search by popularity;\nESC - выход" << endl;

        char key = getchar();
        cin.ignore();
        switch (key)
        {
        case 97: // a) Поиск и сортировка по автору.
            system("clear");
            qsort(book, books_count, sizeof(Books), comp_auth_surname); // быстрая сортировка по автору
            cout << "Enter autor of the movie ==> ";
            cin.getline(search, 30);
            for (int i = 0; i < books_count; i++)
            {
                if (strstr(book[i].author_surname, search))
                {
                    found = false;
                    Print_book(book[i]);
                    cout << "==================================================================" << endl;
                }
            }
            if (found)
            {
                cout << "\nNothing found :C" << endl;
            }
            break;
        case 98: // b) Поиск и сортировка по названию
            system("clear");
            qsort(book, books_count, sizeof(Books), comp_title_book); // быстрая сортировка по названию
            cout << "Enter title of the movie ==> ";
            cin.getline(search, 30);
            for (int i = 0; i < books_count; i++)
            {
                if (strstr(book[i].title_book, search))
                {
                    found = false;
                    Print_book(book[i]);
                    cout << "==================================================================" << endl;
                }
            }
            if (found)
            {
                cout << "\nNothing found :C" << endl;
            }
            break;
        case 99: // c) Поиск и сортировка по жанру.
            system("clear");
            qsort(book, books_count, sizeof(Books), comp_genres); // быстрая сортировка по жанру
            cout << "Enter genre of the movie ==> ";
            cin.getline(search, 30);
            for (int i = 0; i < books_count; i++)
            {
                if (strstr(book[i].genres, search))
                {
                    found = false;
                    Print_book(book[i]);
                    cout << "==================================================================" << endl;
                }
            }
            if (found)
            {
                cout << "\nNothing found :C" << endl;
            }
            break;
        case 100: // d) Поиск и сортировка по популярности
            system("clear");
            qsort(book, books_count, sizeof(Books), comp_popularity); // быстрая сортировка по популярности
            cout << "Enter minimum rating of the movie ==> ";
            cin >> tmp_rating;
            cin.ignore();
            while (tmp_rating < 0 || tmp_rating > 10)
            {
                cout << "\n\t\tError! Rating can't be more than 10 or less than 0!" << endl;
                cout << "Enter minimum rating of the movie ==> ";
                cin >> tmp_rating;
                cin.ignore();
            }
            for (int i = 0; i < books_count; i++)
            {
                if (book[i].rating >= tmp_rating)
                {
                    found = false;
                    Print_book(book[i]);
                    cout << "==================================================================" << endl;
                }
            }
            if (found)
            {
                cout << "\nNothing found :C" << endl;
            }
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
void Print_sort_book_by_genre(Books *&book, int &books_count) //Поиск по жанру, но сортировка по рейтингу. !!СОРТИРОВКНУЖНО ПРОВЕРИТЬ!!
{
    char search[30];   // буфер для поиска
    bool found = true; // проверка нахождения чего либо
    system("clear");
    qsort(book, books_count, sizeof(Books), comp_genres); // быстрая сортировка по жанрам
    cout << "Enter genre of the movie ==> ";
    cin.getline(search, 30);
    for (int i = 0; i < books_count; i++)
    {
        if (strstr(book[i].genres, search))
        {
            found = false;
            Print_book(book[i]);
            cout << "==================================================================" << endl;
        }
    }
    if (found)
    {
        cout << "\nNothing found :C" << endl;
    }
}
void Print_book_by_owner(Books *&book, int &books_count) /* Вывод информации о книгах находящихся на руках у читателей(сортировка по владельцу)
 !!СОРТИРОВКУ ПРОВЕРИТЬ!! (сравнивает поле статуса книги ,если фолс - на руках  ЛИБО сравнивает поле owner если не Library значит на руках) */
{
    char search[30];   // буфер для поиска
    bool found = true; // проверка нахождения чего либо
    system("clear");
    qsort(book, books_count, sizeof(Books), comp_owner); // быстрая сортировка по владельцу
    for (int i = 0; i < books_count; i++)
    {
        if (!book[i].status) //если статус книги фолс ,значиит на руках  //(!(strcmp(book[i].owner, "Library"))) // если в поле владельца книги не библиотека
        {
            found = false;
            Print_book(book[i]);
            cout << "Current owner: " << book[i].owner << "\nLease expiration date : ";
            cout << book[i].return_date_day << "." << book[i].return_date_month << "." << book[i].return_date_year << endl;
            cout << "==================================================================" << endl;
        }
    }
    if (found)
    {
        cout << "\nAll books in library" << endl;
    }
}
void Take_book(Books *&book, int &books_count, Users *&user, int &users_count) /* Выдача книги.(выбирает книгу , выбирает пользователя ,
копирует ФИО юзера в овнера книги и меняет статус, ставит дату взятия и сдачи)!! НУЖНО СДЕЛАТЬ ЮЗЕРА !! */
{
    system("clear");

    int tmp;

    int pos_book = Position_choose_book(books_count);
    if (book[pos_book].status)
    {

        int pos_user = Position_choose_user(users_count); // вызывает ф-ю пользователя(не книги)

        strcpy(book[pos_book].owner, user[pos_user].user_surname);
        strcat(book[pos_book].owner, " ");
        strcat(book[pos_book].owner, user[pos_user].user_name);
        strcat(book[pos_book].owner, " ");
        strcat(book[pos_book].owner, user[pos_user].user_middle_name);

        book[pos_book].status = false;

        if (strlen(user[pos_user].hand_books) > 1)
        {
            strcat(user[pos_user].hand_books, " , \"");
            strcat(user[pos_user].hand_books, book[pos_book].title_book);
            strcat(user[pos_user].hand_books, "\"");
        }
        strcat(user[pos_user].hand_books, "\"");
        strcpy(user[pos_user].hand_books, book[pos_book].title_book);
        strcat(user[pos_user].hand_books, "\"");

        //================== дата взятия ========================

        cout << "\nThe day the book was taken ==> ";
        cin >> tmp;
        cin.ignore();
        while (tmp < 1 || tmp > 31)
        {
            system("clear");
            cout << "\n\t\tError!Wrong day!\nThe day the book was taken ==> ";
            cin >> tmp;
        }
        book[pos_book].take_date_day = tmp; // Дата взятия.День
        cout << "\nThe month the book was taken ==> ";
        cin >> tmp;
        cin.ignore();
        while (tmp < 1 || tmp > 12)
        {
            system("clear");
            cout << "\n\t\tError!Wrong month!\nThe month the book was taken ==> ";
            cin >> tmp;
        }
        book[pos_book].take_date_month = tmp; // Дата взятия.Месяц
        cout << "\nThe year the book was taken ==> ";
        cin >> tmp;
        cin.ignore();
        while (tmp < 1 || tmp > 2048)
        {
            system("clear");
            cout << "\n\t\tError!Wrong year!\nThe year the book was taken ==> ";
            cin >> tmp;
        }
        book[pos_book].take_date_year = tmp; // Дата взятия.Год

        //================== дата сдачи ========================
        cout << "\nThe year when the rent ends ==> ";
        cin >> tmp;
        cin.ignore();
        while (tmp < 1 || tmp > 2048 || tmp < book[pos_book].take_date_year)
        {
            system("clear");
            cout << "\n\t\tError!Wrong year!\nThe year when the book were published ==> ";
            cin >> tmp;
        }
        book[pos_book].return_date_year = tmp; // Дата возврата.Год

        cout << "\nThe month when the rent ends ==> ";
        cin >> tmp;
        cin.ignore();
        while (tmp < 1 || tmp > 12 || (book[pos_book].return_date_year == book[pos_book].take_date_year && tmp < book[pos_book].take_date_month))
        {
            system("clear");
            cout << "\n\t\tError!Wrong month!\nThe month when the book were published ==> ";
            cin >> tmp;
        }
        book[pos_book].return_date_month = tmp; // Дата возврата.Месяц

        cout << "\nThe day when the rent ends ==> ";
        cin >> tmp;
        cin.ignore();
        while (tmp < 1 || tmp > 31 || (book[pos_book].return_date_year == book[pos_book].take_date_year && book[pos_book].return_date_month == book[pos_book].take_date_month && tmp < book[pos_book].take_date_day))
        {
            system("clear");
            cout << "\n\t\tError!Wrong day!\nThe day when the book were published ==> ";
            cin >> tmp;
        }
        book[pos_book].return_date_day = tmp; // Дата возврата.День
    }
    else
    {
        cout << "\nError! Books isn't in library!" << endl;
    }
}
void Return_book(Books *&book, int &books_count, Users *&user, int &users_count) /*  Возврат книги.(возвращает Library в овнера книги)
 При возврате книги читателем, учитывать, что если есть просроченные дни, то выводить на экран сумму начисленной пени.
увеличивает еол-во прочитанных книг пользователем !! ТРЕШАК !! */
{
    int pos_book = Position_choose_book(books_count);
    if (!book[pos_book].status)
    {

        int tmp = 0, day, month, year; // временная переменная и переменные даты ,когда пользователь сдал книгу
        char tmp_title_v1[54];         // временное хранение книги
        char tmp_title_v2[54];         // временное хранение книги

        //================== дата сдачи ========================
        cout << "\nThe year the user passed the book to back ==> ";
        cin >> tmp;
        cin.ignore();
        while (tmp < 1 || tmp > 2048 || tmp < book[pos_book].take_date_year)
        {
            system("clear");
            cout << "\n\t\tError!Wrong year!\nThe year the user passed the book to back ==> ";
            cin >> tmp;
        }
        year = tmp; // Дата возврата.Год

        cout << "\nThe month the user passed the book to back ==> ";
        cin >> tmp;
        cin.ignore();
        while (tmp < 1 || tmp > 12 || (year == book[pos_book].take_date_year && tmp < book[pos_book].take_date_month))
        {
            system("clear");
            cout << "\n\t\tError!Wrong month!\nThe month the user passed the book to back ==> ";
            cin >> tmp;
        }
        month = tmp; // Дата возврата.Месяц

        cout << "\nThe day the user passed the book to back  ==> ";
        cin >> tmp;
        cin.ignore();
        while (tmp < 1 || tmp > 31 || (year == book[pos_book].take_date_year && month == book[pos_book].take_date_month && tmp < book[pos_book].take_date_day))
        {
            system("clear");
            cout << "\n\t\tError!Wrong day!\nThe day the user passed the book to back ==> ";
            cin >> tmp;
        }
        day = tmp; // Дата возврата.День

        //=========================== считает пеню =============================================

        if (year <= book[pos_book].return_date_year && month <= book[pos_book].return_date_month && day < book[pos_book].return_date_day) // если просрочено
        {
            book[pos_book].fine_days = (book[pos_book].return_date_year - year) * 365 + (book[pos_book].return_date_month - month) * 29 + book[pos_book].return_date_day - day;
            book[pos_book].fine_money = book[pos_book].fine_days * book[pos_book].price;
            cout << "\n\t\tEttention!Deadline expired" << endl;
            cout << "Overdue by " << book[pos_book].fine_days << " days " << endl;
            cout << "Fine accrued " << book[pos_book].fine_money << endl;
        }

        //==================== удаление из книг на руках у юзера =====================================

        strcpy(tmp_title_v1, ", \"");
        strcat(tmp_title_v1, book[pos_book].title_book);
        strcat(tmp_title_v1, "\"");
        strcpy(tmp_title_v2, "\"");
        strcat(tmp_title_v2, book[pos_book].title_book);
        strcat(tmp_title_v2, "\"");

        for (int i = 0; i < users_count; i++)
        {
            if (strstr(user[i].hand_books, tmp_title_v1) && strstr(book[pos_book].owner, user[i].user_surname) && strstr(book[pos_book].owner, user[i].user_name) && strstr(book[pos_book].owner, user[i].user_middle_name))
            {
                strtok(user[i].hand_books, tmp_title_v1); // небось сломает все
                user[i].books_read++;                     // увеличивает кол-во прочитанных книг
            }
            if (strstr(user[i].hand_books, tmp_title_v2) && strstr(book[pos_book].owner, user[i].user_surname) && strstr(book[pos_book].owner, user[i].user_name) && strstr(book[pos_book].owner, user[i].user_middle_name))
            {
                strtok(user[i].hand_books, tmp_title_v2); // небось сломает все
                user[i].books_read++;                     // увеличивает кол-во прочитанных книг
            }
        }
        //==========================================================================================
        strcpy(book[pos_book].owner, "Library"); // возможно она и не нужна (переменная)
        book[pos_book].status = true;
        book[pos_book].take_date_day = 0;
        book[pos_book].take_date_month = 0;
        book[pos_book].take_date_year = 0;
        book[pos_book].return_date_day = 0;
        book[pos_book].return_date_month = 0;
        book[pos_book].return_date_year = 0;
    }
    else
    {
        cout << "\nError!Book alreary in library!" << endl;
    }
}
void Print_promiser(Books *&book, int &books_count, Users *&user, int &users_count) /* 
 Вывод информации о читателях с просроченной датой возврата книги,
 обязательно выводить при этом количество просроченных дней и начисленной пени. */
{
    int tmp = 0, day, month, year; // временная переменная и переменные даты ,когда пользователь сдал книгу

    //================== дата текущая ========================

    cout << "\nCurrent year ==> ";
    cin >> tmp;
    cin.ignore();
    while (tmp < 1 || tmp > 2048)
    {
        system("clear");
        cout << "\n\t\tError!Wrong year!\nCurrent year ==> ";
        cin >> tmp;
    }
    year = tmp;

    cout << "\nCurrent month ==> ";
    cin >> tmp;
    cin.ignore();
    while (tmp < 1 || tmp > 12)
    {
        system("clear");
        cout << "\n\t\tError!Wrong month!\nCurrent month ==> ";
        cin >> tmp;
    }
    month = tmp;

    cout << "\nCurrent day  ==> ";
    cin >> tmp;
    cin.ignore();
    while (tmp < 1 || tmp > 31)
    {
        system("clear");
        cout << "\n\t\tError!Wrong day!\nCurrent day ==> ";
        cin >> tmp;
    }
    day = tmp;

    for (int i = 0; i < books_count; i++) // считает всем книгам пеню
    {

        if (book[i].status == 0 && year <= book[i].return_date_year && month <= book[i].return_date_month && day < book[i].return_date_day) // если просрочено - считает сколько
        {
            book[i].fine_days = (book[i].return_date_year - year) * 365 + (book[i].return_date_month - month) * 29 + book[i].return_date_day - day;
            book[i].fine_money = book[i].fine_days * book[i].price;
        }
    }
    for (int i = 0; i < books_count; i++) // перебирает книги
    {
        for (int j = 0; j < users_count; j++) // ищет по названию книги в книгах на руках у пользователя и совпадению овнера книги и фио пользователя
        {
            if (strstr(user[j].hand_books, book[i].title_book) && strstr(book[i].owner, user[j].user_surname) && strstr(book[i].owner, user[j].user_name) && strstr(book[i].owner, user[j].user_middle_name))
            {
                Print_user(user[j]);
                cout << "\n\t\tEttention!Deadline expired" << endl;
                cout << "Overdue by " << book[i].fine_days << " days" << endl;
                cout << "Fine accrued " << book[i].fine_money << endl;
                cout << "==================================================================" << endl;
            }
        }
    }
}

void Save(Books *&book, int &books_count, Users *&user, int &users_count) // сохранение базы
{
    int path_size = 20;
    char path[path_size];
    char buf[path_size];

    cout << "Save to custom file ?(by deffault it's NO)\n a) YES \n b) NO" << endl;
    char key = getchar();
    cin.ignore();

    switch (key)
    {
    case 97: // a) Сохранить по дэфолту
        system("clear");
        cout << "Enter file name ==> " << endl;
        cin.getline(buf, path_size);
        strcpy(path, buf);
        if (!strstr(path, ".dat"))
        {
            strcat(path, ".dat");
        }
        break;
    default:
        strcpy(path, "Library.dat");
        break;
    }

    FILE *fout = fopen(path, "wb");
    fwrite(&books_count, sizeof(books_count), 1, fout);
    fwrite(&users_count, sizeof(users_count), 1, fout);
    for (int i = 0; i < books_count; i++)
    {
        fwrite(&book[i], sizeof(Books), 1, fout);
    }
    for (int j = 0; j < users_count; j++)
    {
        fwrite(&user[j], sizeof(Users), 1, fout);
    }
    fclose(fout);
    cout << "SAVED to " << path << endl;
}

void Load(Books *&book, int &books_count, Users *&user, int &users_count) // загрузка базы
{
    int path_size = 20;
    char path[path_size];
    char buf[path_size];

    cout << "Load from custom file ?(by deffault it's NO)\n a) YES \n b) NO" << endl;
    char key = getchar();
    cin.ignore();

    switch (key)
    {
    case 97: // a) Загрузить из введеннго
        system("clear");
        cout << "Enter file name ==> " << endl;
        cin.getline(buf, path_size);
        strcpy(path, buf);
        if (!strstr(path, ".dat"))
        {
            strcat(path, ".dat");
        }
        break;
    default:
        strcpy(path, "Library.dat");
        break;
    }

    FILE *fin;
    if ((fin = fopen(path, "rb")) == NULL)
    {
        cout << "Errpr! Can't find file!" << path << " isn't exist!" << endl;
    }
    fread(&books_count, sizeof(books_count), 1, fin);
    fread(&users_count, sizeof(users_count), 1, fin);

    book = new Books[books_count];
    for (int i = 0; i < books_count; i++)
    {
        fread(&book[i], sizeof(Books), 1, fin);
    }

    user = new Users[users_count];
    for (int j = 0; j < users_count; j++)
    {
        fread(&user[j], sizeof(Users), 1, fin);
    }

    fclose(fin);
    cout << "LOADED from " << path << endl;
}