#include "operations_user.h"

using namespace std;

int Position_choose_user(const int users_count) // Просит ввести позицию желаемого эллемента, пока не будет введен существующий
{
    if (users_count > 0)
    {
        int pos = 0, tmp = 0;
        cout << "\nEnter id of the user ==> ";
        cin >> tmp;
        cin.ignore();
        cout << endl;
        while (tmp < 0 || tmp >= users_count)
        {
            system("clear");
            cout << "\n\t\tError! Wrong id !\nEnter id of the user ==> ";
            cin >> tmp;
            cin.ignore();
        }
        pos = tmp;
        return pos;
    }
    else
    {
        cout << "\t\t\tError!There no users!" << endl;
        return 0;
    }
}

void Print_user(Users user) // Вывод конкретного пользователя
{
    cout << "==================================================================" << endl;
    cout << "Id : " << user.id_user << endl;
    cout << "Birthday date : " << user.bday_day << "." << user.bday_month << "." << user.bday_year << endl;
    cout << "User : " << user.user_surname << " " << user.user_name << " " << user.user_middle_name << endl;
    cout << "Passport number : " << user.passport_num << endl;
    cout << "Count of books read : " << user.books_read << endl;
    cout << "Books on hands : " << user.hand_books << endl;
    //cout << "==================================================================" << endl;
}

void Add_user(Users *&user, unsigned int &users_count) // Добавление.
{
    if (users_count == 0) //если пусто ,просто создать один пункт
    {
        user = new Users[1];
    }
    else // если не пусто ресайз и добавление
    {
        Users *tmp = new Users[users_count + 1];
        for (int i = 0; i < users_count; i++)
        {
            tmp[i] = user[i];
            tmp[i].id_user = i;
        }
        tmp[users_count].id_user = users_count;
        delete[] user;
        user = tmp;
    }
    Set_user(user[users_count]);
    users_count++;
}

void Set_user(Users &user) // Описание пользователя.
{
    int tmp = 0;           // промежуточная переменная для битовых полей
    float tmp_float = 0;   // промежуточная переменная для проверки дробных полей
    int user_fn_size = 20; // размер масивов ФИО юзера
    int passport_size = 8; // размер масива пасспорта

    cout << "\nThe users's birthday day ==> ";
    cin >> tmp;
    cin.ignore();
    while (tmp < 1 || tmp > 31)
    {
        system("clear");
        cout << "\n\t\tError!Wrong day!\nThe users's birthday day ==> ";
        cin >> tmp;
    }
    user.bday_day = tmp; // Дата рождения.День
    cout << "\nThe users's birthday month ==> ";
    cin >> tmp;
    cin.ignore();
    while (tmp < 1 || tmp > 12)
    {
        system("clear");
        cout << "\n\t\tError!Wrong month!\nThe users's birthday month ==> ";
        cin >> tmp;
    }
    user.bday_month = tmp; // Дата рождения.Месяц
    cout << "\nThe users's birthday year  ==> ";
    cin >> tmp;
    cin.ignore();
    while (tmp < 1 || tmp > 2048)
    {
        system("clear");
        cout << "\n\t\tError!Wrong year!\nThe users's birthday year ==> ";
        cin >> tmp;
    }
    user.bday_year = tmp; // Дата рождения.Год

    cout << "\nUser's name ==> ";
    cin.getline(user.user_name, user_fn_size); // Пользователь.Имя
    cout << "\nUser's surname ==> ";
    cin.getline(user.user_surname, user_fn_size); // Пользователь.Фамилия
    cout << "\nUser's middle name ==> ";
    cin.getline(user.user_middle_name, user_fn_size); // Пользователь.Отчество

    cout << "\nUser's passport code ==> ";
    cin.getline(user.passport_num, passport_size); // Номер паспорта.

    //    cout << "\nId of the user ==> "; // добавляется при инициализации
    //    cin >> user.id_user;
    //    cin.ignore();

    user.books_read = 0;         // Количество прочитанных книг.
    strcpy(user.hand_books, ""); // Список книг находящихся на руках у читателя
}

void Remove_user(Users *&user, unsigned int &users_count) // Удаление.
{
    int pos = Position_choose_user(users_count);
    if (pos < 0 || pos >= users_count) // эксепшн , если позиция за пределами ,защита от вылетов
    {
        return;
    }
    Users *tmp = new Users[--users_count];
    for (int i = 0, j = 0; i < users_count; j++, i++) //пересоздает массив исключая ненужный обьект
    {
        if (i == pos)
        {
            j++;
        }
        tmp[i] = user[j];
    }
    delete[] user;
    user = tmp;
}

