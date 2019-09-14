/* 1. Спроектировать приложение, которое позволяет создавать легковые и грузовые
автомобили, а так же автобусы. Автомобили должны быть минимум двух марок:
“Mercedes” и “Ford”.
2. Создать UML диаграмму классов для приложения. */



/* Фабрика должна производить автомобили одной марки.  */


//-----------------------------Abstract Factory
#include <iostream>
#include <string>

using namespace std;

class Automobile
{
protected:
    string name;

public:
    Automobile(string name) : name(name) {}
};

class Mercedes : public Automobile
{
protected:
    Mercedes(string name) : Automobile(name) {}

public:
    virtual void Show() = 0;
    virtual ~Mercedes() = default;
};

class Ford : public Automobile
{
protected:
    Ford(string name) : Automobile(name) {}

public:
    virtual void Show() = 0;

    virtual ~Ford() = default;
};

class CarMercedes : public Mercedes
{
public:
    CarMercedes() : Mercedes("Car Mercedes") {}

    void Show() override
    {
        cout << name << endl;
    }
};

class TruckMercedes : public Mercedes
{
public:
    TruckMercedes() : Mercedes("Truck Mercedes") {}
    void Show() override
    {
        cout << name << endl;
    }
};

class BusMercedes : public Mercedes
{
public:
    BusMercedes() : Mercedes("Bus Mercedes") {}
    void Show() override
    {
        cout << name << endl;
    }
};

class CarFord : public Ford
{
public:
    CarFord() : Ford("Car Ford") {}
    void Show() override
    {
        cout << name << endl;
    }
};

class TruckFord : public Ford
{
public:
    TruckFord() : Ford("Truck Ford") {}
    void Show() override
    {
        cout << name << endl;
    }
};

class BusFord : public Ford
{
public:
    BusFord() : Ford("Bus Ford") {}
    void Show() override
    {
        cout << name << endl;
    }
};

//absdtract factory
class IAutomobileFactory
{
public:
    virtual Ford *GetFord() = 0;

    virtual Mercedes *GetMercedes() = 0;

    virtual ~IAutomobileFactory() = default;
};

// concrete factory
class TruckAutomobilesFactory : public IAutomobileFactory
{
public:
    Ford *GetFord()
    {
        return new TruckFord();
    }

    Mercedes *GetMercedes()
    {
        return new TruckMercedes();
    }
};

// concrete factory
class CarAutomobilesFactory : public IAutomobileFactory
{
public:
    Ford *GetFord()
    {
        return new CarFord();
    }

    Mercedes *GetMercedes()
    {
        return new CarMercedes();
    }
};

// concrete factory
class BusAutomobilesFactory : public IAutomobileFactory
{
public:
    Ford *GetFord()
    {
        return new BusFord();
    }

    Mercedes *GetMercedes()
    {
        return new BusMercedes();
    }
};

int main()
{
    IAutomobileFactory *automobileFactory;
    Ford *ford;
    Mercedes *mercedes;

    string choice = "truck";
    if (choice == "car")
    {
        automobileFactory = new CarAutomobilesFactory();
    }
    else if (choice == "truck")
    {
        automobileFactory = new TruckAutomobilesFactory();
    }
    else if (choice == "bus")
    {
        automobileFactory = new BusAutomobilesFactory();
    }

    ford = automobileFactory->GetFord();
    mercedes = automobileFactory->GetMercedes();
    ford->Show();
    mercedes->Show();
    if (automobileFactory)
    {
        delete automobileFactory;
    }
}