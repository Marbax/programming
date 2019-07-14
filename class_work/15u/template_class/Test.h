#pragma once
#include <iostream>
#include <string.h>
using namespace std;

template <class T> // практически аналогичны template <typename T>
class Test
{
private:
    T data;

public:
    Test() = default;
    Test(T);
    void setData(T);
    T getData();
    Test operator+(const Test &obj);
};

template <class T>
Test<T>::Test(T val)
{
    data = val;
}

template <class T>
void Test<T>::setData(T val)
{
    data = val;
}

template <class T>
T Test<T>::getData()
{
    return data;
}

template <class T>
Test<T> Test<T>::operator+(const Test<T> &obj)
{
    return Test<T>(data + obj.data);
}

//=================================_Расширение_класса_================

template <>
class Test<const char *>
{
private:
    const char *data = nullptr;

public:
    Test() = default;
    Test(const char *);
    Test(const Test &obj);
    Test(Test &&obj);
    Test &operator=(const Test &obj);
    Test &operator=(Test &&obj);
    void setData(const char *);
    const char *getData();
    Test operator+(const Test &obj);
    ~Test();
};

Test<const char *>::Test(const char *s)
{
    data = strdup(s);
}
Test<const char *>::Test(const Test &obj)
{
    data = strdup(obj.data);
}
Test<const char *>::Test(Test &&obj)
{
    swap(data, obj.data);
}
Test<const char *>::~Test()
{
    delete[] data;
}
Test<const char *> &Test<const char *>::operator=(const Test &obj)
{
    if (this == &obj)
    {
        return *this;
    }
    delete[] data;

    data = strdup(obj.data);
    return *this;
}
Test<const char *> &Test<const char *>::operator=(Test &&obj)
{
    if (this == &obj)
    {
        return *this;
    }
    delete[] data;

    data = obj.data;
    obj.data = nullptr;
    return *this;
}

void Test<const char *>::setData(const char *s)
{
    delete[] data;
    data = strdup(s);
}
const char *Test<const char *>::getData()
{
    return data;
}

Test<const char *> Test<const char *>::operator+(const Test &obj)
{
    char *tmp = new char(strlen(data) + strlen(obj.data) + 1);
    strcpy(tmp, data);
    strcat(tmp, obj.data);
    Test<const char *> sum;
    sum.data = tmp;
    return sum;
}

//================================_Частичная_специализация_=======================

template <class T>
class Test<T *>
{
private:
    T *arr = nullptr;
    int size = 0;

public:
    Test() = default;
    Test(int size, T val);
    Test(int size);
    Test(const Test &obj);
    Test(Test &&obj);
    ~Test();
    Test &operator=(const Test &obj);
    Test &operator=(Test &&obj);
    T &operator[](int pos);
    Test operator+(const Test &obj);
    int getSize();
};

template <class T>
Test<T *>::Test(int size, T val) : size(size)
{
    arr = new T[size];
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = val;
    }
}

template <class T>
Test<T *>::Test(int size) : size(size)
{
    arr = new T[size];
}

template <class T>
Test<T *>::Test(const Test &obj)
{
    size = obj.size;
    arr = new T[size];
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = obj.arr[i];
    }
}

template <class T>
Test<T *>::Test(Test &&obj)
{
    swap(arr, obj.arr);
    swap(size, obj.size);
}

template <class T>
Test<T *>::~Test()
{
    if (size)
        delete[] arr;
}

template <class T>
Test<T *> &Test<T *>::operator=(const Test &obj)
{
    if (this == &obj)
        return *this;
    if (size)
        delete[] arr;
    size = obj.size;
    arr = new T[size];
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = obj.arr[i];
    }

    return *this;
}

template <class T>
Test<T *> &Test<T *>::operator=(Test &&obj)
{
    if (this == &obj)
        return *this;
    if (size)
        delete[] arr;
    arr = obj.arr;
    obj.arr = nullptr;
    size = obj.size;
    obj.size = 0;
    return *this;
}

template <class T>
T &Test<T *>::operator[](int pos) { return arr[pos]; }

template <class T>
Test<T *> Test<T *>::operator+(const Test &obj)
{
    int new_size = size + obj.size;
    Test<T *> tmp(new_size);
    for (size_t i = 0; i < size; i++)
    {
        tmp.arr[i] = arr[i];
    }
    for (size_t j = size, i = 0; i < obj.size; i++, j++)
    {
        tmp.arr[j] = obj.arr[i];
    }

    return tmp;
}

template <class T>
int Test<T *>::getSize()
{
    return size;
}