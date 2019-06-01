#include <iostream>

using namespace std;

/* void print_bit(char c)
{
    for (int i = 7; i >= 0; --i)
    {
        cout << ((c >> i) & 1);
    }
    cout << endl;
} */
void print_bit(unsigned c)
{
    for (int i = 31; i >= 0; --i)
    {
        cout << ((c >> i) & 1);
    }
    cout << endl;
}

int main()
{
    char a = 'A';
    print_bit(a);
    a = 127;
    print_bit(a);

    unsigned data;
    short tmp;
    cout << "enter first num = ";
    cin >> tmp;
    data = tmp;
    cout << "enter second num = ";
    cin >> tmp;
    data = (data << 16) | tmp; // в int влазит два short ,
    // сдвигаем на 16 бит в право старое число , через или записываем туда второй short
    print_bit(data);

    cout<<(data>>16)<<endl;//вывод первого числа
    cout<<(data&65535)<<endl;//накладываем 16 единиц через десятичную систему
    cout<<(data&0b11111111)<<endl;//накладываем 16 единиц через двоичную систему(удобнее) , то же что и выше
}