void Edit_user(Users *&user, unsigned int &users_count) // Редактирование полное и частичное
{
    int user_fn_size = 20;                       // размер масивов ФИО юзера
    int passport_size = 8;                       // размер масива пасспорта
    int pos = Position_choose_user(users_count); // выбор пользователя для редактирования
    bool flag = true;                            // проверка выхода из цикла
    while (flag)
    {
        int tmp = 0;         // промежуточная переменная для битовых полей
        float tmp_float = 0; // промежуточная переменная для проверки дробных полей
        system("clear");
        Print_user(user[pos]);
        cout << "==================================================================" << endl;
        cout << "\n\t\tWhat would you want to do ?" << endl;
        cout << "\na) Fully edit information about the user;" << endl;
        cout << "b) Edit the birthday date;" << endl;
        cout << "c) Edit the user's full name;" << endl;
        cout << "d) Edit the user's passport code;\nESC to exit" << endl;
        cout << "\nYour choice ==>  " << endl;

        char key = getchar();
        cin.ignore();
        if (int(key) == 97 || int(key) == 98) // полное или 'b' (редактирование даты рождения)
        {
            system("clear");
            cout << "\nCurrent user's birthday day ==> " << user[pos].bday_day;
            cout << "\nUser's birthday day ==> ";
            cin >> tmp;
            cin.ignore();
            while (tmp < 1 || tmp > 31)
            {
                system("clear");
                cout << "\n\t\tError!Wrong day!\nUser's birthday day ==> ";
                cin >> tmp;
            }
            user[pos].bday_day = tmp; // Дата рождения.День

            cout << "\nCurrent user's birthday month ==> " << user[pos].bday_month;
            cout << "\nUser's birthday month ==> ";
            cin >> tmp;
            cin.ignore();
            while (tmp < 1 || tmp > 12)
            {
                system("clear");
                cout << "\n\t\tError!Wrong month!\nUser's birthday month ==> ";
                cin >> tmp;
            }
            user[pos].bday_month = tmp; // Дата рождения.Месяц

            cout << "\nCurrent user's birthday year ==> " << user[pos].bday_year;
            cout << "\nUser's birthday year ==> ";
            cin >> tmp;
            cin.ignore();
            while (tmp < 1 || tmp > 2048)
            {
                system("clear");
                cout << "\n\t\tError!Wrong year!\nUser's birthday year ==> ";
                cin >> tmp;
            }
            user[pos].bday_year = tmp; // Дата рождения.Год
        }

        if (int(key) == 97 || int(key) == 99) // полное или 'c' (редактирование фио пользователя)
        {
            system("clear");
            cout << "Current name of the user ==> " << user[pos].user_name << endl;
            cout << "\nNew name of the user ==> ";
            cin.getline(user[pos].user_name, user_fn_size);
            cout << "Current surname of the user ==> " << user[pos].user_surname << endl;
            cout << "\nNew surname of the user ==> ";
            cin.getline(user[pos].user_surname, user_fn_size);
            cout << "Current middle name of the user ==> " << user[pos].user_middle_name << endl;
            cout << "\nNew middle name of the user ==> ";
            cin.getline(user[pos].user_middle_name, user_fn_size);
        }

        if (int(key) == 97 || int(key) == 100) // полное или 'd' (редактирование пасспорта)
        {
            system("clear");
            cout << "\nCurrent passport number ==> " << user[pos].passport_num << endl;
            cout << "\nNew passport number ==> ";
            cin.getline(user[pos].passport_num, passport_size);
        }

        if (int(key) == 27)
        {
            flag = false;
        }
    }
}

