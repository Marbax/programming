#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

// 1. Создать структуру Movie со следующими полями:
// - Id
// - Название фильма
// - Режиссер
// - Жанр
// - Рейтинг популярности
// - Цена диска
// 2. Создать динамический массив videostore типа Movie
// 3. Реализовать следующие возможности:
// - Добавление нового фильма в videostore
// - Удаление последнего фильма.
// - Вывод на экран информации о фильме.
// - Удаление фильма по ID.
// - Поиск фильма по названию.
// - Поиск фильма по жанру.
// 4.Добавить функции сохранения(Save) и загрузки(Load) фильмов.

struct Director // ФИО владельца , дочерняя структура Movie
{
    char name[20];
    char surname[20];
    char middle_name[20];
};

struct Movie // главная структура
{
    int Id;
    char name[100];
    Director director; // вложеная структура
    char genre[100];
    float rating;
    float cost;
};
void Print_Movie(Movie film);

void Print_Director(Director director);

void Save(Movie *&videostore, int &size)//хз как структуру сохранять правиль
{
    string path_sctruct = "Videostore_struct.dat";
    // FILE* f = fopen(path_sctruct,"wb")
    ofstream fout(path_sctruct, ios::binary);
    if (!fout.is_open())
    {
        cout << "Error , while try to open file!" << endl;
    }
    else
    {
        fout.write((char *)&size, sizeof(size));
        /* for (int i = 0; i < size; i++)
        {
            fout.write((char *)(&videostore[i]), sizeof(Movie));
        } */
        fout.write((char *)(&videostore), sizeof(Movie) * size);
    }
    fout.close();
}

void Load(Movie *&videostore, int &size) // хз как загружать структуру правильно
{
    string path_sctruct = "Videostore_struct.dat";
    ifstream file_in(path_sctruct, ios::binary);
    if (!file_in.is_open())
    {
        cout << "Error , while try to open file!" << endl;
    }
    else
    {
        file_in.read((char *)&size, sizeof(size));
        cout << "size = " << size << endl;
        /* for (int i = 0; i < size; i++)
        {
            videostore = new Movie[i];
            file_in.read((char *)(&videostore[i]), sizeof(Movie));
            cout << "!!! " << i << " " << &videostore[i] << endl;
        } */
        file_in.read((char *)(&videostore), sizeof(Movie));
    }
    file_in.close();
}
void Print_Director(Director director) // вывод инфы о владельце
{
    cout << "Director : " << director.surname << " " << director.name << " " << director.middle_name << endl;
}

void Print_Movie(Movie film) // вывод полной инфы о фильме
{
    cout << "Id : " << film.Id << "\nMovie name : " << film.name << endl;
    Print_Director(film.director);
    cout << "Genres : " << film.genre << " \nRating : " << film.rating << " \nMovie cost : " << film.cost << " uah" << endl;
}

void Set_object(Movie &film) // создание обьекта
{
    //    cout << "\nId of the Movie ==> "; // добавляется при инициализации
    //    cin >> film.Id;
    //    cin.ignore();
    cout << "\nName of the Movie ==> ";
    cin.getline(film.name, 100);
    cout << "\ndirector's name ==> ";
    cin.getline(film.director.name, 20);
    cout << "\ndirector's Surname ==> ";
    cin.getline(film.director.surname, 20);
    cout << "\ndirector's Middle name ==> ";
    cin.getline(film.director.middle_name, 20);
    cout << "\nGenres of the Movie ==> ";
    cin.getline(film.genre, 100);
    cout << "\nMovie's rating ==> ";
    cin >> film.rating;
    if (film.rating > 10.0)
    {
        do
        {
            system("clear");
            cout << "Rating cant be more than 10 !";
            cout << "\nMovie's rating ==> ";
            cin >> film.rating;
        } while (film.rating > 10.0);
    }

    cin.ignore();
    cout << "\nMovie's cost ==> ";
    cin >> film.cost;
    cin.ignore();
}

void Add_object(Movie *&videostore, int &size) // пересбор массива с новым обьектом , переопределяет айдишники при каждом добавлении обекта
{
    if (size == 0) //если пусто ,просто создать один пункт
    {
        videostore = new Movie[1];
    }
    else // если не пусто ресайз и добавление
    {
        Movie *tmp = new Movie[size + 1];
        for (int i = 0; i < size; i++)
        {
            tmp[i] = videostore[i];
            tmp[i].Id = i;
        }
        tmp[size].Id = size;
        delete[] videostore;
        videostore = tmp;
    }
    Set_object(videostore[size]);
    size++;
}

void Remove_object(Movie *&videostore, int &size, int pos) // удаление обьекта целиком
{
    if (pos < 0 || pos >= size) // эксепшн , если позиция за пределами ,защита от вылетов
    {
        return;
    }
    Movie *tmp = new Movie[--size];
    for (int i = 0, j = 0; i < size; j++, i++) //пересоздает массив исключая ненужный обьект
    {
        if (i == pos)
        {
            j++;
        }
        tmp[i] = videostore[j];
    }
    delete[] videostore;
    videostore = tmp;
}

