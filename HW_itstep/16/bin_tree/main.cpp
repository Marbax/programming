#include <iostream>
#include "Tree.h"
#include "Node.h"

/* 
Создать шаблонный класс Tree, описывающий бинарное дерево.
Для класса Tree реализовать следующие методы:
▪ добавление элемента(insert); +
▪ удаление элемента(delete);+
▪ поиск элемента(find);+
▪ конструктор копирования;+
▪ конструктор перемещения;+
▪ деструктор;+
▪ clear +
▪ перегрузка присвоения;+
▪ вывод на экран содержимого дерева(print);+
▪ print_decrement |
▪ getRoot;+
▪ getSize.+- странно отрабатывает
▪ getMax +
▪ getMin +
▪ getPrev +- странно отрабатывает
▪ getNext +

 */

int main()
{
    Node<const char *> tmp("Binary tree : ");
    std::cout << tmp.getData() << std::endl;

    Tree<int> tree;
    tree.insert(300);
    std::cout << "\tSIZE from root = " << tree.getSize() << std::endl;
    tree.insert(50);
    tree.insert(30);
    std::cout << "\tSIZE from root = " << tree.getSize() << std::endl;
    tree.insert(40);
    tree.insert(70);
    std::cout << "\tLeft part SIZE after root = " << tree.getSize(tree.getPrev(tree.getRoot())) << std::endl;
    std::cout << "root = " << tree.getRoot()->getData()<<" || ";
    tree.print(tree.getPrev(tree.getRoot()));
    tree.print();
    tree.insert(10);
    std::cout << "\n\tSIZE from root = " << tree.getSize() << std::endl;
    tree.insert(75);
    tree.insert(15);
    tree.insert(230);
    tree.insert(45);
    std::cout << "\tSIZE from root = " << tree.getSize() << std::endl;
    tree.insert(55);
    tree.insert(52);
    tree.insert(325);
    tree.insert(335);
    std::cout << "\tRight part SIZE after root = " << tree.getSize(tree.getNext(tree.getRoot())) << std::endl;
    tree.print();
    std::cout << std::endl;

    auto min_node = tree.getMin(tree.getRoot());
    std::cout << "min = " << min_node->getData() << std::endl;
    auto max_node = tree.getMax(tree.getRoot());
    std::cout << "max = " << max_node->getData() << std::endl;

    auto node_next = tree.getNext(tree.getRoot());
    auto node_prev = tree.getPrev(tree.getRoot());
    auto node_prev_prev = tree.getPrev(tree.getPrev(tree.getRoot()));
    std::cout << "root = " << tree.getRoot()->getData() << " next = " << node_next->getData() << " prev = " << node_prev->getData() << " prev_prev = " << node_prev_prev->getData() << std::endl;

    std::cout << "\ndel root : \n";
    tree.del(tree.getRoot());
    tree.print();
    std::cout << "\nroot = " << tree.getRoot()->getData() << " next = " << tree.getNext(tree.getRoot())->getData() << " prev = " << tree.getPrev(tree.getRoot())->getData() << std::endl;

    std::cout << "\nfind : \n";
    std::cout << tree.find(335)->getData();

    std::cout << "\nprint decr : \n";
    tree.printDecr();

    std::cout << "\n\ncopy constr : \n";
    Tree<int> alfa(tree);
    alfa.print();

    std::cout << "\n\nmove constr : \n";
    Tree<int> gama(std::move(tree));
    gama.print();
    std::cout << "\nmove constr obj result : \n";
    tree.print();

    std::cout << "\n\ncopy operator : \n";
    Tree<int> beta = gama;
    alfa.print();

    std::cout << "\n\nmove operator : \n";
    Tree<int> epsilon(std::move(beta));
    epsilon.print();
    std::cout << "\nmove operator obj result : \n";
    beta.print();

    std::cout << "\n\nclear : \n";
    epsilon.clear();
    epsilon.print();
}