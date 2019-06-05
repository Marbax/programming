#pragma once
#include "operations_user.h"

using namespace std;

int Position_choose_user(const int users_count) // Просит ввести позицию желаемого эллемента, пока не будет введен существующий
{
    int pos = NULL, tmp = NULL;
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

void Add_user(Users *&user, int &users_count) // Добавление.
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

void Remove_user(Users *&user, int &users_count) // Удаление.
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

void Edit_user(Users *&user, int &users_count) // Редактирование полное и частичное
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

// !! IN PROGRESS !!

void Print_sort_user(Users *&user, int &users_count); // Поиск и сортировка по ФИО, количеству прочитанных книг, ID, номеру паспорта.

void Print_most_active_users(Users *&user, int &users_count); // Вывод информации на экран о самых активных читателях.

// Вывод информации о читателях с просроченной датой возврата книги, - в операциях по книге !
