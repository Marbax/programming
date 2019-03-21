#include<iostream>
using namespace std;
//Любое натуральное число (кроме нуля), которое делится на данное натуральное число, называется кратным данному числу.
int main()
{
    int num1, num2;
    float mod;
    cout << "Welcome to a program that will tell you whether first number is multiple of second number or not.\n\nEnter the numbers : " ;
    cin >> num1 >> num2;
    (num2%num1==0) ? cout << "first number is multiple of second number" : cout << "first number isn't multiple of second number";
}