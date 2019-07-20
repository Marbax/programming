#pragma once
#include "Node.h"
#include <iostream>

template <class T>
class Tree
{
private:
    Node<T> *root = nullptr;

public:
    Tree() = default;

    Tree(const Tree &obj); // конструктор копирования

    ~Tree();

    void insert(T val); //добавление эллемента в позицию

    void print(Node<T> *node); // выводит в отсортированом виде (инфиксная форма ,от меншего к большему)

    void printDecr(Node<T> *node);

    void print();

    void copy(Node<T> *node);

    Node<T> *getRoot();

    Node<T> *getMin(Node<T> *node);

    Node<T> *getNext(Node<T> *node);

    void del(Node<T> *node);
};

template <class T>
Tree<T>::Tree(const Tree &obj) { copy(obj.root); } // конструктор копирования

template <class T>
Tree<T>::~Tree() {}

template <class T>
Node<T> *Tree<T>::getRoot() { return root; } // возвращает корень

template <class T>
Node<T> *Tree<T>::getMin(Node<T> *node) // возвращает ноду с минимальным значением
{
    if (node == nullptr)
        return nullptr;
    while (node->getLeft())
    {
        node = node->getLeft();
    }

    return node;
}

template <class T>
Node<T> *Tree<T>::getNext(Node<T> *node) // возвращает след ноду
{
    if (node == nullptr)
        return nullptr;
    if (node->getRight())
        return getMin(node->getRight());
    Node<T> *tmp = node->getParrent();
    while (tmp && node == tmp->getRight())
    {
        node = tmp;
        tmp = node->getParrent();
    }
    return tmp;
}

template <class T>
void Tree<T>::del(Node<T> *node) // удаляет ноду
{
    if (node == nullptr)
        return;
    Node<T> *target, *son;
    if (node->getRight() && node->getLeft())
        target = getNext(node);
    else
        target = node;

    if (target->getLeft())
        son = target->getLeft();
    else
        son = target->getRight();

    if (son)
        son->setParrent(target->getParrent());

    if (target->getParrent() == nullptr)
        root = son;
    else
    {
        if (target == target->getParrent()->getLeft())
            target->getParrent()->setLeft(son);
        else
            target->getParrent()->setRight(son);
    }

    if (node != target)
        node->setData(target->getData());
    delete target;
}

template <class T>
void Tree<T>::insert(T val) //добавление эллемента в позицию
{
    //Node<T> *node = new Node<T>(val); // то же что и ниже
    auto node = new Node<T>(val);
    if (root == nullptr)
    {
        root = node;
        return;
    }
    Node<T> *cur = root;
    Node<T> *prev = root;
    while (cur)
    {
        prev = cur;
        if (val < cur->getData())
            cur = cur->getLeft();
        else
            cur = cur->getRight();
    }
    node->setParrent(prev);

    if (val < prev->getData())
        prev->setLeft(node);
    else
        prev->setRight(node);
}

template <class T>
void Tree<T>::print() { print(root); }

template <class T>
void Tree<T>::print(Node<T> *node) // выводит в отсортированом виде (инфиксная форма ,от меншего к большему)
{
    if (node == nullptr)
    {
        return;
    }
    print(node->getLeft());
    std::cout << node->getData() << " ";
    print(node->getRight());
}

template <class T>
void Tree<T>::printDecr(Node<T> *node) // не доделан
{
    if (node == nullptr)
    {
        return;
    }
    print(node->getRight());
    std::cout << node->getData() << " ";
    print(node->getLeft());
}

template <class T>
void Tree<T>::copy(Node<T> *node) // выводит в отсортированом виде (инфиксная форма ,от меншего к большему)
{
    if (node == nullptr)
    {
        return;
    }
    insert(node->getData());
    copy(node->getLeft());
    //insert(node->getData()); // если поставить между копи , то превратится в список и эффективность упадет
    copy(node->getRight());
}
