#pragma once

class Stack
{
private:
    int *arr = nullptr;
    int top = -1;
    int capacity = 0;

public:
    //=================Constructors==============================================
    Stack();
    Stack(int);
    Stack(const Stack &obj);
    Stack(Stack &&obj);
    ~Stack();

    //==========================Overload_Operatoors===============================
    Stack &operator=(const Stack &obj);
    Stack &operator=(Stack &&obj);

    //==============================Methods=======================================
    void Push(int val);
    int Pop(); // вытаскивает последний эллемент (возвращает его ,и удаляет)
    int Peek();
    bool Is_Empty();
    bool Is_Full();
};
