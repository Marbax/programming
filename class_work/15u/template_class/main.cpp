#include <iostream>
#include "Test.h"

using namespace std;

int main()
{
    Test<int> a(123);
    cout << a.getData() << endl;
    Test<int> b(100);
    cout << b.getData() << endl;
    Test<int> res = a + b;
    cout << res.getData() << endl;

    Test<const char *> str_1("Hello"), str_2("world");
    cout << str_1.getData() << endl;
    cout << str_2.getData() << endl;
    Test<const char *> str = str_1 + " " + str_2;
    cout << str.getData() << endl;

    Test<int *> g(3, 123), f(6,456);
    Test<int *> result = g + f;
    cout << "SIZE " << result.getSize() << endl;
    for (size_t i = 0; i < result.getSize(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
}