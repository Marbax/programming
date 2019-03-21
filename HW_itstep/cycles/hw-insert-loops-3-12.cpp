#include <iostream>
using namespace std;

int main()
{
    for (int i = 0; i < 8; i++)
    {
        for (int c = 0; c < 8; c++)
        {
            if (i >= c)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < 8; i++)
    {
        for (int c = 0; c < 8; c++)
        {
            if ( i + c <= 7) 
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < 8; i++)
    {
        for (int c = 0; c < 8; c++)
        {
            if (i <= c) 
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
    cout<<endl;
    for (int i = 0; i < 8; i++)
    {
        for (int c = 0; c < 8; c++)
        {
            if ( i + c >= 7) 
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
}
