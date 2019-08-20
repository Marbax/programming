#pragma once
#include "DATE.h"
#include "FIO.h"
#include <iostream>
#include <string>

class Visa
{
private:
    string id = "";
    string destination = "";
    DATE start_date;
    DATE end_date;
    int days_sum = 0;
    char visa_type;
    int entries_num = 0;
    string issued = "";
    DATE issued_date;
    string *pasport_id = nullptr;
    FIO *fio = nullptr;
    string visit_purp = "";

public:
    //Visa() = default;
    Visa(string id, string destination, DATE start_date, DATE end_date, int days_sum, char visa_type, int entries_num, string issued, DATE issued_date, string *pasport_id, FIO *fio, string visit_purp)
    {
        this->id = id;
        this->destination = destination;
        this->start_date = start_date;
        this->end_date = end_date;
        this->days_sum = days_sum;
        this->visa_type = visa_type;
        this->entries_num = entries_num;
        this->issued = issued;
        this->issued_date = issued_date;
        this->pasport_id = pasport_id;
        this->fio = fio;
        this->visit_purp = visit_purp;
    }
};
