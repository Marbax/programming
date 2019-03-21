#include <iostream>
using namespace std;

int main()
{
    const int size = 10;
    int arr[size]{};
    int x;
    for (int i = 0; i < size; i++)
    {
        cout << " Enter number --> ";
        cin >> x;
        arr[i] = x;
        //cout << arr[i] << endl;
    }
    cout << "\n\nReversed massive : " << endl;
    for (int i = size - 1; i >= 0; i--)
    {
        arr[i];
        cout << arr[i] << " ";
    }
}
