#include <iostream>
#include <vector>
using namespace std;

class Person
{
private:
    int id;
    int age;

public:
    Person(int id, int age)
    {
        this->id = id;
        this->age = age;
    }

    void setId(int val) { this->id = val; }
    int getId() { return id; }
    void setAge(int val) { this->age = val; }
    int getAge() { return age; }
};

class Group
{
private:
    vector<Person *> arr;

public:
    Group() = default;
    void addPerson(Person *pt)
    {
        arr.push_back(pt);
    }
    void delPerson(int pos)
    {
        arr.erase(arr.begin() + pos);
    }
    Person *&operator[](int pos)
    {
        return arr[pos];
    }
};


int main()
{
    Person *a = new Person(1, 23);
    Person *b = new Person(2, 23);
    Person *c = new Person(3, 23);
    Person *d = new Person(4, 23);

    Group group;
    group.addPerson(a);
    group.addPerson(b);
    group.addPerson(c);
    group.addPerson(d);
    for (size_t i = 0; i < 4; i++)
    {
        cout << group[i]->getId() << " ";
    }
    cout << endl;

    delete a;
    delete b;
    delete c;
    delete d;
}