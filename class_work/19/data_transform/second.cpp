#include <iostream>
using namespace std;

class A
{
private:
    int data;

public:
    A(int d)
    {
        data = d;
    }
    virtual ~A() = default;

    int getData() { return data; }
    void setData()
    {
        A::data = data;
    }
    virtual void info()
    {
        cout << data << endl;
    }
};

class B : public A
{
private:
    string line;

public:
    B(const string &l, int d) : A(d)
    {
        line = l;
    }
    ~B();

    string getLine() { return line; }
    void setLine(const string &line)
    {
        B::line = line;
    }

    void info() override
    {
        cout << " B class" << getData() << " " << line << endl;
    }
    void methodB()
    {
        cout << "Method of class B:" << line << endl;
    }
};

int main()
{
    /*     A *pt = new B("Test", 123);
    pt->info();
    A *ptr = new A(123);
    ptr->info();
    //((B*)pt)->methodB(); // так не робит
    //((B*)ptr)->methodB();
    B *b = dynamic_cast<B *>(pt);
    if (b)
    {
        b->methodB();
    }
    else
    {
        cout << "error " << endl;
    }
    b = dynamic_cast<B *>(ptr);
    if (b)
    {
        b->methodB();
    }
    else
    {
        cout << "error " << endl;
    }

    delete ptr;
    delete pt; */

    const char *hello = "HELLO";
    long h = reinterpret_cast<long>(hello); // берет адрес памяти ? из-за размера инта в g++ не работает ,т.к. нужно 8 байт
    cout << h << endl;

    char *str = reinterpret_cast<char *>(h);
    cout << str << endl;

    int a = 123;
    int *ipa = &a;
    short *spa = reinterpret_cast<short *>(ipa);
    // short*sopa = (short*)(ipa);// сишный способ приобразования , перебирает все вариант ,из за чего дольше работает
    cout << *spa << endl;
}
