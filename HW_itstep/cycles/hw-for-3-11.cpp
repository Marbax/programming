#include <iostream>
using namespace std;

int main()
{
    int res = 0, max = 0, id, nom, num;
    cout << "Enter five numbers : " << endl;
    for (int i = 0; i < 5; i++) //пять вводов
    {
        cout << "--> ";
        cin >> num;
        id = num;                            //сохранение цифры
        for (int i = num; i > 0; i = i / 10) //цикл на отбрасывание десятка,пока число есть
        {
            res += num % 10; //отрезает последний десяток и плюсует
            num /= 10;       //удаляет десяток
        }
        if (res > max) //если сумма чисел новой цифры больше - сохранить сумму и цифру
        {
            max = res;
            nom = id;
        }
        res = 0; //обнуляет считалкук суммы
    }

    cout << "Numbers is -> " << nom << ".  Sum of ciphers are -> " << max << endl;
}
