#include <iostream>
#include <string.h>
using namespace std;

// "-" УДАЛИТЬ ВСЕ ВХОЖДЕНИЯ ,А НЕ ТОЛЬКО ПЕРВОЕ
// "+" ДОБАВИТЬ СЛОЖЕНИЕ ОБЬЕКТОВ,А НЕ ТОЛЬКО СТРОКИ

// Для класса MyString, из предыдущего задания, перегрузить операторы:
// • «+» - объединяет две строки в одну;
// • «-» - удаляет подстроку в строке.
// ищите "_HOME_WORK_PART_" в коде

class MyString
{
private:
    char *str;
    int capacity = 80;

public:
    //=========================================================================================================
    //=======================================_КОНСТРУКТОРЫ_И_МЕТОДЫ_===========================================
    //=========================================================================================================

    MyString() // стандартный конструктор
    {
        str = new char[capacity]{}; // инициализация нулями , не мусором
    }

    MyString(int new_capacity) // конструктор с параметрами (размера строки)
    {
        if (new_capacity > 0)
            capacity = new_capacity;
        str = new char[capacity]{};
    }

    MyString(const char *s) // конструктор с параметрами (строка) (чтобы принять литерал нужно через const)
    {
        str = strdup(s);
        capacity = strlen(str) + 1;
    }

    MyString(const MyString &obj) // конструктор копирования (второй обьект константный т.к. не меняется)
    {
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

    MyString operator+(const char *new_str) const // «+» - объединяет две строки в одну; _HOME_WORK_PART_
    {
        MyString tmp(getSize() + strlen(new_str) + 1);
        strcpy(tmp.str, str);
        strcat(tmp.str, new_str);
        return tmp;
    }
    MyString operator+(MyString &obj) const // «+» - объединяет две строки в одну; _HOME_WORK_PART_
    {
        MyString tmp(getSize() + strlen(obj.str) + 1);
        strcpy(tmp.str, str);
        strcat(tmp.str, obj.str);
        return tmp;
    }
    friend MyString operator+(const char *new_str, const MyString &obj); // «+» - объединяет две строки в одну; _HOME_WORK_PART_

    /* 
    MyString operator-(const char *new_str) const // не совсем понятный и баганый метод
    {
        if (strstr(str, new_str))
        {
            MyString tmp(*this);

            char *t = nullptr;
            do
            {
                t = strstr(tmp.str, new_str);
                if (t != NULL)
                {
                    char *t_ = t + strlen(new_str);
                    strcpy(t, t_);
                }
                else
                    break;
            } while (true);

            return tmp;
        }
        else
        {
            return *this;
        }
    }
    */

    MyString operator-(const char *new_str) const // «-» - удаляет подстроку в строке. _HOME_WORK_PART_
    {
        if (strstr(str, new_str))
        {
            MyString tmp(strlen(str));

            for (size_t i = 0, j = 0; i < strlen(str); i++, j++)
            {
                if (str[j] == new_str[0])
                {
                    size_t counter = 0;

                    for (size_t l = 0; l < strlen(new_str) + 1; l++)
                    {
                        if (str[j + l] == new_str[l])
                        {
                            ++counter;
                        }
                        else
                        {
                            break;
                        }

                        if (counter == strlen(new_str))
                        {
                            j += counter;
                        }
                    }
                }
                tmp.str[i] = str[j];
            }

            MyString resized_tmp(strlen(tmp.str));
            strcpy(resized_tmp.str, tmp.str);

            return resized_tmp;
        }
        else
        {
            return *this;
        }
    }

    MyString operator-(MyString &obj) const // «-» - удаляет подстроку в строке. _HOME_WORK_PART_
    {
        if (strstr(str, obj.str))
        {
            MyString tmp(strlen(str));

            for (size_t i = 0, j = 0; i < strlen(str); i++, j++)
            {
                if (str[j] == obj.str[0])
                {
                    size_t counter = 0;

                    for (size_t l = 0; l < strlen(obj.str) + 1; l++)
                    {
                        if (str[j + l] == obj.str[l])
                        {
                            ++counter;
                        }
                        else
                        {
                            break;
                        }

                        if (counter == strlen(obj.str))
                        {
                            j += counter;
                        }
                    }
                }
                tmp.str[i] = str[j];
            }

            MyString resized_tmp(strlen(tmp.str));
            strcpy(resized_tmp.str, tmp.str);

            return resized_tmp;
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
    ('q' + z).Print();

    //======================================================================================
    //=======================================_HOME_WORK_PART_===============================
    //======================================================================================

    cout << "\n\t\t_HOME_WORK_PART_" << endl;
    MyString HW("Home_wowork_is_work_baaad_work_only_for_ork");
    MyString HW2("work");
    HW.Print();
    (HW + "_more_home_work").Print();
    (HW - HW2).Print();
    ("difficult_" + HW - "_bad_bad_bad_baaad" + "_not_baaad" + "_but_need_more_time"-"bad").Print();
}

MyString operator+(char t, const MyString &obj) // дружественная ф-я , для случаев ,когда СНАЧАЛА литерал
{
    MyString tmp(obj.getSize() + 2);
    tmp.str[0] = t;
    strcat(tmp.str, obj.str);
    return tmp;
}

MyString operator+(const char *new_str, const MyString &obj) //_HOME_WORK_PART_
{
    MyString tmp(obj.getSize() + strlen(new_str) + 1);
    strcpy(tmp.str, new_str);
    strcat(tmp.str, obj.str);
    return tmp;
}
