#include<iostream>
using namespace std;

int main()
{
    int const eq = 100;
    int num , met , cen;
    cout << "Введите рост в сантиметрах : " ;
    cin >> num;
    met = num / eq;
    cen = num % eq;
    cout <<"\nThere are " << met  << " meter(s) and " << cen << " centimeter(s)";
}