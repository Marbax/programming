#include <iostream>
using namespace std;

int main()
{
    const int size = 10;
    int arr[size]{};
    int x, prod = 1, max, min, min_i = 0, zeros = 0, buf;
    for (int i = 0; i < size; i++)
    {
        cout << " Enter number --> ";
        cin >> x;
        arr[i] = x;
    }
    max=arr[0];
    min = arr[0];
    for (int i = 0; i < size; i++)
    {
        prod *= arr[i];
        (arr[i] > max) ? max = arr[i] : max = max;
        (arr[i] < min) ? min = arr[i], min_i = i : min_i = min_i;
        (arr[i] == 0) ? zeros++ : zeros = zeros;
    }
    cout << "\nProduct of numbers : " << prod << endl;
    cout << "\nBiggest number : " << max << endl;
    cout << "\nPosition of minimal number : " << min_i << endl;
    cout << "\nAmmount of zeros : " << zeros << endl;
}
