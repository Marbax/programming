#include <iostream>
#include <cstring>
 
using namespace std;
 
char strings[1000][100];
char fnd[100];
char replace[100];
 
int main()
{
    int n;
    cin >> n;
 
    for (int i = 0; i < n; i++)
    {
        cin >> strings[i];
    }
    cin >> fnd;
    cin >> replace;
 
    for (int i = 0; i < n; i++)
    {
        if (strcmp(strings[i], fnd) == 0)
        {
            strcpy(strings[i], replace);
        }
    }
 
    for (int i = 0; i < n; i++)
    {
        cout << strings[i] << ' ';
    }
    cout << endl;
    return 0;
}