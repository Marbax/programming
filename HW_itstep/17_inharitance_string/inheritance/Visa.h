#pragma once
#include "DATE.h"
#include "FIO.h"
#include <iostream>
#include <string>

class Visa
{
private:
    //string id = "";

    string destination = "";
    DATE start_date;
    DATE end_date;

    //int days_sum = 0;
    //char visa_type;
    //int entries_num = 0;
    //string issued = "";
    //DATE issued_date;
    //string *pasport_id = nullptr;
    //FIO *fio = nullptr;
    //string visit_purp = "";

public:
    /* Visa(string id, string destination, DATE start_date, DATE end_date, int days_sum, char visa_type, int entries_num, string issued, DATE issued_date, string *pasport_id, FIO *fio, string visit_purp)
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
    } */

    Visa() = default;
    Visa(string destination, DATE start_date, DATE end_date) : destination(destination), start_date(start_date), end_date(end_date) {}

    Visa(const Visa &obj)
    {
        this->destination = destination;
        this->start_date = start_date;
        this->end_date = end_date;
    }

    Visa(Visa &&obj)
    {
        this->destination.swap(destination);
        this->start_date = move(start_date);
        this->end_date = move(end_date);
    }

    string getDestination() const { return destination; }
    void setDestination(string destination) { this->destination = destination; }
    DATE getStartDate() const { return start_date; }
    void setStartDate(DATE start_date) { this->start_date = start_date; }
    DATE getEndDate() const { return end_date; }
    void setEndDate(DATE end_date) { this->end_date = end_date; }

    void print()
    {
        cout << "\t\tDestination : " << destination << endl;
        cout << "\tStart date : " << start_date << "\t\tEnd date : " << end_date << " ";
    }

    Visa &operator=(const Visa &obj)
    {
        if (this == &obj)
        {
            return *this;
        }

        this->destination = destination;
        this->start_date = start_date;
        this->end_date = end_date;

        return *this;
    }

    Visa &operator=(Visa &&obj)
    {
        if (this == &obj)
        {
            return *this;
        }

        this->destination.swap(destination);
        this->start_date = move(start_date);
        this->end_date = move(end_date);

        return *this;
    }
};
