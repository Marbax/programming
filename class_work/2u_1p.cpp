#include<iostream>
using namespace std;

int main()
{
    int prog;
    cout << "Welcome\n\n Chose program : \n1: Whats the day today."<<endl;
    cout << "2: ternarn.\n\n Your input is : "; //условие?действие1:действие2;
    cin >> prog;
    switch(prog)//int , short , log , char
    {
    case 1: //number of a day
        //enum days {Monday = 1 , Tuesday = 2 , Wednsday = 3 , Thursday = 4 , Friday = 5, Saturday = 6 , Sunday = 7};
        int num;
        cout << "\n\nEnter the number of a day: " ;
        cin >> num;
        switch(num)
            {
            case 1:
                cout << "Monday"<< endl;
                break;

            case 2:
                cout << "Tuesday"<< endl;
                break;

            case 3:
                cout << "Wednsday"<< endl;
                break;

            case 4:
                cout << "Thursday"<<endl;
                break;

            case 5:
                cout << "Friday"<<endl;
                break;

            case 6:
                cout << "Saturday"<<endl;
                break;

            case 7:
                cout << "Sunday"<<endl;
                break;

        default:
            cout << "zero or not int 1-7 diapazon"<<endl;
            break;            
        }
        break;
    case 2: //ternarn alternative if-else
        {   //условие?действие1:действие2;
            int a,b;
            int max;
            cout << "Input 'a' and 'b' : "<<endl;
            cin >>a>>b;
            (a>b) ? cout << "'a' bigger" : (a < b) ? cout << "'b' bigger" << endl : cout << "a == b";
            /////////////////////////////////////////////////////////////////
            //max = a > b ? a : b;
            //cout << "\n"<< max;
            //////////////////////////////////////////////////////////////////
            //cout << (true ? a : b) << endl;//hz chto eto
            //////////////////////////////////////////////////////////////////
            //a < b ? (a = 10 , b = 20) : (a = 100 , b = 999);
            
        }
    break;
    case 3: //bigger of 3 digits
        {   //
            int a , b, c , max;
            cout << "Input 'a' 'b' 'c' "<<endl;
            cin >> a>>b>>c;
            /*if (a > b && a > c ) max = a; 
                else if (b > c ) max = b;
                    else  max = c;
            cout <<"Maximum number is : "<< max ; */
            max = a ;
            if (max < b )max = b;
            if (max < c )max = c;
            cout <<"Maximum number is : "<< max ;

        }
    break;
    default:
        cout << "\nNo program with that id : " << prog;
        break;

    }
}