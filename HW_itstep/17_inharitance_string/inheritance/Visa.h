#pragma once
#include "DATE.h"
#include "FIO.h"
#include <iostream>
#include <string>

class Visa //: public DATE
{
private:
    //string id = "";

    string destination = "NONE";
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

    Visa(string destination, DATE start_date, DATE end_date) : destination(destination), start_date(start_date), end_date(end_date) { this->destination = destination; }

    Visa(string destination, int start_day, string start_month, int start_year, int end_day, string end_month, int end_year) : destination(destination) /* , DATE(start_day, start_month, start_year), DATE(end_day, end_month, end_year )*/
    {
        start_date = DATE(start_day, start_month, start_year);
        end_date = DATE(end_day, end_month, end_year);
    }

    Visa(const Visa &obj)
    {
        this->destination = obj.destination;
        this->start_date = obj.start_date;
        this->end_date = obj.end_date;
    }

    Visa(Visa &&obj)
    {
        this->destination.swap(obj.destination);
        this->start_date = move(obj.start_date);
        this->end_date = move(obj.end_date);
    }

    string getDestination() const { return destination; }
    void setDestination(string destination) { this->destination = destination; }
    DATE getStartDate() const { return start_date; }
    void setStartDate(DATE start_date) { this->start_date = start_date; }
    DATE getEndDate() const { return end_date; }
    void setEndDate(DATE end_date) { this->end_date = end_date; }

    void print()
    {
        cout << "Destination : \t" << destination << endl;
        cout << "Start date : \t" << start_date << "\nEnd date : \t" << end_date << " ";
    }

    Visa &operator=(const Visa &obj)
    {
        if (this == &obj)
        {
            return *this;
        }

        this->destination = obj.destination;
        this->start_date = obj.start_date;
        this->end_date = obj.end_date;

        return *this;
    }

    Visa &operator=(Visa &&obj)
    {
        if (this == &obj)
        {
            return *this;
        }

        this->destination.swap(obj.destination);
        this->start_date = move(obj.start_date);
        this->end_date = move(obj.end_date);

        return *this;
    }
};
