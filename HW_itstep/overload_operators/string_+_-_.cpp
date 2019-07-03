#include <iostream>
#include <string.h>
using namespace std;

/* 
 Для класса MyString, из предыдущих заданий, перегрузить операторы:
 - S1++ (добавление пробелов между символами, (при каждым вызове
 увеличивается));
 - S1-- (удаление пробелов между символами, (при каждым вызове
 уменьшается));
 - Ввод/вывод данных.

 ищите "_HOME_WORK_PART_" в коде
 */

class MyString
{
private:
    char *str;
    int capacity = 80;

public:
    //=========================================================================================================
    //=======================================_КОНСТРУКТОРЫ_====================================================
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

    MyString(const char *s) // конструктор с параметрами (строка) (чтобы принять литерал(без варнинга)нужно через const)
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

    //=========================================================================================================
    //=======================================_МЕТОДЫ_==========================================================
    //=========================================================================================================

    void Print() const // вывод строки (константный т.к. ничего не меняет)
    {
        cout << str << endl;
    }

    void Input(const char *new_str) // ввод новой строки (замена)
    {
        if (strlen(new_str) + 1 > capacity) // если размер больше старого ,то строка пересоздается и копируется , ф-я(метод) завершается
        {
            delete[] str;
            str = strdup(new_str);
            capacity = strlen(str) + 1;
            return;
        }
        strcpy(str, new_str);
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
    }

    friend MyString operator+(char t, const MyString &obj); // прототип дружественной ф-и ( если первый операнд литерал)

    MyString operator+(const char *new_str) const // «+» - объеденяет две строки в одну;
    {
        MyString tmp(getSize() + strlen(new_str) + 1);
        strcpy(tmp.str, str);
        strcat(tmp.str, new_str);
        return tmp;
    }
    MyString operator+(MyString &obj) const // «+» - объеденяет две строки в одну;
    {
        MyString tmp(getSize() + strlen(obj.str) + 1);
        strcpy(tmp.str, str);
        strcat(tmp.str, obj.str);
        return tmp;
    }
    friend MyString operator+(const char *new_str, const MyString &obj); // «+» - объеденяет две строки в одну;

    MyString operator-(const char *new_str) const // «-» - удаляет подстроку в строке.
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

    MyString operator-(MyString &obj) const // «-» - удаляет подстроку в строке.
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

    bool operator==(const MyString &obj) { return strcmp(str, obj.str) == 0; } // сравнивание строк на идентичность

    bool operator>(const MyString &obj) { return strcmp(str, obj.str) > 0; } // сравнивание строк ,больше ли левая

    bool operator<(const MyString &obj) { return strcmp(str, obj.str) < 0; } // сравнивание строк , больше ли правая

    MyString &operator=(const char *new_str) // тоже что и Input ,присваивает строку литералов
    {
        if (strlen(new_str) + 1 > capacity) // если размер больше старого ,то строка пересоздается и копируется , ф-я(метод) завершается
        {
            delete[] str;
            str = strdup(new_str);
            capacity = strlen(str) + 1;
        }
        strcpy(str, new_str);
    }

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

    //======================================================================================
    //=======================================_HOME_WORK_PART_===============================
    //======================================================================================

    MyString &operator++() // S1++ (добавление пробелов между символами, (при каждым вызове увеличивается));
    {
        char *tmp = new char[capacity * 2];

        for (size_t i = 0, j = 0; i < capacity - 1; i++, j++)
        {
            tmp[j] = str[i];
            j++;
            tmp[j] = ' ';
        }
        capacity *= 2;

        delete[] str;
        str = tmp;
    }

    MyString &operator--() // S1-- (удаление пробелов между символами, (при каждым вызове уменьшается));
    {
        if (strchr(str, ' ')) // проверяем или есть пробелы
        {

            char buf[capacity]{}; // создаем временный массив,такого же размера ,т.к. не знаем сколько пробелов
            for (size_t i = 0, j = 0; i < capacity; i++, j++)
            {
                if (i < capacity - 2 && str[i - 1] == ' ' && str[i] == ' ' && str[i + 1] == ' ') // когда пробел между пробелами , i+=2 ,чтобы избежать повторного сравнения
                {
                    i += 2;
                    buf[j + 1] = str[i + 1];
                }
                if (i < capacity - 1 && str[i] == ' ' && str[i + 1] != ' ') // если не два пробела подряд ,то удаляем пробел(пропускаем текущий символ)
                {

                    i++;
                }
                buf[j] = str[i];
            }

            capacity = strlen(buf) + 1;     // пересчитываем размер массива
            char *tmp = new char[capacity]; // создаем динамический массив такого размера,как строка с удаленными пробелами
            strcpy(tmp, buf);               //копируем эту строку
            delete[] str;                   //удаляем память под старый массив
            str = tmp;                      // меняем указатель на новый массив
        }
        else
            return *this; // если проблелов нет ,возвращаем копию того же обьекта
    }

    friend ostream &operator<<(ostream &os, const MyString &obj) // добавление острима(cout) как френндли вывода  ,для работы с классом
    {
        os << obj.str;
        return os;
    }

    friend istream &operator>>(istream &is, MyString &obj) // добавление истрима(cin) как френндли ввода  ,для работы с классом !!ДИЧЬ КАКАЯ-ТО!!
    {
        is.getline(obj.str, 255); // для считывания пробелов !!ОТКУДА ОН БЕРЕТ ПАМЯТЬ И РАЗМЕР ,ЕСЛИ ОН МЕНЬШЕ БЫЛ!!!
        //is >> obj.str;
        obj.capacity = strlen(obj.str) + 1;
        return is;
    }
};

int main()
{

    cout << "\n\t\t_HOME_WORK_PART_" << endl;
    MyString HW("Home");
    MyString HW2("work");
    cin >> HW;
    cout << HW << " & " << HW2 << endl;
    ++HW;
    HW.Print();
    ++HW;
    HW.Print();
    --HW;
    HW.Print();
    --HW;
    HW.Print();
    --HW;
    HW.Print();
}

MyString operator+(char t, const MyString &obj) // дружественная ф-я , для случаев ,когда СНАЧАЛА литерал
{
    MyString tmp(obj.getSize() + 2);
    tmp.str[0] = t;
    strcat(tmp.str, obj.str);
    return tmp;
}

MyString operator+(const char *new_str, const MyString &obj) // «+» - объеденяет две строки в одну;
{
    MyString tmp(obj.getSize() + strlen(new_str) + 1);
    strcpy(tmp.str, new_str);
    strcat(tmp.str, obj.str);
    return tmp;
}
