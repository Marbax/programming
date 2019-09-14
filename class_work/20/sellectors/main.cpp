#include <iostream>

using namespace std;

class Test
{
private:
    int data = 0;

public:
    Test() = default;
    Test(int data);
    ~Test();

    int getData();

    void setData(int data);
};

Test::Test(int data) : data(data) {}

Test::~Test()
{
}

int Test::getData() { return data; }

void Test::setData(int data) { this->data = data; }

class TestPtr
{
private:
    Test *ptr = nullptr;

public:
    TestPtr(Test *ptr) : ptr(ptr) {}
    ~TestPtr() { delete ptr; }

    TestPtr(const TestPtr &obj) = delete; // запрещает копировать

    TestPtr(TestPtr &&obj) noexcept { swap(ptr, obj.ptr); }

    Test operator*() { return *ptr; }

    Test *operator->() { return ptr; }
};

int main()
{
    Test *pt = new Test(123);
    cout << pt->getData() << endl;

    TestPtr ptr(new Test(348));
    cout << ptr->getData() << endl;

    TestPtr copy = move(ptr);
    cout << copy->getData() << endl;
    //cout << ptr->getData() << endl; // нима указателя

    Test other = *copy;
    cout << other.getData() << endl;

    delete pt;
}