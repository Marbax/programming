#include <iostream>

using namespace std;

int Div(int a, int b) noexcept(false) //noexcept //throw() //( устаревший)  говорит что не может выкинуть ошибку , используется в конструкторах
// noexcept(false) // говорит что ф-я выкидывает исключение
{

    if (b == 0)
        throw invalid_argument("Division by zero");

    return a / b;

    // если не можно обработать внутри ф-и , то не нужно писать
    /* catch (const char *ex)
    {
        cerr << "Error in div func " << ex << endl;
        throw; // выкидывает исключение и ф-я откатывается назад ,как будто ее никто не вызывал
    }
    catch (...) //  ловит все исключения ( нужно писать последним !! )
    {
        cerr << "Some error in div func" << endl;
    } */
}

int main()
{
    int a = 22, b = 0;

    try
    {
        cout << Div(a, b) << endl;
    }
    /* catch (const char *ex)
    {
        cerr << "def Error : " << ex << endl;
    } */
    catch (const invalid_argument &ex) // конкретное исключение
    {
        cerr << "Error : " << ex.what() << endl;
    }
    catch (const exception &ex) // все исключения
    {
        cerr << "Error : " << ex.what() << endl;
    }

    string str = "Hello";
    cout << str[5] << endl;

    try
    {
        cout << str.at(5) << endl; // at  проверяет не выходит ли за пределы и кидает ошибку  , а так тоже самое что и квадратные скобки
    }
    catch (const out_of_range &ex)
    {
        cerr << ex.what() << endl;
    }
};