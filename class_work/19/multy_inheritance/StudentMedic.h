#pragma once

#include "Student.h"
#include "Doctor.h"

class StudentMedic:public Student, public Doctor
{
public:
    StudentMedic(const string &n, int age, const string &s, int id);
    StudentMedic(const string &s, int id);

};

