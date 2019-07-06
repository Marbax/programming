#pragma once

class Queue
{
private:
    int *arr = nullptr;
    int size = 0;
    int capacity = 0;

public:
    //=================Constructors==============================================
    Queue();
    Queue(int);
    Queue(const Queue &obj);
    Queue(Queue &&obj);
    ~Queue();

    //==========================Overload_Operatoors===============================
    Queue &operator=(const Queue &obj);
    Queue &operator=(Queue &&obj);

    //==============================Methods=======================================
    void Push(int val);
    int Pop(); // вытаскивает последний эллемент (возвращает его ,и удаляет)
    int Peek();
    bool Is_Empty();
    bool Is_Full();
};
