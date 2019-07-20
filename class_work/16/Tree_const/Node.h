#pragma once
template <class T>
class Node
{
    T data;
    Node*parent= nullptr;
    Node*left= nullptr;
    Node*right= nullptr;
public:
    Node(T);

    T getData() const;

    void setData(T data);

    Node *getParent() const;

    void setParent(Node *parent);

    Node *getLeft() const;

    void setLeft(Node *left);

    Node *getRight() const;

    void setRight(Node *right);
};

template<class T>
Node<T>::Node(T d)
{
    data = d;
}

template<class T>
T Node<T>::getData() const
{
    return data;
}

template<class T>
void Node<T>::setData(T data)
{
    Node::data = data;
}

template<class T>
Node<T> *Node<T>::getParent() const
{
    return parent;
}

template<class T>
void Node<T>::setParent(Node<T> *parent)
{
    this->parent = parent;
}

template<class T>
Node<T> *Node<T>::getLeft() const
{
    return left;
}

template<class T>
void Node<T>::setLeft(Node *left)
{
    this->left = left;
}

template<class T>
Node<T> *Node<T>::getRight() const
{
    return right;
}

template<class T>
void Node<T>::setRight(Node *right)
{
    this->right = right;
}
