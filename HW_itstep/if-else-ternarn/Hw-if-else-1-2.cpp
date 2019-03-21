#include<iostream>
using namespace std;

int main()
{
    int num;
    cout << "Welcome to a program that will tell you whether you have entered an number divisable by three or not.\n\nEnter the integer number : " ;
    cin >> num;
    if (num%3==0) cout << " The number " << num << " is totally divisible by three";
    else cout << " The number " << num << " is completely divisible by three";
}