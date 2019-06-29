#include <iostream>
#include <string.h>

using namespace std;

// если запрещен конструктор копирования , то не будет работать и перегруженый оператор присваевания =

class Array
{
private:
    int size = 0;
    int *arr = nullptr;

public:
    Array(int s);
    Array() = default; // default - аналог пустых скобок

    //Array(const Array &obj) = delete; // delete запрещает вызывать ,тоесть НИКТО НИКОГДА НЕ СМОЖЕТ ВЫЗЫВАТЬ КОНСТУРКТОРЫ КОПИРОВАНИЯ
    // (принимает константную ссылку на обьект)

    Array(const Array &obj); // конструктор копирования

    Array(Array &&obj); // конструктор перемещения
    ~Array();

    int getItem(int pos) const
    {
        return arr[pos];
    }
    int getSize() const
    {
        return size;
    }
    void setItem(int pos, int val)
    {
        arr[pos] = val;
    }
    int operator[](int pos) const { return arr[pos]; } // перегрузка по константности индексирования (ВОЗВРАЩАЕТ КОПИЮ)
    int &operator[](int pos) { return arr[pos]; }      // перегрузка по константности индексирования (ВОЗВРАЩАЕТ ССЛЫКУ НА ОБЬЕКТ)

    Array &operator=(const Array &obj) // немного больше ,потому что проверяет на нулевую размерность (что необязательно)
    {
        if (this == &obj) // сравнение двух АДРЕСОВ в памяти, т.к. обекты могут быть одинаковы а адрес - нет
        {
            return *this;
        }

        if (size)
        {
            delete[] arr; // удалаяем память левого обьекта
            arr = nullptr;
        }
        size = obj.size;
        if (size == 0)
        {
            return *this;
        }
        arr = new int[size];
        for (size_t i = 0; i < size; i++)
        {
            arr[i] = obj.arr[i];
        }
        return *this;
    }
    Array &operator=(Array &&obj) // конструктор перемещения    
    {
        if (this == &obj)
        {
            return *this;
        }
        if (size)
            delete[] arr;
        arr = obj.arr;
        size = obj.size;
        obj.size = 0;
        obj.arr = nullptr;
        return *this;
    }
};

int main()
{
    Array a(12);
    //Array b =a; // error , запрешено
    //Array b = move(a);

    for (size_t i = 0; i < a.getSize(); i++)
    {
        //a.setItem(i, rand() % 20 + 15);
        a[i] = rand() % 20 + 15;
    }
    const Array b = a;

    for (size_t i = 0; i < b.getSize(); i++)
    {
        //cout << a.getItem(i) << " ";
        cout << b[i] << " ";
    }
}

Array::Array(int s) : size(s) // конструктор с параметрами
{
    arr = new int[size]{};
    //int *arr = new int[size]{}; // ЕСЛИ ВЫДЕЛЯТЬ ТАК , ТО БУДЕТ ЛОКАЛЬНО И УДАЛИТСЯ ПОТОМ
}
Array::Array(const Array &obj) // можно сделать как приватный ,чтоб сам не генерил (плохой старый способ)
{
    size = obj.size;
    if (size == 0) // на всякий случай , new не будет выделять память ,если размер массива ноль
    {
        return;
    }
    arr = new int[size];
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = obj.arr[i];
    }
}
Array::Array(Array &&obj) // конструктор перемещения
{
    size = obj.size;
    arr = obj.arr;
    obj.arr = nullptr;
    obj.size = 0;
}
Array::~Array()
{
    if (size)
    {
        delete[] arr;
    }
}
