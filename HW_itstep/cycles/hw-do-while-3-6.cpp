#include <iostream>
using namespace std;

int main()
{
    int x, i = 0, con = 7;
    cout << "Game \"Guess the number.\n\"The computer \"conceived\" a number from 1 to 10.\nGuess it in 5 tries." << endl;
    cout << "Type a number and press <Enter> : " << endl;
    do
    {
        cout << "--> ";
        cin >> x;
        i++;
        if (x == con)
        {
            cout << "\nGreetings.You WON! It was " << con << endl;
            break;
        }
        else if (i == 5)
        {
            cout << "\nLOOSE!" << endl;
        }
        else
        {
            cout << "NO." << endl;
        }

    } while (i != 5);
}