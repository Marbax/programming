#include "stack.h"
#include <iostream>
//#include <string.h>
//using namespace std;
//#include <utility> // инклудится в иостриме , в данном случае не включает сайз_т

//=================Constructors==============================================
Stack::Stack()
{
    capacity = 100;
    arr = new int[capacity]{};
}
Stack::Stack(int capacity) : capacity(capacity)
{
    arr = new int[capacity]{};
}
Stack::Stack(const Stack &obj)
{
    capacity = obj.capacity;
    top = obj.top;
    arr = new int[capacity];
    for (size_t i = 0; i <= top; i++)
    {
        arr[i] = obj.arr[i];
    }
}
Stack::Stack(Stack &&obj)
{
    std::swap(capacity, obj.capacity);
    std::swap(top, obj.top);
    std::swap(arr, obj.arr);
}
Stack::~Stack()
{
    if (capacity)
    {
        delete[] arr;
    }
}

//==========================Overload_Operatoors===============================
Stack &Stack::operator=(const Stack &obj)
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
    arr = new int[capacity];
    for (size_t i = 0; i <= top; i++)
    {
        arr[i] = obj.arr[i];
    }
    return *this;
}
Stack &Stack::operator=(Stack &&obj)
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
void Stack::Push(int val) { arr[++top] = val; }
int Stack::Pop() { return arr[top--]; } // вытаскивает последний эллемент (возвращает его ,и удаляет)
int Stack::Peek() { return arr[top]; }
bool Stack::Is_Empty() { return top < 0; }
bool Stack::Is_Full() { return top == capacity - 1; }