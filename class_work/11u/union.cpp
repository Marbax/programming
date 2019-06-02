#include <iostream>

using namespace std;

union Test {
    int a;
    short b;
};

int main()
{
    Test obj;
    obj.a = 5;
    cout << obj.b << endl; // так делать нельзя , работает только при уменьшении памяти под переменную, в ином случае - будет мусор
    cout << sizeof(obj.b) << endl;
}