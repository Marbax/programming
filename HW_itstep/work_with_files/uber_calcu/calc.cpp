#include "calc.h"

void Calc()
{
    float a, b, result;
    bool flag = true;

    while (flag)
    {
        result = 0;
        cout << "What you want to do :" << endl;
        cout << "\n\n";
        cout << "a) Sum result of two numbers;" << endl;
        cout << "b) Subtraction result  of two numbers;" << endl;
        cout << "c) Multiplication result  of two numbers;" << endl;
        cout << "d) Division result  of two numbers;\nEsc to exit" << endl;

        char key = getchar();
        cin.ignore();
        switch (key)
        {
        case 100: // d) деление
            system("clear");
            Input(a, b);
            while (b == 0)
            {
                cout << "Can't divide by zero!" << endl;
                Input(a, b);
            }
            result = Div(a, b);
            cout << "Result = " << result << endl;
            system("clear");
            break;
        case 99: // c) умножение.
            system("clear");
            Input(a, b);
            result = Mult(a, b);
            cout << "Result = " << result << endl;
            system("clear");
            break;
        case 98: // b) разница
            system("clear");
            Input(a, b);
            result = Sub(a, b);
            cout << "Result = " << result << endl;
            system("clear");
            break;
        case 97: // a) сумма;
            system("clear");
            Input(a, b);
            result = Sum(a, b);
            cout << "Result = " << result << endl;
            system("clear");
            break;
        case 27:
            system("clear");
            flag = false;
            cout << "\tGood bye." << endl;
            break;
        }
    }
}