void Work_with_user(Users *&user, unsigned int &users_count) // Работа с пользователем 3в1(Добавление.Удаление.Редактирование полное и частичное.)
{
    char key;
    bool flag = true;
    while (flag)
    {
        system("clear");
        cout << "\t\tWhat would you want to do with user?\n";
        cout << "\n\n";
        cout << "\ta) Add the user;\n";                             // Добавление.пользователя
        cout << "\tb) Remove the user;\n";                          // Удаление.пользователя
        cout << "\tc) Edit the user;\n\n\t\t\tESC - return back\n"; // Редактирование полное и частичное.пользователя

        key = getchar();
        cin.ignore();
        switch (key)
        {
        case 97: // a) Добавление.пользователя
            system("clear");
            Add_user(user, users_count);
            break;
        case 98: // b) Удаление.пользователя
            system("clear");
            Remove_user(user, users_count);
            break;
        case 99: // c) Редактирование полное и частичное.пользователя
            system("clear");
            Edit_user(user, users_count);
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

void User_info(Books *&book, unsigned int &books_count, Users *&user, unsigned int &users_count) // Информация о пользователе 3в1
{
    char key;
    bool flag = true;
    while (flag)
    {
        system("clear");
        cout << "\t\tWhat would you show about user?\n";
        cout << "\n\n";
        cout << "\ta) Serch the user by...;\n";                                                // Поиск и сортировка по ФИО, количеству прочитанных книг, ID, номеру паспорта.
        cout << "\tb) Show information about the most active readers.;\n";                     // Вывод информации на экран о самых активных читателях.
        cout << "\tc) Show information about the readers with the expired book return date.;"; // Вывод информации о читателях с просроченной датой возврата книги,
                                                                                               // обязательно выводить при этом количество просроченных дней и начисленной пени.
        cout << "\n\n\t\t\tESC - return back\n";
        key = getchar();
        cin.ignore();
        switch (key)
        {
        case 97: // a) Поиск и сортировка по ФИО, количеству прочитанных книг, ID, номеру паспорта.
            system("clear");
            Print_sort_user(user, users_count);
            break;
        case 98: // b) Вывод информации на экран о самых активных читателях.
            system("clear");
            Print_most_active_users(user, users_count);
            break;
        case 99: // c) Вывод информации о читателях с просроченной датой возврата книги
            system("clear");
            Print_promiser(book, books_count, user, users_count);
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

int comp_user_surname(const void *i, const void *j) // сравнение по ФАМИЛИИ пользователя для сортировки
{
    return strcmp(((Users *)i)->user_surname, ((Users *)j)->user_surname);
}
int comp_passport(const void *i, const void *j) // сравнение по ПАССПОРТУ пользователя для сортировки
{
    return strcmp(((Users *)i)->passport_num, ((Users *)j)->passport_num);
}
int comp_books_read(const void *i, const void *j) // сравнение по РЕЙТИНГУ книги для сортировки
{
    return (((Users *)i)->books_read) - (((Users *)j)->books_read);
}

void Print_sort_user(Users *&user, unsigned int &users_count) // Поиск и сортировка по ФИО, количеству прочитанных книг, ID, номеру паспорта.!!СОРТИРОВКУ ПРОВЕРИТЬ!!
{
    int pos;                  // позиция приннимается из ф-и
    int search_size = 30;     // размер массива поиска ФИО
    int tmp = 0;              // переменная для интового поиска
    char search[search_size]; // буфер для поиска
    bool flag = true;         // выход из цикла

    while (flag)
    {
        bool found = true; // проверка нахождения чего либо
        cout << "\t\tWhat would you want to do :" << endl;
        cout << "\n\n";
        cout << "\ta) Search and sort by user;" << endl;                                // Поиск и сортировка по ФИО
        cout << "\tb) Search by number of read books;" << endl;                         // Поиск по количеству прочитанных книг ,сортировка по ФИО
        cout << "\tc) Search by id;" << endl;                                           // Поиск по ID (сортировать безсмысленно ,т.к он уникальный )
        cout << "\td) Search  and sort by passport code;\n\n\t\t\tESC - выход" << endl; // Поиск и сортировка по коду пасспорта

        char key = getchar();
        cin.ignore();
        switch (key)
        {
        case 97: // a) Поиск и сортировка по ФИО
            system("clear");
            qsort(user, users_count, sizeof(Users), comp_user_surname); // быстрая сортировка по ФИО
            cout << "Enter user surname ==> ";
            cin.getline(search, search_size);
            for (int i = 0; i < users_count; i++)
            {
                if (strstr(user[i].user_surname, search))
                {
                    found = false;
                    Print_user(user[i]);
                    cout << "==================================================================" << endl;
                }
            }
            if (found)
            {
                cout << "\nNothing found :C" << endl;
            }
            break;

        case 98: // b) Поиск по количеству прочитанных книг ,сортировка по ФИО
            system("clear");
            qsort(user, users_count, sizeof(Users), comp_user_surname); // быстрая сортировка по ФИО
            cout << "Enter the number of read books ==> ";
            cin >> tmp;
            while (tmp < 0)
            {
                cout << "\n\t\tError!Can't be less than 0!\nEnter the number of read books ==> ";
                cin >> tmp;
            }
            for (int i = 0; i < users_count; i++)
            {
                if (user[i].books_read = tmp)
                {
                    found = false;
                    Print_user(user[i]);
                    cout << "==================================================================" << endl;
                }
            }
            if (found)
            {
                cout << "\nNothing found :C" << endl;
            }
            break;

        case 99: // c) Поиск по ID (сортировать безсмысленно ,т.к он уникальный )
            system("clear");
            pos = Position_choose_user(users_count);
            Print_user(user[pos]);
            break;

        case 100: // d)  Поиск и сортировка по коду пасспорта
            system("clear");
            qsort(user, users_count, sizeof(Users), comp_passport); // быстрая сортировка по коду пасспорта
            cout << "Enter passport code ==> ";
            cin.getline(search, 8);

            for (int i = 0; i < users_count; i++)
            {
                if (strstr(user[i].passport_num, search))
                {
                    found = false;
                    Print_user(user[i]);
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

void Print_most_active_users(Users *&user, unsigned int &users_count) // Вывод информации на экран о самых активных читателях.(кол-ву прочитаных книг)!!СОРТИРОВКУ ПРОВЕРИТЬ!!
{
    system("clear");
    qsort(user, users_count, sizeof(Users), comp_books_read); // быстрая сортировка по кол-ву прочитаных книг
    for (int i = 0; i < users_count; i++)
    {
        Print_user(user[i]);
        cout << "==================================================================" << endl;
    }
}

// !! Вывод информации о читателях с просроченной датой возврата книги, - в операциях по книге !
