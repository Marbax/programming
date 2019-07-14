#pragma once

class Car
{
private:
    static unsigned long id;
    unsigned short time_to_wash = 10;
    bool clean = false;
    bool washing = false;

public:
    Car();
    ~Car();
    unsigned short getTimeToWash() const;
    bool IsWashing();
    bool IsClean();
    void Washing();
};
