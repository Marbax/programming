#include <iostream>
#include <iomanip>
#include <ctime>
#include <string.h>
#include <math.h>
using namespace std;

// 1. Создать структуру House со следующими полями:
// - Владелец
// - Адрес
// - Высота
// - Количество этажей
// - Количество квартир
// - Дата постройки
// - Материал
// - Стоимость кв.м.
// 2. Создать функции:
// - Заполнения объекта с клавиатуры;
// - Вывода на экран информации об объекте;
// - Полного и частичного редактирования данных объекта.

struct F_name // ФИО владельца , дочерняя структура House
{
    char name[20];
    char surname[20];
    char middle_name[20];
};

struct Date // дата строительства, дочерняя структура House
{
    int day;
    int month;
    char mon_name[20];
    int year;
};

struct House // главная структура
{
    F_name owner; // вложеная структура
    char address[100];
    float height;
    int count_storeys;
    int count_apartaments;
    Date constr_date; // вложеная структура
    char material[200];
    int cost_sq_metr;
};

void Print_Owner(F_name House) // вывод инфы о владельце
{
    cout << "Owner : " << House.name << " " << House.surname << " " << House.middle_name << endl;
}

void Print_Constr_date(Date date) // вывод инфы о дате строительства
{
    cout << "Constuction date : " << date.day << "." << date.month << "(" << date.mon_name << ")." << date.year << endl;
}

void Print_Buiding(House house) // вывод полной инфы о доме
{
    Print_Owner(house.owner); //cout << house.owner.name << "  " << house.owner.surname << "  " << house.owner.middle_name << "  " << house.address;
    cout << "Height : " << house.height << " meters\nStoreys count : " << house.count_storeys << " \nApartaments count : " << house.count_apartaments << endl;
    Print_Constr_date(house.constr_date); //cout << house.constr_date.day << "  " << house.constr_date.month << "(" << house.constr_date.mon_name << ")." << house.constr_date.year;
    cout << "Materils from which building was built : " << house.material << " \nCost per square meter : " << house.cost_sq_metr << " uah" << endl;
}

void Set_object(House &house) // создание обьекта
{
    cout << "\nOwner's Name ==> ";
    cin.getline(house.owner.name, 20);
    cout << "\nOwner's Surname ==> ";
    cin.getline(house.owner.surname, 20);
    cout << "\nOwner's Middle name ==> ";
    cin.getline(house.owner.middle_name, 20);
    cout << "\nAddress of the House ==> ";
    cin.getline(house.address, 100);
    cout << "\nHeight of the House(meters) ==> ";
    cin >> house.height;
    cin.ignore();
    cout << "\nStoreys count of the House ==> ";
    cin >> house.count_storeys;
    cin.ignore();
    cout << "\nApartaments count of the House ==> ";
    cin >> house.count_apartaments;
    cin.ignore();
    cout << "\nDay where the house built was ==> ";
    cin >> house.constr_date.day;
    cin.ignore();
    cout << "\nMonth number where the house built was ==> ";
    cin >> house.constr_date.month;
    cin.ignore();
    cout << "\nMonth name where the house built was ==> ";
    cin.getline(house.constr_date.mon_name, 20);
    cout << "\nYear where the house built was ==> ";
    cin >> house.constr_date.year;
    cin.ignore();
    cout << "\nMaterials from which building was built ==> ";
    cin.getline(house.material, 200);
    cout << "\nCost of per square meter(UAH)  ==> ";
    cin >> house.cost_sq_metr;
    cin.ignore();
}

void Add_object(House *&arr, int &size)
{
    if (size == 0) //если пусто ,просто создать один пункт
    {
        arr = new House[1];
    }
    else // если не пусто ресайз и добавление
    {
        House *tmp = new House[size + 1];
        for (int i = 0; i < size; i++)
        {
            tmp[i] = arr[i];
        }
        delete[] arr;
        arr = tmp;
    }
    Set_object(arr[size]);
    size++;
}

void Remove_object(House *&arr, int &size, int pos) // удаление обьекта целиком
{
    if (pos < 0 || pos >= size) // эксепшн , если позиция за пределами ,защита от вылетов
    {
        return;
    }
    House *tmp = new House[--size];
    for (int i = 0, j = 0; i < size; j++, i++) //пересоздает массив исключая ненужный обьект
    {
        if (i == pos)
        {
            j++;
        }
        tmp[i] = arr[j];
    }
    delete[] arr;
    arr = tmp;
}

