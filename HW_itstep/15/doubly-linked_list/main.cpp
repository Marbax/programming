/* 
Создать шаблонный класс двусвязного списка List. Для этого класса
реализовать следующие методы:
▪ конструктор по умолчанию; +
▪ конструктор копирования; +
▪ конструктор перемещения; +
▪ деструктор; +
▪ добавление элемента в конец списка; +
▪ добавление элемента в указанную позицию; +
▪ удаление элемента с начала списка; +
▪ удаление элемента из указанной позиции; +
▪ вывод на экран содержимого списка; +
▪ перегрузить оператор присваивания(&); +
▪ перегрузить оператор присваивания(&&); +
▪ сортировка списка по возрастанию(убыванию). +
 */

// почему "auto" при выделении памяти под новую ноду ?
// как сделать свап эллементов списка по указателям ,для сортировки ?

#include <iostream>
#include "List.h"

int main()
{
    List<int> l;
    std::cout << "Created empty \'l\' list" << std::endl;

    l.pushBack(34);
    l.pushBack(567);
    l.pushBack(84);
    l.pushBack(295);
    l.pushBack(333);
    l.popBack();
    l.pushFront(888);
    std::cout << "Added ellements to \'l\' list :" << std::endl;
    l.print();
    std::cout << "\nReverse print \'l\' list :" << std::endl;
    l.reversePrint();
    l.removeAt(2, 3);
    l.insert(999, 2);
    //l.popBack();
    //l.popBack();
    //l.popBack();
    std::cout << "\n\'insert\' and \'remove at\' effect to \'l\' list :" << std::endl;
    l.print();
    List<int> f;
    std::cout << "\nCreated \'f\' list(second) :" << std::endl;
    f.pushBack(555);
    f.print();
    f = std::move(l);
    std::cout << "\nCopied \'l\' to  \'f\' list :" << std::endl;
    f.print();
    f.insert(2333, 2);
    std::cout << "\ninsert to \'f\' list(second) :" << std::endl;
    f.print();
    std::cout << "\nReverse print \'f\' list(second) :" << std::endl;
    f.reversePrint();
    std::cout << "\n\'l\' list\'s size => " << l.getSize();
    std::cout << "\n \'l\' list data : " << std::endl;
    l.print();

    std::cout << "\n Copy constr : " << std::endl;
    List<int> z(f);
    f.print();
    f.reversePrint();

    std::cout << "\n Move constr : " << std::endl;
    List<int> q(std::move(f));
    q.print();
    q.reversePrint();

    std::cout << "\n Copy operator : " << std::endl;
    l = q;
    l.print();
    l.reversePrint();

    std::cout << "\n Move operator from \'q\' to empty \'f\' : " << std::endl;
    f = std::move(q);
    f.print();
    std::cout << "\n Increment sort : " << std::endl;
    f.increment_sort();
    f.print();
    f.reversePrint();
    std::cout << "\n Insert elem : " << std::endl;
    f.insert(1666, 2);
    f.print();
    std::cout << "\n Decremet sort : " << std::endl;
    f.decrement_sort();
    f.print();
    f.reversePrint();

}
