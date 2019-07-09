#pragma once
#include "Car.h"

class MyQueue
{
private:
    Car *arr = nullptr;
    unsigned long size = 0;
    unsigned long capacity = 0;
    unsigned long max_size = 0;

public:
    //=================Constructors==============================================
    MyQueue();
    MyQueue(unsigned long capacity);
    MyQueue(const MyQueue &obj);
    MyQueue(MyQueue &&obj);
    ~MyQueue();

    //==========================Overload_Operatoors===============================
    MyQueue &operator=(const MyQueue &obj);
    MyQueue &operator=(MyQueue &&obj);

    //==============================Methods=======================================
    unsigned long getSize() const;
    unsigned long getMaxSize() const; // максимальный размер очереди ,за ее существование
    void CheckMaxSize(); // проверяет или сейчас очередь больше всего
    void Push(Car val); // добавляет обьект в очередь, и вызывает метод CheckMaxSize
    Car Pop(); // вытаскивает последний эллемент (возвращает его ,и удаляет)
    Car& Peek();
    bool Is_Empty();
    bool Is_Full();
};
