#include <iostream>
#include <string.h>
//#include <fstream>
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

void Set_object(Movie &film);

void Add_object(Movie *&videostore, int &size);

void Remove_object(Movie *&videostore, int &size, int pos);

void First_obj(Movie *&videostore, int &size, Movie &film);

void Second_obj(Movie *&videostore, int &size, Movie &film);

void Save(Movie *&videostore, int &size);

void Load(Movie *&videostore, int &size);

int main()
{
    int size = 0;
    bool flag = true;
    Movie *videostore = nullptr; // создание пустого массива в никуда
    cout << "Would you like to load saved info?" << endl;
    cout << "NO/I haven't saved info/It's my first time =>> press 'a'" << endl;
    cout << "Yes i'd like =>> press 'b'" << endl;
    char tmp = getchar();
    cin.ignore();
    if (tmp == 98)
    {
        Load(videostore, size);
    }

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
        delete[] videostore;
    }
    cout << "END OF PROGRAM\n";
}

void Save(Movie *&videostore, int &size) // сохранение данных в файл (кол-во структур -> структуры)
{
    char path[20] = "Videostore.dat";
    FILE *fout = fopen(path, "wb");
    fwrite(&size, sizeof(size), 1, fout);
    for (int i = 0; i < size; i++)
    {
        fwrite(&videostore[i], sizeof(Movie), 1, fout);
    }
    fclose(fout);
    cout << "SAVED to " << path << endl;
}

void Load(Movie *&videostore, int &size) // загрузка данных из файла (кол-во структур -> структуры)
{
    char path[20] = "Videostore.dat";
    FILE *fin;
    if ((fin = fopen(path, "rb")) == NULL)
    {
        cout << "Errpr! Can't find file!" << path << " isn't exist!" << endl;
    }
    fread(&size, sizeof(size), 1, fin);
    videostore = new Movie[size];
    for (int i = 0; i < size; i++)
    {
        fread(&videostore[i], sizeof(Movie), 1, fin);
    }
    fclose(fin);
    cout << "LOADED from " << path << endl;
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
            cout << "Rating cant be more than 10 or less than 0!";
            cout << "\nMovie's rating ==> ";
            cin >> film.rating;
        } while (film.rating > 10.0 || film.rating < 0);
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
