#pragma once

class MyStack
{
private:
    char *arr = nullptr;
    int top = -1;
    int capacity = 0;

public:
    //=================Constructors==============================================
    MyStack();
    MyStack(int capacity);
    MyStack(const MyStack &obj);
    MyStack(MyStack &&obj);
    ~MyStack();

    //==========================Overload_Operatoors===============================
    MyStack &operator=(const MyStack &obj);
    MyStack &operator=(MyStack &&obj);

    //==============================Methods=======================================
    void Push(int val);
    int Pop(); // вытаскивает последний эллемент (возвращает его ,и удаляет)
    int Peek();
    bool Is_Empty();
    bool Is_Full();
};
