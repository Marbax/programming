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
    cout << "\n\n"
         << fio;
    cout << endl;
    cout << endl;
    //Pasport myne("CH56343", "Nikita", "Morozov", "Evgenevich", 17, "June", 1994, "Ukraine", "Khmelnytsky, the city");
    Pasport myne("CH56343", fio, date, "Ukraine", "Khmelnytsky, the city");
    myne.print();
    cout << endl;
    cout << endl;
    Pasport another(myne);
    another.setFIO("Stepan", "Kuku", "Gotta");
    another.setBdayLoc("Zhmerenka");
    another.print();
    cout << endl;
    cout << endl;
    Pasport third = move(another);
    third.print();
    cout << endl;
    cout << "==========================================" << endl;

    DATE issued_date(15, "Marche", 2019);
    ForeignPasport my_foreign("CH111111", fio, date, "Ukraine", "Kyev, the city", issued_date);
    my_foreign.print();

    DATE pol_start(22, "Jule", 2020);
    DATE pol_end(29, "Jule", 2020);
    my_foreign.AddVisa("Poland", pol_start, pol_end);
    my_foreign.AddVisa("Italy", 12, "Jule", 2020, 22, "Jule", 2020);
    my_foreign.AddVisa("UAE", 1, "Jule", 2021, 22, "September", 2021);
    cout << "\n\n#SIZE/COUNT : " << my_foreign.getVisaSize() << "    " << my_foreign.getVisaCount() << endl;
    my_foreign.print();
}
