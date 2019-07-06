#include <iostream>
#include <stdarg.h> // библиотека с макросами для работы с  ...

using namespace std;

class Vector
{
private:
    size_t size = 0; // при копировании и тд проверять.перебирать до сайза

    size_t capacity = 0; //size * 2; // если равны , то capacity делать в два раза больше
                         //(чтобы уменьшить количесво раз перевыделения памяти,
                         //т.к. это медленная операция)
    int *arr = nullptr;

public:
    Vector() = default; //Конструктор по умолчанию. Не принимает аргументов, создает
                        //новый экземпляр вектора

    Vector(const int n, const int val); //Создает вектор с n объектами со значениями val

    Vector(const Vector &obj); // Конструктор копии по умолчанию. Создает копию вектора obj
    ~Vector();

    Vector &operator=(const Vector &obj) //Копирует значение одного вектора в другой.
    {
        if (this == &obj)
            return *this;

        if (capacity)
        {
            delete[] arr; // удалаяем память левого обьекта
            arr = nullptr;
        }
        size = obj.size;
        capacity = obj.capacity;
        if (capacity == 0)
        {
            return *this;
        }
        arr = new int[capacity];
        for (size_t i = 0; i < size; i++)
        {
            arr[i] = obj.arr[i];
        }
        return *this;
    }
    Vector &operator=(Vector &&obj) // конструктор перемещения
    {
        if (this == &obj)
        {
            return *this;
        }
        if (size)
            delete[] arr;
        arr = obj.arr;
        size = obj.size;
        capacity = obj.capacity;
        obj.size = 0;
        obj.capacity = 0;
        obj.arr = nullptr;
        return *this;
    }

    bool operator==(const Vector &obj) //Сравнение двух векторов - равны
    {
        if (size == obj.size)
        {
            for (size_t i = 0; i < size; i++)
            {
                if (arr[i] != obj.arr[i])
                    return false;
            }
            return true;
        }
        return false;
    }
    bool operator!=(const Vector &obj) { return !(*this == obj); } //Сравнение двух векторов - не равны

    bool operator<(const Vector &obj) //Сравнение двух векторов - левый меньше
    {
        if (size > obj.size) // если кол-во эллементов вектора больше ,то он больше,конец
            return false;

        if (size == obj.size) // если кол-во эллементов равно
        {
            for (size_t i = 0; i < size; i++)
            {
                if (arr[i] >= obj.arr[i]) // если ,хоть один эллемент больше ,то вектор больше , конец
                    return false;
            }
            return true; // если небыло эллемента больше или равного ,значит все меньше , конец
        }
        return true; // если эллементов не больше и не одинаково ,то их меньше ,вектор меньше ,конец
    }

    bool operator>(const Vector &obj) //Сравнение двух векторов - левый больше
    {
        if (size < obj.size)
        {
            return false;
        }

        if (size == obj.size)
        {
            for (size_t i = 0; i < size; i++)
            {
                if (arr[i] <= obj.arr[i])
                    return false;
            }
            return true;
        }
        return true;
    }

    bool operator<=(const Vector &obj) //Сравнение двух векторов - левый меньше или равен
    {
        if (*this == obj || *this < obj)
            return true;

        else
            return false;
    }
    bool operator>=(const Vector &obj) //Сравнение двух векторов - левый больше или равен
    {
        if (*this == obj || *this > obj)
            return true;

        else
            return false;
    }

    int operator[](int pos) const { return arr[pos]; } //Доступ к определенному элементу
    int &operator[](int pos) { return arr[pos]; }      //Доступ к определенному элементу
    bool Empty() { return size == 0; }                 //Возвращает true, если вектор пуст
    int getSize() { return size; }                     //Возвращает количество элементов вектора
    int getCapacity() { return capacity; }             //Возвращает размер выделенной памяти

    void Clear() //Удаляет все элементы вектора
    {
        if (size)
        {
            delete[] arr;
            size = 0;
            capacity = 0;
            arr = nullptr;
        }
    }

    void Reloc() // меняет размер выделяемой памяти
    {
        size_t tmp_capacity = (capacity ? capacity : 1) * 2; // если было ноль то станет 1
        int *tmp = new int[tmp_capacity];
        for (size_t i = 0; i < size; i++)
        {
            tmp[i] = arr[i];
        }
        delete[] arr;
        arr = tmp;
        capacity = tmp_capacity;
    }

    void Push_back(int value) // Вставка элемента в конец вектора
    {
        if (size + 1 > capacity)
            Reloc();

        arr[size] = value;
        size++;
    }

