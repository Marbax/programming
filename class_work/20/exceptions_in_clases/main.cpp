#include <iostream>

using namespace std;

class Name
{
private:
    string f_name, l_name;

public:
    Name(const string &f, const string &l);
    ~Name();

    string getFullName() const;
};

Name::Name(const string &f, const string &l)
{
    if (f.empty())
    {
        throw invalid_argument("First param is empty");
    }
    if (l.empty())
    {
        throw invalid_argument("Second param is empty");
    }
    f_name = f;
    l_name = l;
}

Name::~Name()
{
}
string Name::getFullName() const
{
    return f_name + " " + l_name;
}

class Person
{
private:
    Name name;
    int age;

public:
    Person(const string &f, const string &l, int age);
    ~Person();
};

Person::Person(const string &f, const string &l, int age) try : name(f, l), age(age)
{
}
catch (const invalid_argument &ex)
{
    cerr << "Error in class Person " << ex.what() << endl;
}

Person::~Person()
{
    cout << "~Person" << endl;
}

void myTerminate() // переопределение последней линии обработки исключений (перед закрытием)
{
    cout << " Text after main" << endl;
    exit(-1);
}
int main()
{
    set_terminate(myTerminate); // вызывает ф-ю перед тем как все крашнется

    string f_name = "", l_name = "";
    bool f;
    do
    {
        f = false;
        cout << "enter f_name" << endl;
        getline(cin, f_name);
        cout << "enter l_name" << endl;
        getline(cin, l_name);
        
            Person a(f_name, l_name, 23);
        
        /* catch (const invalid_argument &ex)
        {
            cerr << "Error in main " << ex.what() << endl;
            f = true;
        } */
        
    } while (f);
};