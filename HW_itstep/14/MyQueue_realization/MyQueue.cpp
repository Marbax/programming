#include "MyQueue.h"
#include <iostream>
//#include <string.h>
//using namespace std;

//=================Constructors==============================================
MyQueue::MyQueue() : capacity(100)
{
    arr = new Car[capacity]{};
}
MyQueue::MyQueue(unsigned long capacity) : capacity(capacity)
{
    arr = new Car[capacity]{};
}
MyQueue::MyQueue(const MyQueue &obj)
{
    capacity = obj.capacity;
    size = obj.size;
    arr = new Car[capacity];
    for (unsigned long i = 0; i < size; i++)
    {
        arr[i] = obj.arr[i];
    }
}
MyQueue::MyQueue(MyQueue &&obj)
{
    std::swap(capacity, obj.capacity);
    std::swap(size, obj.size);
    std::swap(arr, obj.arr);
}
MyQueue::~MyQueue()
{
    if (capacity)
    {
        delete[] arr;
    }
}

//==========================Overload_Operatoors===============================
MyQueue &MyQueue::operator=(const MyQueue &obj)
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
    size = obj.size;
    arr = new Car[capacity];
    for (unsigned long i = 0; i < size; i++)
    {
        arr[i] = obj.arr[i];
    }
    return *this;
}
MyQueue &MyQueue::operator=(MyQueue &&obj)
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
    size = obj.size;
    obj.arr = nullptr;
    obj.capacity = 0;
    return *this;
}

//==============================Methods=======================================
unsigned long MyQueue::getSize() const { return size; }
unsigned long MyQueue::getMaxSize() const { return max_size; } // максимальный размер очереди ,за ее существование
void MyQueue::CheckMaxSize()                                   // проверяет или сейчас очередь больше всего
{
    if (size > max_size)
        max_size = size;
}
void MyQueue::Push(Car val) // добавляет обьект в очередь, и вызывает метод CheckMaxSize
{
    arr[size++] = val;
    MyQueue::CheckMaxSize();
}
Car MyQueue::Pop() // вытаскивает первый эллемент (возвращает его ,и удаляет)
{
    Car tmp = arr[0];
    for (unsigned long i = 1; i < size; i++)
    {
        arr[size - 1] = arr[i];
    }
    size--;

    return tmp;
}
Car &MyQueue::Peek() { return arr[0]; }
bool MyQueue::Is_Empty() { return size <= 0; }
bool MyQueue::Is_Full() { return size == capacity; }