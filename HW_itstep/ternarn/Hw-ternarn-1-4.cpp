#include<iostream>
using namespace std;
//безпонятия как сделать ,все варианты баганые выходят 
int main()
{
    float num1, num2, num3;
    cout << "Welcome to a program that will tell you which number(second or third) is closer to first number .\n\nEnter three numbers : " ;
    cin >> num1 >> num2 >> num3;
    ((num2-num1) < (num3-num1)) ? cout << "second number is closer , distance is " << (num2-num1) : ((num3-num1) < (num2-num1)) ? cout << "third number is closer , distance is " << (num3-num1) : cout << "they are equalent , distance is :" << (num3 - num1);
}
//