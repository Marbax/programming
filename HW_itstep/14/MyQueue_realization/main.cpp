#include "CarWash.h"
#include <iostream>

using namespace std;

/* 
Создать программу, имитирующую рабочий день мойки автомобилей.
Программа должна содержать класс, описывающий автомойку и класс,
описывающий очередь автомобилей.
Рабочий день длится 480 минут(1 минута 1 итерация цикла). Каждую минуту, с шансом
10%, в очередь добавляется новая машина. Если мойка свободна, первая машина из
очереди перемещается на мойку. Помывка одной машины занимает 10 минут.

Определить максимальное время простоя мойки за день и максимальную величину
очереди.
 */

/* 
10% можно делать через рандом , цикл выполняет 480 итерация , итерация - 1 мин, помыть ,
уменьшает на 1 , 3 метода , поставить время в 10 мин , ис эмпти , уменьшить время на 1,
в автомойке 1 место,класс машина тоже(разные машины по разному моются),
 последнего домывать, за минуту до конца можно принимать на мойку 
 */

int main()
{
    CarWash first_cabin;
    first_cabin.WorkingDay();
    cout << "\nMax empty time => " << first_cabin.getEmptyTime() << "\nMax queue size => " << first_cabin.getMaxQueueSize() << endl;

    cout << "\nEND_OF_PROGRAM" << endl;
}
