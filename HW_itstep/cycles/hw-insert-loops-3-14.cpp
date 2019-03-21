#include <iostream>
using namespace std;

int main()
{

    for (int i = 0; i < 8; i++)
    {
        for (int c = 0; c < 8; c++)
        {
            if ((i + c) % 4 == 0 || (i + c) % 2 == 0 || (i + c) % 6 == 0)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
}
