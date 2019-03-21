#include<iostream>
using namespace std;

int main()
{
    int num1 , num2 , pr;
    float me , sum;
    cout << "Input a first positibe integer : " ;
    cin >> num1;
    cout << "\nInput a second positibe integer : " ;
    cin >> num2;
    sum = num1 + num2;
    pr = num1 * num2;
    me = sum / 2;
    cout <<"\nThe sum of numbers is : " << sum;
    cout <<"\nThe product of numbers is : " << pr;
    cout <<"\nThe ariphmetical mean of numbers is : " << me;
}