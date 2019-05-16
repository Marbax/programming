#include <iostream>
#include <string.h>
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

void Print_Owner(F_name owner) // вывод инфы о владельце
{
    cout << "Owner : " << owner.surname << " " << owner.name << " " << owner.middle_name << endl;
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
    cout << "\nCount of storeys in the house ==> ";
    cin >> house.count_storeys;
    cin.ignore();
    cout << "\nCount of apartaments in the house ==> ";
    cin >> house.count_apartaments;
    cin.ignore();
    cout << "\nDay when the house built was ==> ";
    cin >> house.constr_date.day;
    cin.ignore();
    cout << "\nMonth number when the house built was ==> ";
    cin >> house.constr_date.month;
    cin.ignore();
    cout << "\nMonth name when the house built was ==> ";
    cin.getline(house.constr_date.mon_name, 20);
    cout << "\nYear when the house built was ==> ";
    cin >> house.constr_date.year;
    cin.ignore();
    cout << "\nMaterials from which building was built ==> ";
    cin.getline(house.material, 200);
    cout << "\nCost of per square meter(UAH)  ==> ";
    cin >> house.cost_sq_metr;
    cin.ignore();
}

void Add_object(House *&arr, int &size) // пересбор массива с новым обьектом
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

void Edit_object(House *&arr, int size, int pos) // частичное и полное редактирование
{
    if (pos > 0 && pos <= size)
    {

        House &house = arr[pos - 1];
        bool flag = true;
        while (flag)
        {
            system("clear");
            cout << "===============================_ " << pos << "_===============================" << endl;
            Print_Buiding(arr[pos - 1]);
            cout << "==================================================================\n"
                 << endl;
            cout << "Would you want to do ?\n"
                 << endl;
            cout << "a) Fully edit the object;" << endl;
            cout << "b) Edit the owner's name;" << endl;
            cout << "c) Edit the owner's surname;" << endl;
            cout << "d) Edit the owner's middle name;" << endl;
            cout << "e) Edit address of the house;" << endl;
            cout << "f) Edit height of the house;" << endl;
            cout << "g) Edit storeys count of the house;" << endl;
            cout << "h) Edit apartaments count of the house;" << endl;
            cout << "i) Edit built day of the house;" << endl;
            cout << "j) Edit built month of the house;" << endl; // месяц и имя месяца
            cout << "k) Edit built year of the house;" << endl;
            cout << "l) Edit materials from which house was built" << endl;
            cout << "m) Edit the cost of per square meter in the house;\nESC to exit" << endl;
            cout << "\nYour choice ==>  " << endl;
            char key = getchar();
            cin.ignore();

            if (int(key) == 97 || key == 98)
            {
                system("clear");
                cout << "Old Name of the owner==> " << house.owner.name << endl;
                cout << "\nNew Name of the owner==> ";
                cin.getline(house.owner.name, 20);
            }
            if (int(key) == 97 || int(key) == 99)
            {
                system("clear");
                cout << "Old Surname of the owner ==> " << house.owner.surname << endl;
                cout << "\nNew Surname of the owner ==> ";
                cin.getline(house.owner.surname, 20);
            }
            if (int(key) == 97 || int(key) == 100)
            {
                system("clear");
                cout << "Old Middle name of the owner ==> " << house.owner.middle_name << endl;
                cout << "\nNew Middle name of the owner ==> ";
                cin.getline(house.owner.middle_name, 20);
            }
            if (int(key) == 97 || int(key) == 101)
            {
                system("clear");
                cout << "Old address of the house ==> " << house.address << endl;
                cout << "\nNew address of the house ==> ";
                cin.getline(house.address, 100);
            }
            if (int(key) == 97 || int(key) == 102)
            {
                system("clear");
                cout << "Old height of the house ==> " << house.height << " (meters)" << endl;
                cout << "\nNew height of the house ==> ";
                cin >> house.height;
                cin.ignore();
            }
            if (int(key) == 97 || int(key) == 103)
            {
                system("clear");
                cout << "Old count of storeys in the house ==> " << house.count_storeys << endl;
                cout << "\nNew count of storeys in the house ==> ";
                cin >> house.count_storeys;
                cin.ignore();
            }
            if (int(key) == 97 || int(key) == 104)
            {
                system("clear");
                cout << "Old count of apartaments in the house ==> " << house.count_apartaments << endl;
                cout << "\nNew count of apartaments in the house ==> ";
                cin >> house.count_apartaments;
                cin.ignore();
            }
            if (int(key) == 97 || int(key) == 105)
            {
                system("clear");
                cout << "Old day when the house built was ==> " << house.constr_date.day << endl;
                cout << "\nNew day when the house built was ==> ";
                cin >> house.constr_date.day;
                cin.ignore();
            }
            if (int(key) == 97 || int(key) == 106)
            {
                system("clear");
                cout << "Old month number when the house built was ==> " << house.constr_date.month << endl;
                cout << "\nNew month number when the house built was ==> ";
                cin >> house.constr_date.month;
                cin.ignore();
                cout << "Old month name when the house built was ==> " << house.constr_date.mon_name << endl;
                cout << "\nNew month name when the house built was ==> ";
                cin >> house.constr_date.mon_name;
                cin.ignore();
            }
            if (int(key) == 97 || int(key) == 107)
            {
                system("clear");
                cout << "Old year when the house built was ==> " << house.constr_date.year << endl;
                cout << "\nNew year when the house built was ==> ";
                cin >> house.constr_date.year;
                cin.ignore();
            }
            if (int(key) == 97 || int(key) == 108)
            {
                system("clear");
                cout << "Old materials from which building was built ==> " << house.material << endl;
                cout << "\nNew materials from which building was built ==> ";
                cin.getline(house.material, 200);
            }
            if (int(key) == 97 || int(key) == 109)
            {
                system("clear");
                cout << "Old cost of per square meter ==> " << house.cost_sq_metr << " (UAH)" << endl;
                cout << "\nNew cost of per square meter ==> ";
                cin >> house.cost_sq_metr;
                cin.ignore();
            }

            if (int(key) == 27)
            {
                flag = false;
            }
        }
    }
    else
    {
        cout << "Error! Wrong position! " << endl;
    }
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
        int pos = 0;
        cout << "What you want to do :\n";
        cout << "\n\n";
        cout << "a) Print all houses;\n";
        cout << "b) Print House by the position;\n";
        cout << "c) Remove home by the position;\n";
        cout << "d) Add house to array;\n";
        cout << "e) Clear the screen;\n";
        cout << "f) Edit object by thr position;\nESC - выход\n";

        char key = getchar();
        cin.ignore();
        switch (key)
        {
        case 102: // f) редактирование обьекта
            system("clear");
            cout << "Enter position ==> ";
            cin >> pos;
            cin.ignore();
            Edit_object(arr, size, pos);
            system("clear");
            break;
        case 101: // e) очистка экрана
            system("clear");
            break;
        case 100: // d) добавление нового дома
            system("clear");
            Add_object(arr, size);
            system("clear");
            break;
        case 99: // c) удаления дома по позиции.
            cout << "Enter position ==> ";
            cin >> pos;
            cin.ignore();
            Remove_object(arr, size, pos);
            system("clear");
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

    if (size) //если массив не пустой - очистить память
    {
        delete[] arr;
    }
    //cout << "END OF PROGRAM\n";
}