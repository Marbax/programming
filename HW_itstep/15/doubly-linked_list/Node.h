#pragma once
#include <iostream>

template <class T>
class Node
{
    T data;
    Node *next = nullptr, *prev = nullptr;

public:
    Node(T val);

    T getData() const;

    void setData(T data);

    Node *getNext() const;

    Node *getPrev() const;

    void setNext(Node *next);

    void setPrev(Node *prev);

    void swap(Node *second);

    void swap_data(Node *second);
};

template <class T>
Node<T>::Node(T val)
{
    data = val;
}

template <class T>
T Node<T>::getData() const
{
    return data;
}

template <class T>
void Node<T>::setData(T data)
{
    this->data = data;
}

template <class T>
Node<T> *Node<T>::getNext() const
{
    return next;
}

template <class T>
Node<T> *Node<T>::getPrev() const
{
    return prev;
}

template <class T>
void Node<T>::setNext(Node *next)
{
    this->next = next;
}

template <class T>
void Node<T>::setPrev(Node *prev)
{
    this->prev = prev;
}

template <class T>
void Node<T>::swap(Node *second)
{
    std::swap(this->next, next);
    std::swap(this->prev, prev);
}

template <class T>
void Node<T>::swap_data(Node *second)
{
    std::swap(this->data, data);
}
