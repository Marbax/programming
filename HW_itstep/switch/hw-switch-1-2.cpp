#include<iostream>
using namespace std;
//january = 31 , feruary = 28 , march = 31 , april = 30 , may = 31 , june = 30 , july = 31 
    // august = 31 , september = 30 , october = 31 , november = 30 , december = 31
int main()
{
    int seas;
    cout << "Welcome\n\n Enter month's number : "<<endl;
    cin >> seas;
    switch(seas)
    {
    case 1:
    cout << "January = 31 days ";
    break;
    
    case 2:
    {
        char leap;
        cout << "Is it leap year? (y/n)\n";
        cin >> leap;
        switch(leap)
        {
            case 'y':
            case 'yes':
            cout << "February = 29 days";
            break;

            case 'n':
            case 'no':
            cout << " February = 28 days ";
            break;

            default:
            cout << "Wrong input ! " << leap;
            break;

        }
    }
    break;

    case 3:
    cout << "March = 31 days";
    break;

    case 4:
    cout << "April = 30 days";
    break;

    case 5:
    cout << "May = 31 days";
    break;

    case 6:
    cout << "June = 30 days ";
    break;

    case 7:
    cout << "July = 31 days ";
    break;

    case 8:
    cout << "August = 31 days ";
    break;

    case 9:
    cout << "September = 30 days";
    break;

    case 10:
    cout << "October = 31 days";
    break;

    case 11:
    cout << "November = 30 days";
    break;

    case 12:
    cout << "December = 31 days";
    break;

    default:
        cout << "\nWrong input : " << seas;
        break;

    }
}