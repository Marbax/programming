#include <iostream>
using namespace std;

int main()
{
    const int size = 5;
    int arr[size]{};
    int x;
    for (int i = 0; i < size; i++)
    {
        cout << " Enter number --> ";
        cin >> x;
        arr[i] = x;
    }
    cout << "\nPositive numbers :" << endl;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] >= 0)
        {
            cout << arr[i] << " ";
        }
    }
    cout << "\nNegative numbers :" << endl;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            cout << arr[i] << " ";
        }
    }
}
