#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    srand(time(0));
    const int size = 10;
    int max = 10, min = -9;
    int arr[size]{};
    int x, buf = 0, count = 0, num = 0;
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % (max - min) + min;
        cout << arr[i] << " ";
    }
    for (int i = 0; i < size; i++)
    {
        buf = 0;
        for (int j = 0; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                buf++;
            }
        }
        if (buf > count)
        {
            count = buf;
            num = arr[i];
        }
    }

    cout << "\n\nMost common nummber is  : " << num << " its repeats " << count << " times." << endl;
}
