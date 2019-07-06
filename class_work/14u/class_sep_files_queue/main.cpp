#include "queue.h"
#include <iostream>

using namespace std;

int main()
{
    Queue st(50);
    for (size_t i = 0; i < 360; i++)
    {
        if (!st.Is_Full())
            st.Push(i + 1);
    }
    while (!st.Is_Empty())
    {
        cout << st.Pop() << " ";
    }
    cout << endl;
}