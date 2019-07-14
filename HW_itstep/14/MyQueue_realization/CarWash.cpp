#include "CarWash.h"

unsigned long CarWash::getMaxQueueSize() { return queue.getMaxSize(); }

short CarWash::getEmptyTime() { return empty_time; }

void CarWash::GenerateNewCar() // добавляет новую машину согласно вероятности
{
    //srand(time(0)); // если вызывать тут то всегда одно число
    Car new_car;
    short chance = 0;

    if ((chance = rand() % 101) < percent + 1)
    {
        queue.Push(new_car);
    }
}

void CarWash::CheckEmptyTime(short current_empty_time) // проверяет время простоя
{
    if (current_empty_time > empty_time)
    {
        empty_time = current_empty_time;
    }
}

void CarWash::WorkingDay() // моет последнюю машину ,не доставая, с несколькими мойками нужно будет переделать
{
    srand(time(0));
    short current_empty_time = 0;
    for (short i = 0; i < working_hours * 60 || (queue.Peek()).IsWashing(); i++) // Каждую минуту , в течении рабочего дня или пока не домыта начатая машына
    {
        CarWash::GenerateNewCar();

        if (!queue.Is_Empty())
        {
            CarWash::CheckEmptyTime(current_empty_time);
            current_empty_time = 0;
            if ((queue.Peek()).IsClean()) // если первый в очереди чист - удаляет его
            {
                queue.Pop();
            }
            else
            {
                (queue.Peek()).Washing(); // иначе - моет его
            }
        }
        else
        {
            current_empty_time++;
        }
    }
}
