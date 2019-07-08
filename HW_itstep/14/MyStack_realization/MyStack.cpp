#include "MyStack.h"
#include <iostream>

//=================Constructors==============================================
MyStack::MyStack()
{
    capacity = 100;
    arr = new char[capacity]{};
}
MyStack::MyStack(int capacity) : capacity(capacity)
{
    arr = new char[capacity]{};
}
MyStack::MyStack(const MyStack &obj)
{
    capacity = obj.capacity;
    top = obj.top;
    arr = new char[capacity];
    for (size_t i = 0; i <= top; i++)
    {
        arr[i] = obj.arr[i];
    }
}
MyStack::MyStack(MyStack &&obj)
{
    std::swap(capacity, obj.capacity);
    std::swap(top, obj.top);
    std::swap(arr, obj.arr);
}
MyStack::~MyStack()
{
    if (capacity)
    {
        delete[] arr;
    }
}

//==========================Overload_Operators================================
MyStack &MyStack::operator=(const MyStack &obj)
{
    if (this == &obj)
    {
        return *this;
    }
    if (capacity)
    {
        delete[] arr;
    }
    capacity = obj.capacity;
    top = obj.top;
    arr = new char[capacity];
    for (size_t i = 0; i <= top; i++)
    {
        arr[i] = obj.arr[i];
    }
    return *this;
}
MyStack &MyStack::operator=(MyStack &&obj)
{
    if (this == &obj)
    {
        return *this;
    }
    if (capacity)
    {
        delete[] arr;
    }
    arr = obj.arr;
    capacity = obj.capacity;
    top = obj.top;
    obj.arr = nullptr;
    obj.capacity = 0;
    return *this;
}

//==============================Methods=======================================
void MyStack::Push(int val) { arr[++top] = val; }
int MyStack::Pop() { return arr[top--]; } // вытаскивает последний эллемент (возвращает его ,и удаляет)
int MyStack::Peek() { return arr[top]; }
bool MyStack::Is_Empty() { return top < 0; }
bool MyStack::Is_Full() { return top == capacity - 1; }