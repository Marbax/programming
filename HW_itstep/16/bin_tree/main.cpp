#include <iostream>
#include "Tree.h"
#include "Node.h"

int main()
{
    Node<const char *> tmp("Binary tree : ");
    std::cout << tmp.getData() << std::endl;

    Tree<int> tree;
    tree.insert(300);
    tree.insert(50);
    tree.insert(30);
    tree.insert(40);
    tree.insert(70);
    tree.insert(10);
    tree.insert(75);
    tree.insert(15);
    tree.insert(230);
    tree.insert(45);
    tree.insert(55);
    tree.insert(52);
    tree.insert(325);
    tree.print();
    std::cout << std::endl;

    auto node = tree.getMin(tree.getRoot());
    std::cout << "min = " << node->getData() << std::endl;

    auto node1 = tree.getNext(tree.getRoot());
    std::cout << "root = " << tree.getRoot()->getData() << " next = " << node1->getData() << std::endl;

    std::cout << "\ndel root : \n";
    tree.del(tree.getRoot());
    tree.print();
    std::cout << "\nroot = " << tree.getRoot()->getData() << " next = " << tree.getNext(tree.getRoot())->getData() << std::endl;
}