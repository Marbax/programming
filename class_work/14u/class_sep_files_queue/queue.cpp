#include "queue.h"
#include <iostream>
//#include <string.h>
//using namespace std;
//#include <utility> // инклудится в иостриме , в данном случае не включает сайз_т

// ОЧЕРЕДЬ МОЖЕТ ДВИГАТЬСЯ САМА ,А НЕ ЕЕ ЧЛЕНЫ

//=================Constructors==============================================
Queue::Queue()
{
    capacity = 100;
    arr = new int[capacity]{};
}
Queue::Queue(int capacity) : capacity(capacity)
{
    arr = new int[capacity]{};
}
Queue::Queue(const Queue &obj)
{
    capacity = obj.capacity;
    size = obj.size;
    arr = new int[capacity];
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = obj.arr[i];
    }
}
Queue::Queue(Queue &&obj)
{
    std::swap(capacity, obj.capacity);
    std::swap(size, obj.size);
    std::swap(arr, obj.arr);
}
Queue::~Queue()
{
    if (capacity)
    {
        delete[] arr;
    }
}

//==========================Overload_Operatoors===============================
Queue &Queue::operator=(const Queue &obj)
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
    arr = new int[capacity];
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = obj.arr[i];
    }
    return *this;
}
Queue &Queue::operator=(Queue &&obj)
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
    obj.size = 0;
    return *this;
}

//==============================Methods=======================================
void Queue::Push(int val) { arr[size++] = val; }
int Queue::Pop() // вытаскивает первый эллемент (возвращает его ,и удаляет)
{
    int tmp = arr[0];
    for (size_t i = 1; i < size; i++)
    {
        arr[size - 1] = arr[i];
    }
    size--;

    return tmp;
}
int Queue::Peek() { return arr[0]; }
bool Queue::Is_Empty() { return size <= 0; }
bool Queue::Is_Full() { return size == capacity; }