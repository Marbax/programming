#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    float num1, num2;
    cout << "Welcome\n\n Input two values : ";
    cin >> num1 >> num2;
    if (num2!=0)
    {
        cout << "\nChoose an operation with numbers \n1.Multiplication\n2.Addition\n3.Subtraction\n";
        cout << "4.Division\n5.Exponentiation\n6.Finding the average\n7.Finding the highest number\n";
        int op;
        cout << "Your input : ";
        cin >>op;
        cout << endl;
        switch(op)
        {
        case 1:
        cout << num1*num2;
        break;
    
        case 2:
        cout << num1+num2;
        break;

        case 3:
        cout << num1-num2;
        break;

        case 4:
        cout << num1/num2;
        break;

        case 5:
        cout << pow(num1,num2);
        break;

        case 6:
        cout << (num1+num2)/2;
        break;

        case 7:
        (num1>num2)?cout<<num1:cout<<num2;
        break;

        default:
        cout << "\nWrong input : " << op;
        break;
    }

    }
    else cout << "Error! second number cant be zero!";
}