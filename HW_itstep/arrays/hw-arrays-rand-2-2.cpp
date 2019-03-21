#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    srand(time(0)); 
    const int size = 10, suze = size - 1;
    int max = 10, min = 0;
    int arr[size]{};
    int brr[suze];
    int x;
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % (max - min) + min; 
        cout << arr[i] << " ";
    }
    cout << "\nEnter index of element whcih you would like to delete : ";
    cin >> x;
    for (int i = 0; i < suze; i++)
    {
        if (i >= x)
        {
            brr[i] = arr[i + 1];
        }
        else
            brr[i] = arr[i];
    }

    cout << "\n\nModified massive : " << endl;
    for (int i = 0; i < suze; i++)
    {
        cout << brr[i] << " ";
    }
}
