#pragma once
#include "Pasport.h"
#include "Visa.h"
#include <iostream>
#include <string>

class ForeignPasport : public Pasport
{
private:
    DATE issued_date;
    DATE expires_date;
    Visa *visa_arr = nullptr;

public:
    //ForeignPasport()=default;

    ForeignPasport(Pasport &obj, DATE issued_date, DATE expires_date) : Pasport(obj), issued_date(issued_date), expires_date(expires_date) {}

    void AddVisa(string id, string destination, DATE start_date, DATE end_date, int days_sum, char visa_type, int entries_num, string issued, DATE issued_date, string *pasport_id, FIO *fio, string visit_purp)
    {
        Visa::Visa(id, destination, start_date, end_date, days_sum, visa_type, entries_num, issued, issued_date, pasport_id, fio, visit_purp);
    }

    Visa &operator[](int pos) { return visa_arr[pos]; }
};
