#pragma once
#include <iostream>
#include <string>

using namespace std;

class FIO
{
private:
    string name = "";
    string last_name = "";
    string middle_name = "";

public:
    FIO() = default;
    FIO(const string name, const string last_name, const string middle_name)
    {
        this->name = name;
        this->last_name = last_name;
        this->middle_name = middle_name;
    }
    FIO(const FIO &obj)
    {
        name = obj.name;
        last_name = obj.last_name;
        middle_name = obj.middle_name;
    }
    FIO(FIO &&obj)
    {
        name.swap(obj.name);
        last_name.swap(obj.last_name);
        middle_name.swap(obj.middle_name);
    }
    string getName() const { return name; }
    void setName(string name) { this->name = name; }
    string getLastName() const { return last_name; }
    void setLastName(string last_name) { this->last_name = last_name; }
    string getMiddleName() const { return middle_name; }
    void setMiddleName(string middle_name) { this->middle_name = middle_name; }
    void print() const { cout << last_name << " " << name << " " << middle_name << " "; }
    FIO &operator=(const FIO &obj)
    {
        if (this == &obj)
        {
            return *this;
        }

        name = obj.name;
        last_name = obj.last_name;
        middle_name = obj.middle_name;
        return *this;
    }
    FIO &operator=(FIO &&obj)
    {
        if (this == &obj)
        {
            return *this;
        }
        name.swap(obj.name);
        last_name.swap(obj.last_name);
        middle_name.swap(obj.middle_name);
        return *this;
    }
};
