#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator> // доп итераторы
#include <memory>   // умные указатели

using namespace std;

class Person
{
private:
    string f_name, l_name;
    int age;

public:
    Person(const string &fn, const string &ln, const int &ag) : f_name(fn), l_name(ln), age(ag) {}
    ~Person() {}

    const string &getFName() const { return f_name; }
    const string &getLName() const { return l_name; }
    const int &getAge() const { return age; }

    void setFName(const string &FName) { f_name = FName; }
    void setLName(const string &LName) { l_name = LName; }
    void setAge(const int &Age) { age = Age; }

    friend ostream &operator<<(ostream &os, const Person &p)
    {
        os << "First name: " << p.f_name << endl;
        os << "Last name: " << p.l_name << endl;
        os << "Age : " << p.age << endl;
        os << "+++++++++++++++++++++++++++++++++++++";
        return os;
    }
};

int main()
{
    vector<shared_ptr<Person>> people;
    people.push_back(shared_ptr<Person>(new Person("Ivan", "Ivanov", 23)));
    people.push_back(shared_ptr<Person>(new Person("Petr", "Bugger", 11)));
    people.push_back(shared_ptr<Person>(new Person("Masha", "Wanker", 44)));
    people.push_back(shared_ptr<Person>(new Person("Ivan", "Ivanov", 23)));

    transform(people.begin(), people.end(), ostream_iterator<Person>(cout, "\n"), [](shared_ptr<Person> val) -> Person { return *val; });

    cout << "\nSorted : " << endl;
    sort(people.begin(), people.end(), [](shared_ptr<Person> a, shared_ptr<Person> b) -> bool { return a->getAge() < b->getAge(); }); // сортирует по возрасту
    transform(people.begin(), people.end(), ostream_iterator<Person>(cout, "\n"), [](shared_ptr<Person> val) -> Person { return *val; });

    copy(people.begin(), people.end(), ostream_iterator<shared_ptr<Person>>(cout, " "));
}