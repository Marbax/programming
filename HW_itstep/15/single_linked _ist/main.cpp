/* 
Создать шаблонный класс List. Для этого класса реализовать следующие
методы:
▪ конструктор по умолчанию; +
▪ конструктор копирования; +
▪ конструктор перемещения; +
▪ деструктор; +
▪ добавление элемента в конец списка; +
▪ удаление элемента с начала списка; +
▪ вывод на экран содержимого списка; +
▪ добавление элемента в указанную позицию; +
▪ удаление элемента из указанной позиции(одного или нескольких); +
▪ перегрузить оператор присваивания(&); +
▪ перегрузить оператор присваивания(&&); +
 */

#include <iostream>
#include "List.h"

int main()
{
    List<int> l;
    std::cout << "Created empty \'l\' list" << std::endl;
    l.pushBack(123);
    l.pushBack(34);
    l.pushBack(567);
    l.pushBack(84);
    l.pushBack(295);
    l.pushBack(333);
    //l.popBack();
    std::cout << "Added ellements to \'l\' list :" << std::endl;
    l.print();
    l.removeAt(2, 3);
    l.insert(999, 2);
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
    std::cout << "\n\'l\' list\'s size => " << l.getSize();
    std::cout << "\n \'l\' list data : " << std::endl;
    l.print();
}
