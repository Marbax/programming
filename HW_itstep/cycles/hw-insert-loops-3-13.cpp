#include <iostream>
using namespace std;

int main()
{

    for (int i = 0; i < 9; i++)
    {
        for (int c = 0; c < 5; c++)
        {
            if (i == 0 || i == 8 || c == 0 || i + c <= 4 || i >= c + 4)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
}
