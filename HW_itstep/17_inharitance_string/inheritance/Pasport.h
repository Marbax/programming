#pragma once
#include "FIO.h"
#include "DATE.h"
#include <iostream>
#include <string>

using namespace std;

class Pasport
{
private:
    string id = "";
    FIO fio;
    DATE date;
    string bday_loc = "";

public:
    Pasport() = default;
    Pasport(const string id, const FIO fio, const DATE date, const string bday_loc)
    {
        this->id = id;
        this->fio = fio;
        this->date = date;
        this->bday_loc = bday_loc;
    }
    Pasport(const string id, const string name, const string last_name, const string middle_name, const int bday_day, const string bday_month, const int bday_year, const string bday_loc)
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
        this->bday_loc = bday_loc;
    }
    Pasport(const Pasport &obj)
    {
        id = obj.id;
        fio = obj.fio;
        date = obj.date;
        bday_loc = obj.bday_loc;
    }
    Pasport(Pasport &&obj)
    {
        id.swap(obj.id);
        fio = move(obj.fio);
        date = move(obj.date);
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
    void setFIO(FIO &obj)
    {
        fio = obj;
    }
    DATE getDATE() const { return date; }
    void setDATE(int bday_day, string bday_month, int bday_year)
    {
        date.setBdayDay(bday_day);
        date.setBdayMonth(bday_month);
        date.setBdayYear(bday_year);
    }
    void setDATE(DATE &obj)
    {
        date = obj;
    }
    string getBdayLoc() { return bday_loc; }
    void setBdayLoc(string bday_loc) { this->bday_loc = bday_loc; }
    void print()
    {
        cout << "\t" << id << endl;
        fio.print();
        cout << endl;
        date.print();
        cout << endl;
        cout << bday_loc << " ";
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
        FIO fio(move(obj.fio));
        DATE date(move(obj.date));
        bday_loc.swap(obj.bday_loc);

        return *this;
    }
};
