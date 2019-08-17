#pragma once
#include "Node.h"
#include <iostream>

/* 
гет сайз через рекурсивную ф-ю, т.к. нельзя добавлять параметр сайз(сумма всех левых + сумма всех правых + 1) -
▪ конструктор перемещения;-+ check it
▪ деструктор;-+ check it
▪ перегрузка присвоения;-+ check it
 */

template <class T>
class Tree
{
private:
    Node<T> *root = nullptr;
    int size = 0;

public:
    Tree() = default;

    Tree(const Tree &obj); // конструктор копирования

    Tree(const Tree &&obj); // конструктор перемещения

    ~Tree();

    void clear();

    void clear(Node<T> *node);

    void insert(T val); //добавление эллемента в позицию

    void print(Node<T> *node); // выводит в отсортированом виде (инфиксная форма ,от меньшего к большему)

    void printDecr();

    void printDecr(Node<T> *node);

    void print();

    void copy(Node<T> *node);

    int getSize();

    Node<T> *getRoot();

    Node<T> *getMin(Node<T> *node);

    Node<T> *getNext(Node<T> *node);

    Node<T> *find(T val); // поиск элемента(find) ,по значению

    void del(Node<T> *node);

    Tree<T> &operator=(const Tree<T> &obj);

    Tree<T> &operator=(Tree<T> &&obj);
};

template <class T>
Tree<T>::Tree(const Tree &obj)
{
    copy(obj.root);
    size = obj.size;
} // конструктор копирования

template <class T>
Tree<T>::Tree(const Tree &&obj)
{
    std::swap(root, obj.root);
    size = obj.size;
    obj.size = 0;
} // конструктор перемещения

template <class T>
Tree<T>::~Tree()
{
    clear(root);
}

template <class T>
void Tree<T>::clear()
{
    clear(root);
}

template <class T>
void Tree<T>::clear(Node<T> *node) // !!!НЕ РАБОТАЕТ !!! // можно удалять корень все время  // либо по аналогу принта ,только удалять
{
    if (node)
    {
        Node<T> *tmp_left, *tmp_right;
        if (node->getLeft())
        {
            tmp_left = node->getLeft();
            clear(tmp_left);
        }
        if (node->getRight())
        {
            tmp_right = node->getRight();
            clear(tmp_left);
        }

        if (node->getParrent())
        {
            if (node->getParrent()->getLeft() == node)
                node->getParrent()->setLeft(nullptr);
            else if (node->getParrent()->getRight() == node)
                node->getParrent()->setRight(nullptr);
        }

        delete node;
        size--;
    }
}

template <class T>
int Tree<T>::getSize() { return size; } // возвращает размер

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
Node<T> *Tree<T>::find(T val) // возвращает ноду с совпавшим значением
{
    if (root != nullptr)
    {
        Node<T> *cur = root;
        while (cur)
        {
            if (cur->getData() == val)
            {
                return cur;
            }

            if (val < cur->getData())
                cur = cur->getLeft();
            else
                cur = cur->getRight();
        }
    }
}
template <class T>
void Tree<T>::del(Node<T> *node) // удаляет ноду , если нет наследника то будет эррор
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

    if (target->getParrent() == nullptr) // почему не так if (&target == &root)
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
    size--;
}

template <class T>
void Tree<T>::insert(T val) //добавление эллемента в позицию
{
    //Node<T> *node = new Node<T>(val); // то же что и ниже
    auto node = new Node<T>(val);
    size++;
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
void Tree<T>::printDecr()
{
    printDecr(root);
}

template <class T>
void Tree<T>::printDecr(Node<T> *node)
{
    if (node == nullptr)
    {
        return;
    }
    printDecr(node->getRight());
    std::cout << node->getData() << " ";
    printDecr(node->getLeft());
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

template <class T>
Tree<T> &Tree<T>::operator=(const Tree<T> &obj)
{
    copy(obj.root);
    size = obj.size;
}

template <class T>
Tree<T> &Tree<T>::operator=(Tree<T> &&obj)
{
    root = obj.root;
    obj.root = nullptr;
    size = obj.size;
    obj.size = 0;
}
