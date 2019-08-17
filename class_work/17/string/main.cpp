#include <iostream>
#include <string> // основной набор ф-й из basic string

using namespace std;

int main()
{
    string str; /* ("Hello");
    cout << str.size() << endl;
    cout << str.capacity() << endl;
    cout << str.max_size() << endl; */
    cout << "Enter string => ";
    getline(cin, str); //откуда и куда читать
    cout << str << endl;

    /* int pos = str.length() / 2;
    str = str.substr(pos) + str.substr(0, pos); // от позиции до конца ,если нет второго параметра
    cout << str << endl; */

    int pos = str.find(" ");
    str = str.substr(pos + 1) + ' ' + str.substr(0, pos);
    cout << str << endl;
}