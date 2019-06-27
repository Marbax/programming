#include <iostream>
#include <string.h>
using namespace std;

// Для класса MyString, из предыдущего задания, перегрузить операторы:
// • «+» - объединяет две строки в одну;
// • «-» - удаляет подстроку в строке.

class MyString
{
private:
    char *str;
    int capacity = 80;

public:
    //=========================================================================================================
    //=======================================_МЕТОДЫ_==========================================================
    //=========================================================================================================

    MyString() // стандартный конструктор
    {
        cout << "\nDef constr" << endl;
        str = new char[capacity]{}; // инициализация нулями , не мусором
    }

    MyString(int new_capacity) // конструктор с параметрами (размера строки)
    {
        cout << "\nRecap constr" << endl;
        if (new_capacity > 0)
            capacity = new_capacity;
        str = new char[capacity]{};
    }

    MyString(const char *s) // конструктор с параметрами (строка) (чтобы принять литерал нужно через const)
    {
        cout << "\nWith string constr" << endl;
        str = strdup(s);
        capacity = strlen(str) + 1;
    }

    MyString(const MyString &obj) // конструктор копирования (второй обьект константный т.к. не меняется)
    {
        cout << "\nCopy constr" << endl;
        capacity = obj.capacity;
        str = new char[capacity];
        strcpy(str, obj.str);
    }

    MyString(MyString &&obj) // (r-value ссылка) ,конструктор перемещения
    {
        capacity = obj.capacity;
        str = obj.str;
        obj.str = nullptr;
        obj.capacity = 0;
    }

    ~MyString() // деструктор (если у строки есть размер)
    {
        if (capacity)
            delete[] str;
    }

    void Print() const // вывод строки (константный т.к. ничего не меняет)
    {
        cout << str << endl;
    }

    void Input() // ввод новой строки (замена)
    {
        cout << "\nEnter your string :" << endl;
        char buf[1000];
        cin.getline(buf, 1000);
        if (strlen(buf) + 1 > capacity) // если размер больше старого ,то строка пересоздается и копируется , ф-я(метод) завершается
        {
            delete[] str;
            str = strdup(buf);
            capacity = strlen(str) + 1;
            return;
        }
        strcpy(str, buf);
    }

    int getSize() const // геттер количества символов в строке (не учитывая нул)
    {
        return strlen(str);
    }

    int getCapacity() const // геттер рамера массива чаров под строку
    {
        return capacity;
    }

    //=========================================================================================================
    //=======================================_ПЕРЕГРУЖЕННЫЕ_ОПЕРАТОРЫ_=========================================
    //=========================================================================================================

    MyString operator+(char new_char) const // перегрузка оператор плюсования(добавления) символа к строке
    {
        MyString tmp(getSize() + 2);   // создание временного обьекта типа MyString с измененным размером (использую
                                       //геттер + 2 доп елемента под новый символ и нуль символ)
        strcpy(tmp.str, str);          // копирования старой строки во временную
        tmp.str[getSize()] = new_char; // запись в последний елемент массива(по старой версии) нового символа
        return tmp;                    // возвращение временного обьекта
        // ? почему не меняется capacity ?
    }

    friend MyString operator+(char t, const MyString &obj); // прототип дружественной ф-и ( если первый операнд литерал)

    MyString operator+(const char *new_str) const // перегрузка оператор плюсования(добавления) строки к строке
    {
        MyString tmp(getSize() + strlen(new_str) + 1);
        strcpy(tmp.str, str);
        strcat(tmp.str, new_str);
        return tmp;
    }

    MyString operator-(const char *new_str) const // «-» - удаляет подстроку в строке.
    {
        // НЕ ДОПИСАН

        if (strstr(str, new_str))
        {
            MyString tmp(getSize() - strlen(new_str) + 1);
            tmp.str = strtok(str, new_str);
            return tmp;
        }
        else
        {
            return *this;
        }
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

    /* MyString operator=(const char *new_str) 
    {
        MyString tmp(getSize() + strlen(new_str) + 1);
        strcpy(tmp.str, new_str);
        return tmp;
    } */

    MyString &operator=(const MyString &obj) // перегрузка оператор присваевания(КОПИРОВАНИЕ) обьекта к обьекту (l-value)
    {
        if (this == &obj) // если это один и тот же обьект (ячейка в памяти) то возвращает его
        {
            return *this;
        }

        delete[] str;
        capacity = obj.capacity;
        str = new char[capacity];
        strcpy(str, obj.str);
        return *this;
    }

    MyString &operator=(MyString &&obj) // перегрузка оператор присваевания(ПЕРЕМЕЩЕНИЕ) обьекта к обьекту (r-value)
    {
        if (this == &obj) // если это один и тот же обьект (ячейка в памяти) то возвращает его
        {
            return *this;
        }

        delete[] str;
        capacity = obj.capacity;
        str = obj.str;     // меняем указатель на нужную строку
        obj.str = nullptr; // а ее указатель делаем в никуда
        return *this;
    }
    /* 
    MyString operator+(char t, const MyString &obj) // вариант без использования дружественной ф-и ,
                                                     // для случаев ,когда СНАЧАЛА литерал
                                                     // !!!! НЕ ДОПИСАН
    {
        char *tmp = new char[obj.getSize() + 2]{};
        tmp[0] = t;
        strcat(tmp, obj.getStr());
        MyString buf(tmp);
        delete[] tmp;
        return buf;
    }
     */
};

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