void First_obj(House *&arr, int &size, House &hibara) // создание записей ,чтоб меньше кликать
{
    arr = new House[1];
    strcpy(hibara.owner.name, "Petr");
    strcpy(hibara.owner.surname, "Petrov");
    strcpy(hibara.owner.middle_name, "Petrovich");
    strcpy(hibara.address, "Kozyatin, Niszhebrodskaya 1/1");
    hibara.height = 1;
    hibara.count_storeys = 1;
    hibara.count_apartaments = 1;
    hibara.constr_date.day = 1;
    hibara.constr_date.month = 9;
    strcpy(hibara.constr_date.mon_name, "December");
    hibara.constr_date.year = 1876;
    strcpy(hibara.material, "Crov',pot,palki,othodu");
    hibara.cost_sq_metr = 500;
    arr[size] = hibara;
    size++;
}

void Second_obj(House *&arr, int &size, House &penthouse) // создание записей ,чтоб меньше кликать
{
    House *tmp = new House[size + 1];
    for (int i = 0; i < size; i++)
    {
        tmp[i] = arr[i];
    }
    delete[] arr;
    arr = tmp;

    strcpy(penthouse.owner.name, "Suleyman");
    strcpy(penthouse.owner.surname, "Ahmudov");
    strcpy(penthouse.owner.middle_name, "Ivanovich");
    strcpy(penthouse.address, "Dubai, Tebezdesnemesto 122/1z");
    penthouse.height = 222;
    penthouse.count_storeys = 122;
    penthouse.count_apartaments = 244;
    penthouse.constr_date.day = 22;
    penthouse.constr_date.month = 6;
    strcpy(penthouse.constr_date.mon_name, "June");
    penthouse.constr_date.year = 2019;
    strcpy(penthouse.material, "Gold,adamantyte,silver,voodoo magic");
    arr[size] = penthouse;
    size++;
}

void Edit_object(House *&arr, int pos, int choice) // нужно допилить!!! частичное и полное редактирование
{
    House &house = arr[pos];

    cout << "\nOwner's Name ==> ";
    cin.getline(house.owner.name, 20);
    cout << "\nOwner's Surname ==> ";
    cin.getline(house.owner.surname, 20);
    cout << "\nOwner's Middle name ==> ";
    cin.getline(house.owner.middle_name, 20);
    cout << "\nAddress of the House ==> ";
    cin.getline(house.address, 100);
    cout << "\nHeight of the House(meters) ==> ";
    cin >> house.height;
    cin.ignore();
    cout << "\nStoreys count of the House ==> ";
    cin >> house.count_storeys;
    cin.ignore();
    cout << "\nApartaments count of the House ==> ";
    cin >> house.count_apartaments;
    cin.ignore();
    cout << "\nDay where the house built was ==> ";
    cin >> house.constr_date.day;
    cin.ignore();
    cout << "\nMonth number where the house built was ==> ";
    cin >> house.constr_date.month;
    cin.ignore();
    cout << "\nMonth name where the house built was ==> ";
    cin.getline(house.constr_date.mon_name, 20);
    cout << "\nYear where the house built was ==> ";
    cin >> house.constr_date.year;
    cin.ignore();
    cout << "\nMaterials from which building was built ==> ";
    cin.getline(house.material, 200);
    cout << "\nCost of per square meter(UAH)  ==> ";
    cin >> house.cost_sq_metr;
    cin.ignore();
}

int main()
{
    int size = 0;
    bool flag = true;
    House *arr = nullptr; // создание пустого массива

    House hibara;
    House penthouse;
    First_obj(arr, size, hibara);
    Second_obj(arr, size, penthouse);

    while (flag)
    {
        int pos = -1;
        cout << "What you want to do :\n";
        cout << "\n\n";
        cout << "a) Print all houses;\n";
        cout << "b) Print House by position;\n";
        cout << "c) Remove home by position;\n";
        cout << "d) Add house to array;\nESC - выход\n";
        char key = getchar();
        switch (key)
        {
        case 100: // d) добавление нового дома
            Add_object(arr, size);
            break;
        case 99: // c) удаления дома по позиции.
            cout << "Enter position ==> ";
            cin >> pos;
            cin.ignore();
            Remove_object(arr, size, pos);
            break;
        case 98: // b) вывод конкретного дома по позиции
            system("clear");
            cout << "Enter position ==> ";
            cin >> pos;
            cin.ignore();
            if (pos > 0 && pos <= size)
            {
                cout << "===============================_ " << pos << "_===============================" << endl;
                Print_Buiding(arr[pos - 1]);
                cout << "==================================================================\n"
                     << endl;
            }
            else
            {
                cout << "Error! Wrong position! " << endl;
            }
            break;
        case 97: // a) Показывает все дома;
            system("clear");
            for (int i = 0; i < size; i++)
            {
                cout << "===============================_ " << i + 1 << "_===============================" << endl;
                Print_Buiding(arr[i]);
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

    //Edit_object(arr, 0, 1);

    if (size) //если массив не пустой - очистить память
    {
        delete[] arr;
    }
}