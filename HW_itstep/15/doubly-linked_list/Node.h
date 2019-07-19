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

    Node *findNode(int pos); // поиск ноды по позиции с головы

    Node *findNode(int pos, int size); // поиск ноды по позиции с хвоста

    void setNext(Node *next);

    void setPrev(Node *prev);

    void swap_data(Node *second);

    Node<T> &operator=(const Node<T> &obj); // не используется
};

template <class T>
Node<T>::Node(T val) : data(val) {}

template <class T>
T Node<T>::getData() const { return data; }

template <class T>
void Node<T>::setData(T data) { this->data = data; }

template <class T>
Node<T> *Node<T>::getNext() const { return next; }

template <class T>
Node<T> *Node<T>::getPrev() const { return prev; }

template <class T>
Node<T> *Node<T>::findNode(int pos)
{
    Node<T> *current = this;
    for (int i = 0; i < pos - 1; i++)
    {
        current = current->getNext();
    }
    return current;
}

template <class T>
Node<T> *Node<T>::findNode(int pos, int size)
{
    Node<T> *current = this;
    for (int i = 0; i < size - pos; i++)
    {
        current = current->getPrev();
    }
    return current;
}

template <class T>
void Node<T>::setNext(Node *next) { this->next = next; }

template <class T>
void Node<T>::setPrev(Node *prev) { this->prev = prev; }

template <class T>
void Node<T>::swap_data(Node *second) { std::swap(this->data, second->data); }

template <class T>
Node<T> &Node<T>::operator=(const Node &obj)
{
    data = obj.data;
    next = obj.next;
    prev = obj.prev;
}
