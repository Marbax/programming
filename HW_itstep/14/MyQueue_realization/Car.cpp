#include "Car.h"
#include <iostream>

Car::Car() {}
Car::~Car() {}

unsigned short Car::getTimeToWash() const { return time_to_wash; }
bool Car::IsWashing() { return washing; }
bool Car::IsClean() { return clean; }
void Car::Washing()
{
    if (!IsClean())
    {
        time_to_wash--;
        washing = true;
        if (time_to_wash == 0)
        {
            clean = true;
            washing = false;
        }
    }
}
