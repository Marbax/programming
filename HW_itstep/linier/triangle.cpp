#include<iostream>
using namespace std;

int main()
{
    float len , hei , s;
    //cout << "Calculate the area of a triangle."
    cout << "Calculate the area of a triangle.\n\nEnter the source data:\nInput a triangle base length : " ;
    cin >> len;
    cout << "\nInput a triangle heihgt : " ;
    cin >> hei;
    s = 0.5 * len * hei;
    cout <<"\nThe area of a triangle is " << s << " sq. c.";
}