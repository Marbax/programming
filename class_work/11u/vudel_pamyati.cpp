#include <iostream>

using namespace std;

struct Date
{
    unsigned int day:5; //ограничивает пятью 
    unsigned int month:4;
    unsigned int year:11;
};

struct Date2
{
    unsigned int day;
    unsigned int month;
    unsigned int year;
};

int main()
{

    cout<<sizeof(Date)<<endl;
    cout<<sizeof(Date2)<<endl;
}