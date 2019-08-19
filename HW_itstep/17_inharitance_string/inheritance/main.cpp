/* 
Создайте класс Passport (паспорт), который будет содержать паспортную
информацию о гражданине Украины . С помощью механизма 
наследования , реализуйте класс ForeignPassport ( загран . паспорт )
производный от Passport . Напомним , что загран. паспорт содержит
помимо паспортных данных, также данные о визах.
 */

#include <iostream>
#include <string>
#include "ForeignPasport.h"

using namespace std;

int main()
{
    DATE date(17, "June", 1994);
    date.print();
    FIO fio("Nikita", "Morozov", "Evgenevich");
    cout << endl;
    fio.print();
    cout << endl;
    cout << endl;
    Pasport myne("CH56343", fio, date, "Khmelnytsky, the city");
    myne.print();
    cout << endl;
    cout << endl;
    Pasport another(myne);
    another.setFIO("petuh", "kuka", "reka");
    another.setBdayLoc("kuka zagon");
    another.print();
    cout << endl;
    cout << endl;
    Pasport third = move(another);
    third.print();
    cout << endl;
    cout << endl;
}
