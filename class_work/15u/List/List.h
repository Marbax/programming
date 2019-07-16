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

    void popBack();

    void print();
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
List<T>::~List()
{
    while (size)
        popFront();
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
