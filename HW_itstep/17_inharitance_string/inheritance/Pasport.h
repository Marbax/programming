#pragma once
#include "FIO.h"
#include "DATE.h"
#include <iostream>
#include <string>

using namespace std;

class Pasport
{
private:
    string id = "NONE";
    FIO fio;
    DATE date;
    string country = "NONE";
    string bday_loc = "NONE";

public:
    Pasport() = default;
    Pasport(string id, FIO fio, DATE date, string country, string bday_loc)
    {
        this->id = id;
        this->fio = fio;
        this->date = date;
        this->country = country;
        this->bday_loc = bday_loc;
    }
    Pasport(string id, string name, string last_name, string middle_name, int bday_day, string bday_month, int bday_year, string country, string bday_loc)
    {
        this->id = id;
        setFIO(name, last_name, middle_name);
        //this->fio.setName(name);
        //this->fio.setLastName(last_name);
        //this->fio.setMiddleName(middle_name);
        setDATE(bday_day, bday_month, bday_year);
        //this->date.setBdayDay(bday_day);
        //this->date.setBdayMonth(bday_month);
        //this->date.setBdayMonth(bday_year);
        this->country = country;
        this->bday_loc = bday_loc;
    }
    Pasport(const Pasport &obj)
    {
        id = obj.id;
        fio = obj.fio;
        date = obj.date;
        country = obj.country;
        bday_loc = obj.bday_loc;
    }
    Pasport(Pasport &&obj)
    {
        id.swap(obj.id);
        fio = move(obj.fio);
        date = move(obj.date);
        country.swap(obj.country);
        bday_loc.swap(obj.bday_loc);
    }
    string getId() const { return id; }
    void setId(string id) { this->id = id; }
    FIO getFIO() const { return fio; }
    void setFIO(string name, string last_name, string middle_name)
    {
        fio.setName(name);
        fio.setLastName(last_name);
        fio.setMiddleName(middle_name);
    }
    void setFIO(FIO &obj) { fio = obj; }
    DATE getDATE() const { return date; }
    void setDATE(int bday_day, string bday_month, int bday_year)
    {
        date.setBdayDay(bday_day);
        date.setBdayMonth(bday_month);
        date.setBdayYear(bday_year);
    }
    string getCountry() const { return country; }
    void setCountry(string country) { this->country = country; }
    void setDATE(DATE &obj) { this->date = obj; }
    string getBdayLoc() const { return bday_loc; }
    void setBdayLoc(string bday_loc) { this->bday_loc = bday_loc; }
    void print() const
    {
        cout << "\t" << id << endl;
        cout << "\t   \342\230\272" << endl;
        /* cout << "Surname : \t" << fio.getLastName() << endl;
        cout << "Name : \t\t" << fio.getName() << endl;
        cout << "Middle name : \t" << fio.getMiddleName() << endl; */
        cout << fio;
        //fio.print();
        cout << "Birth date : \t";
        //date.print();
        cout << date << endl;
        cout << "Birth place : \t" << bday_loc << endl;
        cout << "Country : \t" << country << " ";
    }

    Pasport &operator=(const Pasport &obj)
    {
        if (this == &obj)
        {
            return *this;
        }

        id = obj.id;
        fio = obj.fio;
        date = obj.date;
        country = obj.country;
        bday_loc = obj.bday_loc;

        return *this;
    }
    Pasport &operator=(Pasport &&obj)
    {
        if (this == &obj)
        {
            return *this;
        }

        id.swap(obj.id);
        fio = move(obj.fio);
        date = move(obj.date);
        country.swap(obj.country);
        bday_loc.swap(obj.bday_loc);

        return *this;
    }
};
