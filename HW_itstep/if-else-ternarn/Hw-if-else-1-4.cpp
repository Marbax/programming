#include<iostream>
using namespace std;

int main()
{   // january = 31 , feruary = 28 , march = 31 , april = 30 , may = 31 , june = 30 , july = 31 
    // august = 31 , september = 30 , october = 31 , november = 30 , december = 31
    // 31 = 1,3,5,7,8,10,12
    // 30 = 4,6,9,11
    // 28(leap 29) = 2 
    int day ,month ,year;
    cout << "Welcome to a program that will say you whats the next day.\n\nEnter the date (day month year) : " ;
    cin >> day >> month >> year;
    if (  (day<32&&day>0) && (month<13&&month>0) ) 
    {
        if (  day < 28 ) cout << "Tommorow : " << day+1 <<" "<< month << " " << year;  //lower date        
        else if (day < 30) //28 || 29
            {
                if (month == 2) 
                {
                    cout << "February .";
                    if ( (year%400==0) || ((year%4==0)&&(!(year%100==0))) )           //leap year
                    {
                    cout << "Leap year .Tommorow : " << day+1 <<" "<< month << " " << year;
                    }
                    else 
                    {
                    day = 1;
                    month++;
                    cout << "Not leap year .Tommorow : " << day <<" "<< month << " " << year;
                    }

                }
                else cout << "Tommorow : " << day+1 <<" "<< month << " " << year;
            }
            else if ( (day == 30) && (month!=2) )                                                         //day 30
                {
                    if ( (month == 4)||(month == 6)||(month == 9)||(month == 11) )
                    {
                        day=1;
                        month++;
                        cout << "Tommorow : " << day <<" "<< month << " " << year;
                    }
                    else cout << "Tommorow : " << day+1 <<" "<< month << " " << year;

                }
                else if (month == 12) 
                    {
                        day=1;
                        month=1;
                        year++;
                        cout << "Last day in the year !\nHappy new year!!!\nTommorow : " << day <<" "<< month << " " << year;
                    }
                    else if ( (month == 1)||(month == 3)||(month == 5)||(month == 7)||(month == 8)||(month == 10) )
                        {
                            day=1;
                            month++;
                            cout << "Tommorow : " << day <<" "<< month << " " << year;
                        }
                        else cout << "\nTo much days in the month";
    }
    else cout << "\nError. Wrong format of date";
}