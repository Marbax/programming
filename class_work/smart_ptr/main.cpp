#include <iostream>
#include <memory>

using namespace std;

/* 
умный указатель - такой себе примитивный самописный сброщик мусора 

стандартные поинтеры , библиотека <memory> 
 - auto_ptr - устаревший , похож на уникальный поинтер(ниже)
 - unique_ptr - пришел на смену авто поинтеру
 - shared_ptr - решена проблема указания на один обьект, самый популярный вид

 */

template <class T>
class SmartPointer
{
private:
    T *ptr; // указатель обобщенного типа
public:
    SmartPointer(T *ptr) : ptr(ptr) {}

    ~SmartPointer() { delete ptr; }

    T &operator*() { return *ptr; }
};

int main()
{
    SmartPointer<double> pointer = new double(6.4325235);
    cout << *pointer << endl;

    /*
    auto_ptr<int> ap1(new int(5)); // превращает в псевдо
    auto_ptr<int> ap2(ap1);
 */

    /*
    unique_ptr<int> ap1(new int(5));
    unique_ptr<int> ap2(ap1); // просто не разрешит копировать
 */

    /* 
    shared_ptr<int> ap1(new int(5));
    shared_ptr<int> ap2(ap1); // владеет одними и теми же данными, при уничтожении не будет ошибки ,
    // данные уничтожаются при удалении последей копии.
    // просто считает кол-во ссылок на обьект
    // в деструкторе уменьшается счетчик,если обьект был последний - выполняется очистка
 */

    int SIZE = 15;
    int *arr = new int[SIZE]{1, 2, 4, 6, 7};
    shared_ptr<int[]> ptr(arr);
    //shared_ptr<int[]> ptr(new int[5]{1,2,4,6,7}); // 2в1 того что выше

    for (size_t i = 0; i < SIZE; i++)
    {
        ptr[i] = rand() % 10;
        cout << ptr[1] << endl;
    }
}