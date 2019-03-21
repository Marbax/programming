#include<iostream>
using namespace std;

int main()
{
    float pr , wei , res;
    cout << "Calculate the purchase price.\n\nEnter the source data:\nThe price of one kilogram of apples (uah)-> " ;
    cin >> pr;
    cout << "\nApples weight (kg)-> " ;
    cin >> wei;
    res = pr * wei;
    cout <<"\nThe purchase price :  " << res << " uah";
}