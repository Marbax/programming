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
    int visa_size = 0;
    int visa_count = 0;
    static const int RESERVED = 3;

public:
    //ForeignPasport()=default;

    ForeignPasport(Pasport obj, DATE issued_date /* , DATE expires_date */) : Pasport(obj), issued_date(issued_date), expires_date(issued_date) { expires_date.setBdayYear(issued_date.getBdayYear() + 10); }

    ForeignPasport(const string id, const FIO fio, const DATE date, const string country, const string bday_loc, DATE issued_date) : Pasport(id, fio, date, country, bday_loc), issued_date(issued_date), expires_date(issued_date) { expires_date.setBdayYear(issued_date.getBdayYear() + 10); }

    ForeignPasport(const ForeignPasport &obj) : Pasport(obj)
    {
        this->issued_date = issued_date;
        this->expires_date = expires_date;
        if (obj.visa_size)
        {
            visa_size = obj.visa_size;
            //visa_count = obj.visa_size + RESERVED;
            (visa_size + RESERVED < obj.visa_count) ? visa_count = obj.visa_count + RESERVED : visa_count = obj.visa_count;
            visa_arr = new Visa[visa_count];

            for (size_t i = 0; i < obj.visa_size; i++)
            {
                visa_arr[i] = obj.visa_arr[i];
            }
        }
    }

    ForeignPasport(ForeignPasport &&obj) : Pasport(move(obj))
    {
        issued_date = move(obj.issued_date);
        expires_date = move(obj.expires_date);
        swap(visa_arr, obj.visa_arr);
        swap(visa_size, obj.visa_size);
        if (visa_size + RESERVED < obj.visa_count)
        {
            visa_count = obj.visa_count + RESERVED;
            obj.visa_count = 0;
        }
        else
        {
            visa_count = obj.visa_count;
            obj.visa_count = 0;
        }
    }

    ~ForeignPasport()
    {
        if (visa_size)
        {
            delete[] visa_arr;
        }
    }

    DATE getIssuedDate() const { return issued_date; }
    void setIssuedDate(DATE issued_date) { this->issued_date = issued_date; }
    DATE getExpiresDate() { return expires_date; }
    void setExpiresDate(DATE expires_date) { this->expires_date = expires_date; }

    void Reloc()
    {
        size_t tmp_capacity = (visa_count ? visa_count : 1) + RESERVED;
        Visa *tmp = new Visa[tmp_capacity];
        for (size_t i = 0; i < visa_size; i++)
        {
            tmp[i] = visa_arr[i];
        }
        delete[] visa_arr;
        visa_arr = tmp;
        visa_count = tmp_capacity;
    }

    void AddVisa(string destination, DATE start_date, DATE end_date)
    {
        if (visa_size + 1 > visa_count)
        {
            Reloc();
        }

        visa_arr[visa_size++] = Visa(destination, start_date, end_date);
    }
    void AddVisa(Visa &obj)
    {
        if (visa_size + 1 > visa_count)
        {
            Reloc();
        }

        visa_arr[visa_size++] = Visa(obj);
    }

    void print()
    {
        Pasport::print();
        cout << endl;
        cout << "Issued date : " << issued_date << "\nExpires date : " << expires_date << endl;
        for (size_t i = 0; i < visa_size; i++)
        {
            visa_arr[i].print();
            cout << "\n"
                 << endl;
        }
    }

    ForeignPasport &operator=(const ForeignPasport &obj)
    {
        if (this == &obj)
        {
            return *this;
        }

        this->issued_date = issued_date;
        this->expires_date = expires_date;
        if (obj.visa_size)
        {
            visa_size = obj.visa_size;
            //visa_count = obj.visa_size + RESERVED;
            (visa_size + RESERVED < obj.visa_count) ? visa_count = obj.visa_count + RESERVED : visa_count = obj.visa_count;
            visa_arr = new Visa[visa_count];

            for (size_t i = 0; i < obj.visa_size; i++)
            {
                visa_arr[i] = obj.visa_arr[i];
            }
        }

        Pasport::operator=(obj);

        return *this;
    }

    ForeignPasport &operator=(ForeignPasport &&obj)
    {
        if (this == &obj)
        {
            return *this;
        }

        Pasport::operator=(move(obj));

        issued_date = move(obj.issued_date);
        expires_date = move(obj.expires_date);
        swap(visa_arr, obj.visa_arr);
        swap(visa_size, obj.visa_size);
        if (visa_size + RESERVED < obj.visa_count)
        {
            visa_count = obj.visa_count + RESERVED;
            obj.visa_count = 0;
        }
        else
        {
            visa_count = obj.visa_count;
            obj.visa_count = 0;
        }

        return *this;
    }

    Visa &operator[](int pos) { return visa_arr[pos]; }
};
