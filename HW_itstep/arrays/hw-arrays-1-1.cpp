#include <iostream>
using namespace std;

int main()
{
    const int size = 20;
    int arr[size]{};
    for (int i = 0; i < size / 2; i++)
    {
        cout << i<<" --> ";
        arr[i] = i * 2 + 1;
        cout << arr[i] << endl;
    }
}
