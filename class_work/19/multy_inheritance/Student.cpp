

#include "Student.h"

Student::Student(const string &n, int a, int id):Person(n,a)
{
    this->id = id;
}

int Student::getId() const
{
    return id;
}

void Student::setId(int id)
{
    Student::id = id;
}
