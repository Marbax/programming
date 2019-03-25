#include <iostream>
using namespace std;

int main()
{
    float num;
    int sec, b_dot, a_dot;
    cout << "Welcome to a program that will translate time into seconds.\n\nEnter the time(minutes.seconds) : ";
    cin >> num;
    a_dot = (float(num) - (int)num) * 100;
    if (a_dot < 60)
    {
        b_dot = (int)num * 60;
        sec = a_dot + b_dot;
        cout << "There are " << sec << " seconds";
    }
    else
        cout << "\nError. Amount of seconds can't be more than 60";
}