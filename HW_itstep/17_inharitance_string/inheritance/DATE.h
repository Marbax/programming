#pragma once
#include <iostream>
#include <string>

using namespace std;

class DATE
{
private:
    int bday_day = 0;
    string bday_month = "";
    int bday_year = 0;

public:
    DATE() = default;
    DATE(const int bday_day, const string bday_month, const int bday_year) : bday_day(bday_day), bday_year(bday_year), bday_month(bday_month) {}
    DATE(const DATE &obj)
    {
        bday_day = obj.bday_day;
        bday_month = obj.bday_month;
        bday_year = obj.bday_year;
    }
    DATE(DATE &&obj)
    {
        swap(bday_day, obj.bday_day);
        bday_month.swap(obj.bday_month);
        swap(bday_year, obj.bday_year);
    }
    int getBdayDay() const { return bday_day; }
    void setBdayDay(int bday_day) { this->bday_day = bday_day; }
    string getBdayMonth() const { return bday_month; }
    void setBdayMonth(string bday_month) { this->bday_month = bday_month; }
    int getBdayYear() const { return bday_year; }
    void setBdayYear(int bday_year) { this->bday_year = bday_year; }
    void print() const { cout << bday_day << " " << bday_month << " " << bday_year; }
    DATE &operator=(const DATE &obj)
    {
        if (this == &obj)
        {
            return *this;
        }

        bday_day = obj.bday_day;
        bday_month = obj.bday_month;
        bday_year = obj.bday_year;

        return *this;
    }

    DATE &operator=(DATE &&obj)
    {
        if (this == &obj)
        {
            return *this;
        }

        swap(bday_day, obj.bday_day);
        bday_month.swap(obj.bday_month);
        swap(bday_year, obj.bday_year);

        return *this;
    }

    friend ostream &operator<<(ostream &os, const DATE &obj)
    {
        os << obj.bday_day << " " << obj.bday_month << " " << obj.bday_year;
        return os;
    }

    friend istream &operator>>(istream &is, DATE &obj)
    {
        cout << "\nEnter day-> ";
        is >> obj.bday_day;
        cout << "\nEnter month-> ";
        is >> obj.bday_month;
        cout << "\nEnter year-> ";
        is >> obj.bday_year;
        return is;
    }
};
