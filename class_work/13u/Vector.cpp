// конструктор перемещения тоже нужен
// если размер массива одинаковый ,потом если эллементы одинаковые ,сравнение
/* 
vector::clear Удаляет все элементы векторас +-
vector::insert Вставка элементов в вектор +-
vector::erase Удаляем указанные элементы вектора (один или несколько) 
vector::push_back Вставка элемента в конец вектора +
vector::pop_back Удалить последний элемент вектора
vector::resize Изменяет размер вектора на заданную величину
 */

#include <iostream>

using namespace std;

class Vector
{
private:
    size_t size = 0; // при копировании и тд проверять.перебирать до сайза

    size_t capacity = 0; //size * 2; // если равны , то capacity делать в два раза больше
                         //(чтобы уменьшить количесво раз перевыделения памяти,
                         //т.к. это медленная операция)
    size_t *arr = nullptr;

public:
    Vector() = default; //Конструктор по умолчанию. Не принимает аргументов, создает
                        //новый экземпляр вектора

    Vector(const size_t n, const size_t val); //Создает вектор с n объектами со значениями val

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
        arr = new size_t[capacity];
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

    bool operator<(const Vector &obj) //Сравнение двух векторов - левый меньше (что то явно не так)
    {
        if (size > obj.size)
        {
            return false;
        }

        if (size == obj.size)
        {
            for (size_t i = 0; i < size; i++)
            {
                if (arr[i] > obj.arr[i])
                    return false;
            }
            return true;
        }
        return true;
    }

    bool operator>(const Vector &obj) //Сравнение двух векторов - левый больше (что то явно не так)
    {
        if (size < obj.size)
        {
            return false;
        }

        if (size == obj.size)
        {
            for (size_t i = 0; i < size; i++)
            {
                if (arr[i] < obj.arr[i])
                    return false;
            }
            return true;
        }
        return true;
    }

    bool operator<=(const Vector &obj) //Сравнение двух векторов - левый меньше или равен (что то явно не так)
    {
        if (*this == obj || *this < obj)
            return true;

        else
            return false;
    }
    bool operator>=(const Vector &obj) //Сравнение двух векторов - левый больше или равен (что то явно не так)
    {
        if (*this == obj || *this > obj)
            return true;

        else
            return false;
    }

    size_t operator[](size_t pos) const { return arr[pos]; } //Доступ к определенному элементу
    size_t &operator[](size_t pos) { return arr[pos]; }      //Доступ к определенному элементу
    bool Empty() { return size == 0; }                       //Возвращает true, если вектор пуст
    size_t getSize() { return size; }                        //Возвращает количество элементов вектора
    size_t getCapacity() { return capacity; }                //Возвращает размер выделенной памяти

    void Clear() //Удаляет все элементы вектора ( что то может быть не так )  лучше сделать через новый обьект
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
        size_t tmp_capacity = (capacity ? capacity:1) * 2; // если было ноль то станет 1
        size_t *tmp = new size_t[tmp_capacity];
        for (size_t i = 0; i < size; i++)
        {
            tmp[i] = arr[i];
        }
        delete[] arr;
        arr = tmp;
        capacity = tmp_capacity;
    }

    void Push_back(size_t value) // Вставка элемента в конец вектора
    {
        if (size + 1 > capacity)
            Reloc();

        arr[size] = value;
        size++;
    }

    void Insert(size_t pos, size_t val) //Вставка элементов в вектор !!НЕ_ДОДЕЛАН!! проверить
    {
        //++size;
        if (++size > capacity)
        {
            size_t tmp_capacity = (capacity ? capacity:1) * 2; // если было ноль то станет 1
            size_t *tmp = new size_t[tmp_capacity];
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
        }
    }

    void Pop_back(size_t value) // Удалить последний элемент вектора
    {
        if (size)
        {
            --size;
        }
    }
};

Vector::Vector(const size_t n, const size_t val) : size(n), capacity(n * 2) //Создает вектор с n объектами со значениями val
{
    arr = new size_t[capacity]{};
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = val;
    }
}

Vector::Vector(const Vector &obj) // Конструктор копии по умолчанию. Создает копию вектора obj
{
    size = obj.size;
    capacity = obj.capacity;
    arr = new size_t[capacity];
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
