#include<iostream>
using namespace std;

int main()
{
    float num1, num2, num3;
    cout << "Welcome to a program that will say you which number isn't equalent to another two .\n\nEnter three numbers and two oh them should be similar : " ;
    cin >> num1 >> num2 >> num3;
    (num1 == num2) ? cout << "third number is different" : (num1 == num3) ? cout << "second number different" << endl : cout << "first number different";
}