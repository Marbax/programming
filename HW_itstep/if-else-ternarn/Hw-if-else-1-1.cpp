#include<iostream>
using namespace std;

int main()
{
    short num;
    cout << "Welcome to a program that will tell you whether you have entered an number in 25-50 range or not.\n\nEnter the number : " ;
    cin >> num;
    if (num>=25&&num<=50) cout << "\n The number in the range of 25-50";
    else cout <<"This number isn't in the range of 25-50";
}