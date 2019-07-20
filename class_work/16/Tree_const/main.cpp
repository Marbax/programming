#include <iostream>
#include "Tree.h"

using namespace std;

int main()
{
    Tree<int> tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(90);
    tree.insert(10);
    tree.insert(80);
    tree.insert(100);
    tree.insert(44);
    tree.print();
    cout<<endl;
    tree.del(tree.getRoot());
    tree.print();
    cout<<endl;
}