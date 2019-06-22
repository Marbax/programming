#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

class Point3D
{
private:
    int x;
    int y;
    int z;

public:
    Point3D(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z)
    {
    }
    friend ostream &operator<<(ostream &os, const Point3D &obj)
    {
        os << " X = " << obj.x << " Y = " << obj.y << " Z = " << obj.z << endl;
        return os;
    }
};

class Point
{
private:
    char *name = nullptr;
    int x;
    int y;

public:
    explicit Point(const char *n, int x = 0, int y = 0) : x(x), y(y) // список инициализации (не нужно явно писать this )
                                                                     // explicit запрещает неявный вызов метода
    {
        name = strdup(n);
    }
    Point(const Point &obj) // конструктор копирования
    {
        x = obj.x;
        y = obj.y;
        name = strdup(obj.name);
    }
    Point(Point &&obj) // конструктор перемещения
    {
        x = obj.x;
        y = obj.y;
        name = obj.name;
        obj.name = nullptr;
    }
    ~Point() // деструктор
    {
        delete[] name;
    }
    void setName(const char *s) // сеттер для имени
    {
        if (s) // защита от вылетов
        {
            delete[] name;
            name = strdup(s);
        }
    }
    const char *getName() // геттер для имени
    {
        return name;
    }
    int getX() const
    {
        return x;
    }
    void setX(int x)
    {
        this->x = x;
    }
    int getY() const
    {
        return y;
    }
    void setY(int y)
    {
        this->y = y;
    }
    void Print() const
    {
        cout << name << ":\nX = " << x << " Y = " << y << endl;
    }
    Point operator+(const Point &obj) // перегрузка оператор плюсования
    {
        return Point("new_name ", x + obj.x, y + obj.y);
        //return {x + obj.x, y + obj.y}; // аналог тому что выше с 11 стандарта
    }
    Point operator+(int val) // вариант для передачи лиералов
    {
        return Point("new_name ", x + val, y + val);
    }
    bool operator==(const Point &obj)
    {
        return x == obj.x && y == obj.y; // сравнивание совпадения
    }
    bool operator!=(const Point &obj)
    {
        //return x != obj.x || y != obj.y; // сравнивание различия
        return !(*this == obj); // переиспользование ф-и сравнения совпадения, то же что и выше
    }
    Point &operator=(const Point &obj) // перегрузка присваивания(копирования)
    {
        cout << "\nCOPY" << endl;
        if (this == &obj) // сравнение двух АДРЕСОВ в памяти, т.к. обекты могут быть одинаковы а адрес - нет
        {
            return *this;
        }

        delete[] name; // удалаяем память левого обьекта
        x = obj.x;
        y = obj.y;
        name = strdup(obj.name);
        return *this;
    }
    Point &operator=(Point &&obj) // перегрузка присваивания(перемещения)
    {
        cout << "\nMOVE" << endl;
        if (this == &obj)
        {
            return *this;
        }
        delete[] name;

        x = obj.x;
        y = obj.y;
        name = obj.name;
        obj.name = nullptr;

        return *this;
    }

    //-------------------------- перегрузка унарных операторов----------------------------------------

    Point &operator++() // по дэфолту принимает один параметр, префиксная форма инкремента
    {
        x++;
        y++;
        return *this;
    }
    Point &operator++(int) // по дэфолту принимает один параметр , постфиксная форма инкремента
    {
        x++;
        y++;
        return *this;
    }
    Point &operator--() // по дэфолту принимает один параметр, префиксная форма декремента
    {
        x--;
        y--;
        return *this;
    }
    Point &operator--(int) // по дэфолту принимает один параметр , постфиксная форма декремента
    {
        x--;
        y--;
        return *this;
    }
    friend ostream &operator<<(ostream &os, const Point &obj) // добавление острима как френндли вывода  ,для работы с классом
    {
        os << obj.name << " X = " << obj.x << " Y = " << obj.y << endl;
        return os;
    }
    friend istream &operator>>(istream &is, Point &obj) // добавление истрима как френндли ввода  ,для работы с классом
    {
        cout << "enter x-> ";
        is >> obj.x;
        cout << "enter y-> ";
        is >> obj.y;
        return is;
    }

    // приведение типов , абстрактного к стандартному , абстрактного к абстрактному

    explicit operator int() // запретит использовать ,если не интовые ( НЕ РАБОТАЕТ ,ПОТОМУ ЧТО ПРИСУТСТВУЕТ ЧАРОВСКОЕ ПОЛЕ)
    {
        return sqrt(pow(x, 2) + pow(y, 2));
    }
    explicit operator double() // запретит использовать ,если не интовые
    {
        return sqrt(pow(x, 2) + pow(y, 2));
    }
    operator Point3D()
    {
        return Point3D(x, y, 12);
    }
};

int main()
{
    Point a("a", 12, 23), b("b", 44, 45);
    a.Print();
    cout << endl;

    Point c = a + b; // изначально не понимает как складывать
    c.Print();
    cout << endl;

    Point d = a + 10; // думает что это конструктор , а потом вызывает копирование ,а потом  перегрузку оператора +
                      // експилисит запрещает неявный вызов метода

    // Point g = a.operator+(10); // явный вызов оператора перегрузки
    d.Print();
    cout << endl;

    cout << "\nSravnenie : " << endl;

    if (a == b) // изначально не понимает как сравнивать
    {
        cout << "+++" << endl;
    }
    else
    {
        cout << "---" << endl;
    }
    if (a != b) // изначально не понимает как сравнивать
    {
        cout << "!=" << endl;
    }
    else
    {
        cout << "==" << endl;
    }

    cout << "\nCopy and move" << endl;
    Point l("!!!");
    l = b;
    l.Print();
    l = move(a);
    l.Print();

    cout << "\nIncrement decrement" << endl;
    Point k("dfdfsf", 1, 1);
    k = b++; // ф-я всегда отработает ДО присвоения в переменную, то есть без разници какая форма
    k.Print();

    cout << "\nPereopred ostrem" << endl;
    Point m("olo", 12, 44);
    cout << m << endl;
    cin >> m;
    cout << m << endl;

    cout << "\nPereopred typov" << endl;
    Point f("asd", 3, 4);
    int pifag = f;
    cout << pifag << endl;

    cout << "\nPereopred abstractnuh typov" << endl;
    Point3D q = f;
    cout << q << endl;
}
