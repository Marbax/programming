#include <iostream>
#include "bird.h"
#include "fish.h"
#include "kenguru.h"

using namespace std;

int main()
{

    //    Animal a("Animal");
    //    Bird b("Kesha");
    //    Fish c("Nemo");
    //    Kenguru d("Bobby");
    //    a.move();
    //    b.move();
    //    c.move();
    //    d.move();

    srand(time(0));
    Animal *zoo[10]; // working only if childs have parrent methods
    for (size_t i = 0; i < 10; i++)
    {
        switch (rand() % 4)
        {
        case 0:
            zoo[i] = new Animal("Animal");
            break;
        case 1:
            zoo[i] = new Bird("Kesha");
            break;
        case 2:
            zoo[i] = new Fish("Nemo");
            break;
        case 3:
            zoo[i] = new Kenguru("Bobby Jack");
            break;

        default:
            zoo[i] = new Animal("the thisg");
            break;
        }
    }

    for (auto item : zoo) // working only with static memory
    {
        item->move();
    }

    for (auto item : zoo)
    {
        delete item;
    }
}