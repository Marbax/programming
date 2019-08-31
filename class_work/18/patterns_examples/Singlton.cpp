#include <iostream>

class Singlton
{
    int data;
    static Singlton *ptr;
    Singlton(int data) { this->data = data; }

public:
    Singlton(const Singlton &) = delete;

    static Singlton *getRef()
    {
        if (ptr == nullptr)
        {
            ptr = new Singlton(0);
        }
        return ptr;
    }

    int getData() { return data; }

    void setData(int data) { this->data = data; }

    ~Singlton() {}
};
Singlton *Singlton::ptr = nullptr; // конст можно только снаружи инициализировать
