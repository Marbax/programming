#include <iostream>
#include <string.h>
using namespace std;

// пример класса с разлычными методами

class MyString
{
private:
    char *str;
    int capacity = 80;

public:
    MyString()
    {
        cout << "\nDef constr" << endl;
        str = new char[capacity]{}; // инициализация нулями , не мусором
    }
    MyString(int c)
    {
        cout << "\nRecap constr" << endl;
        if (c > 0)
            capacity = c;
        str = new char[capacity]{};
    }
    MyString(const char *s) //чтобы принять литерал нужно через const
    {
        cout << "\nWith string constr" << endl;
        str = strdup(s);
        capacity = strlen(str) + 1;
    }
    MyString(const MyString &obj) //конструктор копирования
    {
        cout << "\nCopy constr" << endl;
        capacity = obj.capacity;
        str = new char[capacity];
        strcpy(str, obj.str);
    }
    MyString(MyString &&obj) // r-value ссылка ,конструктор перемещения
    {
        capacity = obj.capacity;
        str = obj.str;
        obj.str = nullptr;
        obj.capacity = 0;
    }
    ~MyString()
    {
        if (capacity)
            delete[] str;
    }
    void Print() const
    {
        cout << str << endl;
    }
    void Input()
    {
        cout << "\nEnter your string :" << endl;
        char buf[1000];
        cin.getline(buf, 1000);
        if (strlen(buf) + 1 > capacity)
        {
            delete[] str;
            str = strdup(buf);
            capacity = strlen(str) + 1;
            return;
        }
        strcpy(str, buf);
    }
    int getSize() const
    {
        return strlen(str);
    }
    int getCapacity() const
    {
        return capacity;
    }

    MyString operator+(char new_char) const // перегрузка оператор плюсования символа к строке
    {
        MyString tmp(getSize() + 2);
        strcpy(tmp.str, str);
        tmp.str[getSize()] = new_char;
        return tmp;
    }
    friend MyString operator+(char t, const MyString &obj); // прототип дружественной ф-и

    MyString operator+(const char *new_str) const // перегрузка оператор плюсования строки к строке
    {
        MyString tmp(getSize() + strlen(new_str) + 1);
        strcpy(tmp.str, str);
        strcat(tmp.str, new_str);
        return tmp;
    }

    bool operator==(const MyString &obj) // сравнивание строк на идентичность
    {
        return strcmp(str, obj.str) == 0;
    }
    bool operator>(const MyString &obj) // сравнивание строк ,больше ли левая
    {
        return strcmp(str, obj.str) > 0;
    }
    bool operator<(const MyString &obj) // сравнивание строк , больше ли правая
    {
        return strcmp(str, obj.str) < 0;
    }
    /* MyString operator=(const char *new_str)  // перегрузка оператор плюсования строки к строке
    {
        MyString tmp(getSize() + strlen(new_str) + 1);
        strcpy(tmp.str, new_str);
        return tmp;
    } */
    MyString &operator=(const MyString &obj) // перегрузка оператор плюсования строки к строке l-value
    {
        if (this == &obj)
        {
            return *this;
        }
        delete[] str;
        capacity = obj.capacity;
        str = new char[capacity];
        strcpy(str, obj.str);
        return *this;
    }
    MyString &operator=(MyString &&obj) // перегрузка оператор плюсования строки к строке r-value
    {
        if (this == &obj)
        {
            return *this;
        }
        delete[] str;
        capacity = obj.capacity;
        str = obj.str;
        obj.str = nullptr;
        return *this;
    }
    MyString operator+(char t, const MyString &obj) // вариант без использования дружественной ф-и ,
                                                    // для случаев ,когда СНАЧАЛА литерал
                                                    // НЕ ДОПИСАН
    {
        char *tmp = new char[obj.getSize() + 2]{};
        tmp[0] = t;
        strcat(tmp, obj.getStr());
        MyString buf(tmp);
        delete[] tmp;
        return buf;
    }
};
/* 
MyString::MyString()
{
}

MyString::~MyString()
{
}
 */
int main()
{
    MyString a("Hello"), b;
    a.Print();
    //b.Input();
    //b.Print();
    MyString c = move(a);
    c.Print();
    MyString z("Hello");
    cout << "\nThere we added one char : " << endl;
    (z + '!').Print();
    cout << "\nThere we added one string to another : " << endl;
    (z + "ololo").Print();
    cout << "\nThere we replace one string with another : " << endl;
    (z = "Replace").Print();
}

MyString operator+(char t, const MyString &obj) // дружественная ф-я , для случаев ,когда СНАЧАЛА литерал
{
    MyString tmp(obj.getSize() + 2);
    tmp.str[0] = t;
    strcat(tmp.str, obj.str);
    return tmp;
}