
#include "StudentMedic.h"

StudentMedic::StudentMedic(const string &n, int age, const string &s, int id)
        : Student(n, age, id), Doctor(n, age, s)
{

}

StudentMedic::StudentMedic(const string &s, int id) : Student("Ivan",19, id),Doctor("Aybolit",57,s)
{

}
