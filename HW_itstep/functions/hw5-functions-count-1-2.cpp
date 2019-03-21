#include <iostream>
using namespace std;
// 2. Написать функцию, которая возвращает количество цифр в целом числе,
// полученном в качестве аргумента.
int Counter(int num)
{
    int res = 0;
    for (int i = num; i > 0; i = i / 10)
    {
        res++;
    }
    return res;
}

int main()
{
    int num = 0, res = 0;
    cout << "Enter number ==> ";
    cin >> num;
    res = Counter(num);
    cout << "There are(is) " << res << " digits";
}
