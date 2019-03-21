#include<iostream>
using namespace std;

int main()
{
    int num;// 
    cout << "Welcome to a program that will tell you whether you have entered an even number or not.\n\nEnter the number : " ;
    cin >> num;
    if (num!=0){
        if (!(num%2)) 
            {cout << "There are even number";
            }
        else cout << "There are odd number";
    }
    else cout << "There are zero";
}