    void Resize(int new_size) // Изменяет размер вектора на заданную величину
    {
        if (new_size >= 0)
        {
            if (size)
            {
                while (size >= new_size)
                {
                    arr[size] = 0;
                    --size;
                }

                size = new_size;
            }
            else
            {
                Vector tmp(new_size, 0);
                *this = move(tmp);
            }
        }
    }

    /* void Insert(int pos, int val) //Вставка элемента(одного) в вектор !!КОНФЛИКТУЕТ!!
    {
        if (pos < size && pos >= 0)
        {
            //++size;
            if (size + 1 > capacity)
            {
                size_t tmp_capacity = (capacity ? capacity : 1) * 2; // если было ноль то станет 1
                int *tmp = new int[tmp_capacity];
                for (size_t i = 0, j = 0; i < size; i++, j++)
                {
                    if (i == pos)
                    {
                        tmp[j] = val;
                        j++;
                    }

                    tmp[j] = arr[i];
                }
                delete[] arr;
                arr = tmp;
                capacity = tmp_capacity;
                size++;
            }
        }
    } */

    void Insert(int pos, int count, ...) //Вставка элементов в вектор
    {
        if (size)
        {
            while (size + count > capacity)
            {
                Reloc();
            }

            int *tmp = new int[capacity];
            va_list list;
            va_start(list, count);

            for (size_t j = 0, l = 0; j < size + count; j++, l++)
            {
                if (j == pos)
                {
                    for (size_t i = 0; i < count; i++)
                    {
                        tmp[j] = va_arg(list, int);
                        j++;
                    }
                }
                tmp[j] = arr[l];
            }

            va_end(list);
            delete[] arr;
            arr = tmp;
            size += count;
        }
    }

    void Erase(int count, ...) //  Удаляем указанные элементы вектора 
    {
        if (size)
        {
            size_t size_dif = 0;
            int *tmp = new int[capacity];
            for (size_t j = 0, l = 0; j < size; j++, l++)
            {
                va_list list;
                va_start(list, count);
                for (size_t i = 0; i < count; i++)
                {
                    if (va_arg(list, int) == arr[l])
                    {
                        size_dif++;
                        l++;
                        break;
                    }
                }
                tmp[j] = arr[l];
                va_end(list);
            }
            delete[] arr;
            arr = tmp;
            size -= size_dif;
        }
    }

    /* void Erase(int val) //  Удаляем указанные элементы вектора (один) !!КОНФЛИКТУЕТ!!
    {
        if (size)
        {
            size_t size_dif = 0;
            int *tmp = new int[capacity];
            for (size_t j = 0, l = 0; j < size; j++, l++)
            {
                while (arr[l] == val)
                {
                    size_dif++;
                    l++;
                }

                tmp[j] = arr[l];
            }
            delete[] arr;
            arr = tmp;
            size -= size_dif;
        }
    } */

    void Pop_back() // Удалить последний элемент вектора
    {
        if (size)
        {
            arr[size] = 0;
            --size;
        }
    }

    void Print()
    {
        if (size)
        {
            for (size_t i = 0; i < size; i++)
            {
                cout << arr[i] << " ";
            }
            //cout << "   size = " << size << endl;
            cout << endl;
        }
        else
            cout << "Empty" << endl;
    }
};

int main()
{
    Vector first(5, 1);
    Vector second(5, 5);
    cout << first[0] << first[1] << first[2] << endl;
    cout << second[3] << second[4] << second[5] << endl;
    first.Clear();
    first.Print();
    first.Push_back(12);
    first.Push_back(12);
    first.Insert(1, 5, 1, 2, 3, 4, 5);
    first.Print();
    first.Insert(2, 2, 100, 100);
    first.Print();
    first.Erase(2, 12, 4);
    first.Print();
    first.Erase(1, 2);
    first.Print();
    first.Pop_back();
    first.Print();
    first.Insert(0, 1, 1000);
    first.Print();
    first.Resize(3);
    first.Print();
    first.Resize(10);
    first.Print();
}

Vector::Vector(const int n, const int val) : size(n), capacity(n * 2) //Создает вектор с n объектами со значениями val
{
    arr = new int[capacity]{};
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = val;
    }
}

Vector::Vector(const Vector &obj) // Конструктор копии по умолчанию. Создает копию вектора obj
{
    size = obj.size;
    capacity = obj.capacity;
    arr = new int[capacity];
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = obj.arr[i];
    }
}

Vector::~Vector()
{
    if (capacity)
    {
        delete[] arr;
    }
}
