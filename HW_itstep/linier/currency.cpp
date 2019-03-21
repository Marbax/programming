#include<iostream>
using namespace std;

int main()
{
    float const const_d = 0.036 , const_e = 0.032 , const_r = 2.39;
    float uah , rub , eur , dol;
    cout << "Please enter amount of your money in uah : " ;
    cin >> uah;
    rub = uah * const_r;
    dol = uah * const_d;
    eur = uah * const_e;
    cout <<"\nThere are " << rub << " rubles";
    cout <<"\nThere are " << dol << " dollars";
    cout <<"\nThere are " << eur  << " euro";
}