#pragma once

template <class T>
class Node
{
    T data;
    Node *next = nullptr;

public:
    Node(T val);

    T getData() const;

    void setData(T data);

    Node *getNext() const;

    void setNext(Node *next);
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
void Node<T>::setNext(Node *next)
{
    this->next = next;
}
