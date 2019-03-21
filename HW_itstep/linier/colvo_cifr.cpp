#include<iostream>
using namespace std;

int main()
{
    int num , sum;
    cout << "Welcome to a program that will tell you the count of digits and and the sum of numbers in entered number .\n\nEnter the number : " ;
    cin >> num;
    if (num<100&&num>0){
        cout << "There are " << num+1 << " digits , and they sum are " << num*(num+1)/2;
    }
    else cout << "Your number bigger then ont hundred ,equalent or lether then zero";
}