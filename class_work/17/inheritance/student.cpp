#include <iostream>
#include <string.h>

using namespace std;

class Person
{
private:
    char *name = nullptr;
    int age = 0;

public:
    Person() = default;

    Person(const char *str, int val)
    {
        name = strdup(str);
        age = val;
    }

    Person(const Person &obj)
    {
        name = strdup(obj.name);
        age = obj.age;
    }

    Person(Person &&obj)
    {
        swap(name, obj.name);
        swap(age, obj.age);
    }

    ~Person()
    {
        if (name)
        {
            delete[] name;
        }
    }

    void setName(char *str)
    {
        if (name)
        {
            char *tmp = name;
            name = str;
            delete[] tmp;
        }
        name = str;
    }

    char *getName() const { return name; }

    void setAge(int val) { age = val; }

    int getAge() const { return age; }

    Person &operator=(const Person &obj)
    {
        if (this == &obj)
        {
            return *this;
        }
        delete[] name;

        name = strdup(obj.name);
        age = obj.age;

        return *this;
    }
    Person &operator=(Person &&obj)
    {
        if (this == &obj)
        {
            return *this;
        }
        delete[] name;

        name = obj.name;
        age = obj.age;
        obj.name = nullptr;

        return *this;
    }
};

struct Mark
{
    string subject;
    int mark;
};

class Student : public Person
{
private:
    Mark *arr = nullptr;
    int size;

public:
    Student(const char *str, int val) : Person(str, val)
    {
        size = 5;
        arr = new Mark[5];
    }

    ~Student()
    {
        if (size)
        {
            delete[] arr;
        }
    }

    Student(const Student &obj) : Person(obj) // в конструкторе копирования вызываем конструтор копирования базового класса
    {
        size = obj.size;
        arr = new Mark[size];
        for (size_t i = 0; i < size; i++)
        {
            arr[i] = obj.arr[i];
        }
    }

    Student(Student &&obj) : Person(move(obj))
    {
        swap(size, obj.size);
        swap(arr, obj.arr);
    }

    int getSize() const
    {
        return size;
    }

    Mark &operator[](int pos)
    {
        return arr[pos];
    }

    Student &operator=(const Student &obj)
    {
        if (this == &obj)
        {
            return *this;
        }

        Person::operator=(obj); // вызывается оператор присваевания базового класса

        if (size)
        {
            delete[] arr;
        }
        size = obj.size;
        arr = new Mark[size];
        for (size_t i = 0; i < size; i++)
        {
            arr[i] = obj.arr[i];
        }
        return *this;
    }

    Student &operator=(Student &&obj)
    {
        if (this == &obj)
        {
            return *this;
        }

        size = obj.size;
        arr = obj.arr;
        obj.arr = nullptr;
        obj.size = 0;

        Person::operator=(move(obj));

        return *this;
    }

private:
};

int main()
{
    Person a("Ivan", 23);
    cout << a.getName() << " " << a.getAge() << endl;

    Student pedro("Pedro", 21);
    pedro[0].subject = "Math";
    pedro[0].mark = 12;
    pedro[1].subject = "Eng";
    pedro[1].mark = 11;
    pedro[2].subject = "Biology";
    pedro[2].mark = 8;
    pedro[3].subject = "Some";
    pedro[3].mark = 12;
    pedro[4].subject = "Another";
    pedro[4].mark = 12;

    Student petr = pedro;
    cout << petr.getName()   << endl;
    for (size_t i = 0; i < petr.getSize(); i++)
    {
        cout << "  " << petr[i].subject << " = " << petr[i].mark << endl;
    }
}