#pragma once

#include <iostream>
#include "Node.h"

template <class T>
class List
{
    Node<T> *head = nullptr;
    Node<T> *tail = nullptr;
    int size = 0;

public:
    List() = default;

    List(const List &);

    List(List &&);

    ~List();

    void pushBack(T val);

    void pushFront(T val);

    void popFront();

    void clear();

    void popBack();

    void print();

    int getSize();

    void insert(T val, int pos); // добавление эллемента в позицию

    void removeAt(int pos);            // удаление эллемента по позиции
    void removeAt(int pos, int count); // удаление эллемента по позиции c кол-вом (либо до последнего возможного)
    /*     
    void removeAt(int pos, int pos1); // удаление эллемента по позиции (2шт)
    void removeAt(int pos, int pos1,int pos2); // удаление эллемента по позиции (3шт)
*/

    List<T> &operator=(const List<T> &obj);

    List<T> &operator=(List<T> &&obj);
};

template <class T>
void List<T>::pushBack(T val)
{
    auto tmp = new Node<T>(val);
    if (size == 0)
        head = tail = tmp;
    else
    {
        tail->setNext(tmp);
        tail = tmp;
    }
    size++;
}

template <class T>
void List<T>::pushFront(T val)
{
    auto tmp = new Node<T>(val);
    if (size == 0)
        head = tail = tmp;
    else
    {
        tmp->setNext(head);
        head = tmp;
    }
    size++;
}

template <class T>
void List<T>::insert(T val, int pos) // добавление эллемента в позицию
{
    if (pos >= 0 && pos < size)
    {
        if (pos == 0)
        {
            pushFront(val);
        }
        else
        {
            Node<T> *previous = head;
            for (int i = 0; i < pos - 1; i++)
            {
                previous = previous->getNext();
            }

            auto newNode = new Node<T>(val);
            newNode->setNext(previous->getNext());

            previous->setNext(newNode);
            size++;
        }
    }
    else if (pos == size)
        pushBack(val);
}

template <class T>
void List<T>::print()
{
    Node<T> *current = head;
    while (current)
    {
        std::cout << current->getData() << " ";
        current = current->getNext();
    }
    std::cout << std::endl;
}

template <class T>
int List<T>::getSize() { return size; }

template <class T>
void List<T>::popFront()
{
    if (size == 0)
        return;
    if (size == 1)
    {
        delete head;
        head = tail = nullptr;
        size = 0;
        return;
    }
    Node<T> *tmp = head;
    head = head->getNext();
    delete tmp;
    size--;
}

template <class T>
void List<T>::popBack()
{
    if (size == 0)
        return;
    if (size == 1)
    {
        delete head;
        head = tail = nullptr;
        size = 0;
        return;
    }

    Node<T> *current = head;
    while (current->getNext() != tail)
    {
        current = current->getNext();
    }
    delete tail;
    tail = current;
    tail->setNext(nullptr);
    size--;
}

template <class T>
void List<T>::removeAt(int pos) // удаление эллемента по позиции
{
    if (pos >= 0 && pos < size)
    {
        if (pos == 0)
        {
            popFront();
        }
        else
        {
            Node<T> *previous = head;
            for (int i = 0; i < pos - 1; i++) // ищим предыдущий эллемент, чтобы потом записать туда указатель
            {
                previous = previous->getNext();
            }

            Node<T> *toDelete = previous->getNext(); // создаем эллемент , который указывает будет на данные которые нужно будет удалить(чтобы не потерять)
            previous->setNext(toDelete->getNext());  // указываем на еллемент через один(пропускаем один)
            delete toDelete;                         //очищаем память ненужного эллемента
            size--;
        }
    }
}

template <class T>
void List<T>::removeAt(int pos, int count) // удаление эллемента по позиции c кол-вом (либо до последнего возможного)
{
    for (int j = 0; j < count; j++)
    {
        removeAt(pos);
    }
}

/* 
template <class T>
void List<T>::removeAt(int pos, int pos1) // удаление эллемента по позиции
{
    removeAt(pos);
    removeAt(pos1-1);
}

template <class T>
void List<T>::removeAt(int pos, int pos1,int pos2) // удаление эллемента по позиции
{
    removeAt(pos);
    removeAt(pos1-1);
    removeAt(pos1-1);
}
 */

template <class T>
void List<T>::clear()
{
    while (size)
        popFront();
}

template <class T>
List<T>::~List()
{
    clear();
}

template <class T>
List<T>::List(const List &obj)
{
    Node<T> *current = obj.head;
    while (current)
    {
        pushBack(current->getData());
        current = current->getNext();
    }
}

template <class T>
List<T>::List(List &&obj)
{
    std::swap(head, obj.head);
    std::swap(tail, obj.tail);
    std::swap(size, obj.size);
}

template <class T>
List<T> &List<T>::operator=(const List &obj)
{
    if (this == &obj)
        return *this;
    clear();
    Node<T> *current = obj.head;
    while (current)
    {
        pushBack(current->getData());
        current = current->getNext();
    }
    return *this;
}

template <class T>
List<T> &List<T>::operator=(List &&obj)
{
    if (this == &obj)
        return *this;
    clear();
    //head = obj.head;
    //tail = obj.tail;
    //size = obj.size;
    //obj.head = nullptr;
    //obj.tail = nullptr;
    //obj.size = 0;
    std::swap(head,obj.head);
    std::swap(tail,obj.tail);
    std::swap(size,obj.size);

    return *this;
}
