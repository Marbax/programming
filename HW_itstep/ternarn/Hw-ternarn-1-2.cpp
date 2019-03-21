#include<iostream>
using namespace std;

int main()
{
    float num1, num2, num3;
    cout << "Welcome to a program.\n\nEnter the numbers three : " ;
    cin >> num1 >> num2 >> num3;
    (num1 < num2 < num3) ? cout << num1 * 2 << " " << num2 * 2 << " " <<  num3 *2 : cout << -num1 << " " << -num2 << " " << -num3;
}