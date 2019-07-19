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
    //==================================================================================================================
    //===============================================_CONSTRUCTORS_=====================================================
    //==================================================================================================================
    List() = default; //▪ конструктор по умолчанию;

    List(const List &); //▪ конструктор копирования;

    List(List &&); //▪ конструктор перемещения;

    ~List(); //▪ деструктор;

    //==================================================================================================================
    //=================================================_METHODS_========================================================
    //==================================================================================================================
    void pushBack(T val); //▪ добавление элемента в конец списка;

    void pushFront(T val); // добавление элемента в конец списка;

    void popFront(); // ▪ удаление элемента с начала списка;

    void clear(); // очистить список

    void popBack(); // удалить эллемент с конца списка

    void print(); //▪ вывод на экран содержимого списка;

    void reversePrint(); //▪ вывод на экран содержимого списка задом на перед

    int getSize(); // получить размер списка

    void insert(T val, int pos); // ▪ добавление элемента в указанную позицию;

    void removeAt(int pos); // ▪ удаление элемента из указанной позиции;

    void removeAt(int pos, int count); // ▪ удаление элемента из указанной позиции c кол-вом (либо до последнего возможного)

    void swap(Node<T> *first, Node<T> *second);  // нерабочий :С

    void increment_sort(); //▪ сортировка списка по возрастанию.

    void decrement_sort(); //▪ сортировка списка по убыванию.

    /*
    void removeAt(int pos, int pos1); // удаление эллемента по позиции (2шт)
    void removeAt(int pos, int pos1,int pos2); // удаление эллемента по позиции (3шт)
    */

    //==================================================================================================================
    //=================================================_OPERATORS_======================================================
    //==================================================================================================================

    List<T> &operator=(const List<T> &obj); //▪ перегрузить оператор присваивания(&);

    List<T> &operator=(List<T> &&obj); //▪ перегрузить оператор присваивания(&&);
};

//==================================================================================================================
//===============================================_CONSTRUCTORS_=====================================================
//==================================================================================================================

template <class T>
List<T>::List(const List &obj)
{
    Node<T> *current = obj.head; // создаем временный обьект указывающий на начало списка ,который хотим копировать
    while (current)              // пока указатель куда то указывает (не nullptr)
    {
        pushBack(current->getData()); // вызываем метод добавления эллемента в конец списка
        current = current->getNext(); // двигаем указатель вперед на один эллемент
    }
}

template <class T>
List<T>::List(List &&obj)
{
    std::swap(head, obj.head); // т.к. новый список безразмерный и указывает в никуда , просто меняем местами указатели и размер
    std::swap(tail, obj.tail);
    std::swap(size, obj.size);
}

template <class T>
List<T>::~List()
{
    clear(); // вызывает очистку списка , которая в свою очередь удаляет эллементы спереди в цикле
}

//==================================================================================================================
//=================================================_METHODS_========================================================
//==================================================================================================================
template <class T>
void List<T>::pushBack(T val)
{
    auto tmp = new Node<T>(val); // создаем в куче новый обьект ,через консруктор с параметрами ноды
    if (size == 0)               // если первый эллемент
        head = tail = tmp;       // начало и конец указывают на него
    else                         // иначе
    {
        tail->setNext(tmp); // конец указывает на новый эллемент
        tmp->setPrev(tail); // новый эллемент указывает на хвост ,как на прошлый
        tail = tmp;         // конец становится новым эллементомu
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
        tmp->setNext(head); // новый эллемент указывает на голову как на следующий эллемент
        head->setPrev(tmp); // голова указывает на новый эллемент как на предыдущий
        head = tmp;         // новый эллемент стает головой
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
            Node<T> *current = (pos >= size / 2 + 1) ? tail->findNode(pos, size) : head->findNode(pos);
            auto newNode = new Node<T>(val);
            newNode->setNext(current->getNext());
            newNode->setPrev(current);
            (current->getNext())->setPrev(newNode);
            current->setNext(newNode);

            /* Node<T> *current = head;
            for (int i = 0; i < pos - 1; i++)
            {
                current = current->getNext();
            }
            */

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
void List<T>::reversePrint()
{
    Node<T> *current = tail;
    while (current)
    {
        std::cout << current->getData() << " ";
        current = current->getPrev();
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
    head->setPrev(nullptr);
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
    Node<T> *tmp = tail;
    tail = tail->getPrev();
    tail->setNext(nullptr);
    delete tmp;
    size--;
}

template <class T>
void List<T>::removeAt(int pos) // удаление эллемента по позиции !!!_СДЕЛАТЬ_ВОЗМОЖНОСТЬ_ДОБАВЛЕНИЯ_С_КОНЦА_!!!
{
    if (pos >= 0 && pos < size - 1)
    {
        if (pos == 0)
        {
            popFront();
        }
        else
        {
            Node<T> *current = (pos >= size / 2 + 1) ? tail->findNode(pos, size) : head->findNode(pos);
            /* 
            Node<T> *current = head;
            for (int i = 0; i < pos - 1; i++) // ищим предыдущий эллемент, чтобы потом записать туда указатель
            {
                current = current->getNext();
            }
            */
            Node<T> *toDelete = current->getNext();  // создаем эллемент , который  будет указывать на данные ,которые нужно будет удалить(чтобы не потерять)
            current->setNext(toDelete->getNext());   // указываем на еллемент через один(пропускаем один)
            (toDelete->getNext())->setPrev(current); // так же меняем указатель следующего эллемента на через один назад(пропускаем один)
            delete toDelete;                         //очищаем память ненужного эллемента
            size--;
        }
    }
    else if (pos == size - 1)
        popBack();
}

template <class T>
void List<T>::removeAt(int pos, int count) // удаление эллемента по позиции c кол-вом (либо до последнего возможного)
{
    for (int j = 0; j < count; j++)
    {
        removeAt(pos);
    }
}

template <class T>
void List<T>::swap(Node<T> *first, Node<T> *second) // нерабочий :С
{
    if (first->getPrev()!=nullptr)
    {
        second->setPrev(first->getPrev());
        (second->getPrev())->setNext(second);
    }
    else
    {
        second->setPrev(nullptr);
        head = second;
    }

    if (second->getNext()!=nullptr)
    {
        first->setNext(second->getNext());
        (first->getNext())->setPrev(first);
    }
    else
    {
        first->setNext(nullptr);
        tail = first;
    }
    second->setNext(first);
    first->setPrev(second);
}

template <class T>
void List<T>::increment_sort()
{
    if (size > 1)
    {
        Node<T> *current = head;
        while (current->getNext())
        {
            if ((current->getData()) > ((current->getNext())->getData()))
            {
                current->swap_data(current->getNext());
                //swap(current, current->getNext());
                current = current->getNext();
                increment_sort();
            }
            else
            {
                current = current->getNext();
            }
        }
    }
}

template <class T>
void List<T>::decrement_sort()
{
    if (size > 1)
    {
        Node<T> *current = tail;
        while (current->getPrev())
        {
            if ((current->getData()) > ((current->getPrev())->getData()))
            {
                current->swap_data(current->getPrev());
                current = current->getPrev();
                decrement_sort();
            }
            else
            {
                current = current->getPrev();
            }
        }
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

//==================================================================================================================
//=================================================_OPERATORS_======================================================
//==================================================================================================================

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
    std::swap(head, obj.head);
    std::swap(tail, obj.tail);
    std::swap(size, obj.size);

    return *this;
}
