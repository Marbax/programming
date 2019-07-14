#pragma once
#include "MyQueue.h"
#include <iostream>

class CarWash //  или одна кабинка
{
private:
    short empty_time = 0;
    short working_hours = 8;
    short percent = 10;
    MyQueue queue;
    void GenerateNewCar();                         // добавляет новую машину согласно вероятности
    void CheckEmptyTime(short current_empty_time); // проверяет время простоя

public:
    CarWash() = default;
    ~CarWash() = default;
    unsigned long getMaxQueueSize();
    short getEmptyTime();
    void WorkingDay(); // моет последнюю машину ,не доставая, с несколькими мойками нужно будет переделать
};
