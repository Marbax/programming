/* Создать абстрактный базовый класс Automobile с полем «number» и
чисто виртуальным деструктором. 
    От класса Automobile наследуется два
    абстрактных класса: 
    Common(поле «color») и Special(поле«organization»). 
        От Common наследуются три класса: Sedan, Minivan,Pickup. 
        От класса Special наследуются абстрактный класс Builder с чисто
        виртуальной функцией work и абстрактный класс Emergency c чисто
        виртуальной функцией signal. 
            От класса Builder наследуются три класса:
            TruckCrane, ConcreteMixer, Tipper, переопределяющие метод work.
            От класса Emergency наследуются три класса: Police, Ambulance, FireEngine,
            переопределяющие метод signal. */

/* 
                          ------------------Automobile-----------------------------
                          |                                                       |
              --------Common---------                          -----------------Special-----------------------
              |         |           |                          |                                             |
            Sedan     Minivan    Pickup         -------------Builder---------                    --------Emergency---------
                                                |              |            |                    |           |            |
                                            TruckCrane   ConcreteMixer    Tipper              Police     Ambulance     FireEngine

 */

/* Не все методы должны быть виртуальными. При переопределении метода, его нужно помечать как override  */

// нет оверрайда ,потому что ф-и чисто виртуальные и нечего переопределять "member function declared with 'override' does not override a base class member"

#include <iostream>
#include "./Automobile/Common/Sedan.h"
#include "./Automobile/Common/Minivan.h"
#include "./Automobile/Common/Pickup.h"
#include "./Automobile/Special/Builder/TruckCrane.h"
#include "./Automobile/Special/Builder/ConcreteMixer.h"
#include "./Automobile/Special/Builder/Tipper.h"
#include "./Automobile/Special/Emergency/Police.h"
#include "./Automobile/Special/Emergency/Ambulance.h"
#include "./Automobile/Special/Emergency/FireEngine.h"

using namespace std;

int main()
{
    Ambulance amb;
    amb.setNumber("KI00000");
    amb.setOrganization("Low");
    cout << amb.getNumber() << "  " << amb.getOrganization() << " ";
    amb.signal();

    Minivan lol("ka124141", "yellow");
    cout << lol.getNumber() << "  " << lol.getColor() << endl;

    TruckCrane tracker("ZZ22222", "benz");
    cout << tracker.getNumber() << "  " << tracker.getOrganization() << " ";
    tracker.work();
}
