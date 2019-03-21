#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    srand(time(0));
    const int size = 10;
    int max = 10, min = 1;
    int arr[size]{}, brr[size]{};
    int x;
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % (max - min) + min;
        cout << arr[i] << " ";
    }
    cout << "\nEnter step for pushing --> ";
    cin >> x;
    for (int i = 0; x >= size; i++)
    {
        (x >= size) ? x -= size : x = x;
    }
    for (int i = x; i < size; i++)
    {
        brr[i - x] = arr[i];
    }
    for (int i = size - x, j = 0; i < size; i++, j++)
    {
        brr[i] = arr[j];
    }
    cout << "\nModified massive : " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << brr[i] << " ";
    }
}
