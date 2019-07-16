#include <iostream>
#include <string>

using namespace std;

//====================================_START_OF_CLASS_=======================================
template <class T>
class List
{
private:
    //============================_вложеный_класс======================================
    template <class T>
    class Node
    {
    public:
        Node *pNext;
        T data;
        Node(T data = T(), Node *pNext = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
        }
    };
    //==============================_конец_вложеного_класса==============================

    int SIZE;
    Node<T> *head;

public:
    List();
    ~List();

    //================================_МЕТОДЫ_=======================================
    void Push_back(T data);

    int getSize() { return SIZE; }

    T &operator[](const int index)
    {
        int counter = 0;
        Node<T> *current = this->head;
        while (current != nullptr)
        {
            if (counter == index)
            {
                return current->data;
            }
            current = current->pNext;
            counter++;
        }
    }
};
//====================================_END_OF_CLASS_=======================================

template <class T>
List<T>::List()
{
    SIZE = 0;
    head = nullptr;
}

template <class T>
List<T>::~List()
{
}

//================================_МЕТОДЫ_=======================================
template <class T>
void List<T>::Push_back(T data)
{
    if (head == nullptr)
    {
        head = new Node<T>(data);
    }
    else
    {
        Node<T> *current = this->head;
        while (current->pNext != nullptr)
        {
            current = current->pNext;
        }
        current->pNext = new Node<T>(data);
    }

    SIZE++;
}

int main()
{
    List<int> lst;
    lst.Push_back(5);
}