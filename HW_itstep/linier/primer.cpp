#include<iostream>
using namespace std;

int main()
{
    float x , y;
    cout << "Please enter value : " ;
    cin >> x ;
    y = (-2.7 * (x * x * x)) + (0.23 * (x * x)) - 1.4;
    cout <<"\nResult is : " << y << endl;
}