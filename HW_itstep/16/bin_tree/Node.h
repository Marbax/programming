#pragma once
#include <iostream>

template <class T>
class Node
{
    T data;
    Node *parrent = nullptr, *left = nullptr, *right = nullptr;

public:
    Node(T val);

    T getData() const;

    void setData(T data);

    Node *getParrent();

    Node *getLeft();

    Node *getRight();

    void setParrent(Node *parrent);

    void setLeft(Node *left);

    void setRight(Node *right);
};

template <class T>
Node<T>::Node(T val) : data(val) {}

template <class T>
void Node<T>::setData(T data) { this->data = data; }

template <class T>
T Node<T>::getData() const { return data; }

template <class T>
Node<T> *Node<T>::getParrent() { return parrent; }

template <class T>
Node<T> *Node<T>::getLeft() { return left; }

template <class T>
Node<T> *Node<T>::getRight() { return right; }

template <class T>
void Node<T>::setParrent(Node *parrent) { this->parrent = parrent; }

template <class T>
void Node<T>::setLeft(Node *left) { this->left = left; }

template <class T>
void Node<T>::setRight(Node *right) { this->right = right; }