void First_obj(Movie *&videostore, int &size, Movie &film) // создание записей ,чтоб меньше кликать
{
    videostore = new Movie[1];
    strcpy(film.name, "December");
    film.Id = size;
    strcpy(film.director.name, "Petr");
    strcpy(film.director.surname, "Petrov");
    strcpy(film.director.middle_name, "Petrovich");
    strcpy(film.genre, "Horror , comedy , melodrame");
    film.rating = 8.1;
    film.cost = 111;
    videostore[size] = film;
    size++;
}

void Second_obj(Movie *&videostore, int &size, Movie &film) // создание записей ,чтоб меньше кликать
{
    Movie *tmp = new Movie[size + 1];
    for (int i = 0; i < size; i++)
    {
        tmp[i] = videostore[i];
    }
    delete[] videostore;
    videostore = tmp;
    strcpy(film.name, "Picachu");
    film.Id = size;
    strcpy(film.director.name, "Jim");
    strcpy(film.director.surname, "Cerry");
    strcpy(film.director.middle_name, "Petrovich");
    strcpy(film.genre, "Fantasy , comedy , melodrame");
    film.rating = 5.51;
    film.cost = 1111;
    videostore[size] = film;
    size++;
}

int main()
{
    int size = 0;
    bool flag = true;
    Movie *videostore = nullptr; // создание пустого массива
    Load(videostore, size);

    /* 
    Movie one;
    First_obj(videostore, size, one);
    Movie two;
    Second_obj(videostore, size, two);
    Movie three;
    Second_obj(videostore, size, three);
 */

    while (flag)
    {
        int pos = 0;
        char string[100];
        bool found = true;
        cout << "What you want to do :\n";
        cout << "\n\n";
        cout << "a) Print all Movies;\n";
        cout << "b) Print Movie by the id;\n";
        cout << "c) Add new Movie;\n";
        cout << "d) Remove last Movie;\n";
        cout << "e) Remove Movie by the id;\n";
        cout << "f) Search movie by the name;\n";
        cout << "g) Search movie by the genre\nESC - выход\n";

        char key = getchar();
        cin.ignore();
        switch (key)
        {
        case 103: // g) поиск по жанру
            system("clear");
            cout << "Enter genre of the movie ==> ";
            cin.getline(string, 100);
            for (int i = 0; i < size; i++)
            {
                if (strstr(videostore[i].genre, string))
                {
                    found = false;
                    cout << "==================================================================" << endl;
                    Print_Movie(videostore[i]);
                    cout << "==================================================================\n"
                         << endl;
                }
            }
            if (found)
            {
                cout << "\nMovie wasnt found :C\n"
                     << endl;
            }
            break;
        case 102: // f) поиск по имени
            system("clear");
            cout << "Enter name of the movie ==> ";
            cin.getline(string, 100);
            for (int i = 0; i < size; i++)
            {
                if (strstr(videostore[i].name, string))
                {
                    found = false;
                    cout << "==================================================================" << endl;
                    Print_Movie(videostore[i]);
                    cout << "==================================================================\n"
                         << endl;
                }
            }
            if (found)
            {
                cout << "\nMovie wasnt found :C\n"
                     << endl;
            }
            break;
        case 101: // e) удаление фильма по Id
            cout << "Enter Id ==> ";
            cin >> pos;
            cin.ignore();
            Remove_object(videostore, size, pos);
            system("clear");
            break;
        case 100: // d) удаление последнего фильма
            Remove_object(videostore, size, size - 1);
            system("clear");
            break;
        case 99: // c) добавление нового фильма.
            system("clear");
            Add_object(videostore, size);
            system("clear");
            break;
        case 98: // b) вывод конкретного фильма по Id
            system("clear");
            cout << "Enter Id ==> ";
            cin >> pos;
            cin.ignore();
            if (pos >= 0 && pos < size)
            {
                cout << "==================================================================" << endl;
                Print_Movie(videostore[pos]);
                cout << "==================================================================\n"
                     << endl;
            }
            else
            {
                cout << "Error! Wrong Id! " << endl;
            }
            break;
        case 97: // a) Показывает все фильмы;
            system("clear");
            for (int i = 0; i < size; i++)
            {
                cout << "==================================================================" << endl;
                Print_Movie(videostore[i]);
                cout << "==================================================================\n"
                     << endl;
            }
            break;
        case 27:
            system("clear");
            cout << "Good bye\n";
            flag = false;
            break;
        }
    }

    if (size) //если массив не пустой - очистить память
    {
        Save(videostore, size);
        cout << "SAVED\n";
        delete[] videostore;
    }
    cout << "END OF PROGRAM\n";
}
