#include <iostream>
using namespace std;

// НУЖНО БЫЛО НАХОДИТЬ ОБЩИЙ ЗНАМЕНАТЕЛЬ НЕ ПЕРЕМНОЖЕНИЕМ ИХ , А СРАЗУ НАХОЖДЕНИЯ НАИМЕНЬШЕГО

/* 
Cоздайте класс Fraction(обыкновенная дробь), содержащий следующие
методы:
- конструктор по умолчанию;
- конструктор с параметрами;
- сеттеры и геттеры;
- сокращение дроби;
- show();
И перегрузите следующие операторы:
- арифметиче ские: +, -, *, /;
- логиче ские: <, >, <=, >=, ==, !=.
 */

class Fraction
{
private:
    int numerator = 0;
    int denominator = 0;

public:
    Fraction() : numerator(0), denominator(0) {} // конструктор по умолчанию;

    Fraction(const int numerator, const int denominator) : numerator(numerator), denominator(denominator) {} // конструктор с параметрами;

    int getNumerator() const { return numerator; }

    int getDenominator() const { return denominator; }

    void setNumerator(const int numerator) { this->numerator = numerator; }

    void setDenominator(const int denominator) { this->denominator = denominator; }

    Fraction Fractions_reduction() // сокращение дроби; алгоритм Эвклида
    {
        int tmp_den = denominator, tmp_num = numerator, mod;
        while (tmp_num != 0 && tmp_den != 0)
        {
            if (tmp_num > tmp_den)
            {
                tmp_num = tmp_num % tmp_den;
            }
            else
            {
                tmp_den = tmp_den % tmp_num;
            }
        }
        int nod = (tmp_num + tmp_den);
        Fraction result;
        result.numerator = numerator / nod;
        result.denominator = denominator / nod;
        return result;
        /* 
        if (numerator != 0)
        {
            int tmp_den = denominator, tmp_num = numerator, mod;
            mod = tmp_den % tmp_num;
            while (mod != 0)
            {
                tmp_den = tmp_num;
                tmp_num = mod;
                mod = tmp_den % tmp_num;
            }
            int nod = tmp_num;
            if (nod != 1)
            {
                Fraction result;
                result.numerator = numerator / nod;
                result.denominator = denominator / nod;
                return result;
            }
        }
        */
    }

    void Show() { cout << numerator << "\\" << denominator << endl; }

    Fraction operator+(Fraction &obj)
    {
        Fraction result;
        result.numerator = numerator * obj.denominator + obj.numerator * denominator;
        result.denominator = denominator * obj.denominator;
        return result;
    }

    Fraction operator-(Fraction &obj)
    {
        Fraction result;
        result.numerator = numerator * obj.denominator - obj.numerator * denominator;
        result.denominator = denominator * obj.denominator;
        return result;
    }

    Fraction operator*(Fraction &obj)
    {
        Fraction result;
        result.numerator = numerator * obj.numerator;
        result.denominator = denominator * obj.denominator;
        return result;
    }

    Fraction operator/(Fraction &obj)
    {
        Fraction result;
        result.numerator = numerator * obj.denominator;
        result.denominator = denominator * obj.numerator;
        return result;
    }

    bool operator<(Fraction &obj)
    {
        /*         
        if (denominator == obj.denominator)
        {
            return numerator < obj.numerator;
        }
        if (numerator == obj.numerator)
        {
            return denominator > obj.denominator;
        }
        Fraction left;
        left.numerator = numerator * obj.denominator;
        left.denominator = denominator * obj.denominator;
        Fraction right;
        right.numerator = obj.numerator * denominator;
        right.denominator = denominator * obj.denominator;
        return left.numerator < right.numerator;
        */
        return numerator * obj.denominator < denominator * obj.numerator;
    }

    bool operator>(Fraction &obj)
    {
        return numerator * obj.denominator > denominator * obj.numerator;
    }

    bool operator<=(Fraction &obj)
    {
        return numerator * obj.denominator <= denominator * obj.numerator;
    }

    bool operator>=(Fraction &obj)
    {
        return numerator * obj.denominator >= denominator * obj.numerator;
    }

    bool operator==(Fraction &obj)
    {
        return numerator * obj.denominator == denominator * obj.numerator;
    }

    bool operator!=(Fraction &obj)
    {
        return !(*this == obj);
    }
};

int main()
{
    Fraction first(8, 9);
    Fraction second(5, 6);
    (first - second).Show();
    Fraction third(first - second);
    (third.Fractions_reduction()).Show();
    cout << endl;
    (first + second).Show();
    ((first + second).Fractions_reduction()).Show();
    cout << endl;
    (first * second).Show();
    ((first * second).Fractions_reduction()).Show();
    cout << endl;
    (first / second).Show();
    ((first / second).Fractions_reduction()).Show();

    cout << endl;

    if (first > second)
    {
        cout << first.getNumerator() << "\\" << first.getDenominator() << " > ";
        cout << second.getNumerator() << "\\" << second.getDenominator() << endl;
    }
    if (first < second)
    {
        cout << first.getNumerator() << "\\" << first.getDenominator() << " < ";
        cout << second.getNumerator() << "\\" << second.getDenominator() << endl;
    }
    if (first >= second)
    {
        cout << first.getNumerator() << "\\" << first.getDenominator() << " >= ";
        cout << second.getNumerator() << "\\" << second.getDenominator() << endl;
    }
    if (first <= second)
    {
        cout << first.getNumerator() << "\\" << first.getDenominator() << " <= ";
        cout << second.getNumerator() << "\\" << second.getDenominator() << endl;
    }
    if (first == second)
    {
        cout << first.getNumerator() << "\\" << first.getDenominator() << " == ";
        cout << second.getNumerator() << "\\" << second.getDenominator() << endl;
    }
    if (first != second)
    {
        cout << first.getNumerator() << "\\" << first.getDenominator() << " != ";
        cout << second.getNumerator() << "\\" << second.getDenominator() << endl;
    }
    cout << "\nEND_OF_PROGRAM" << endl;
}
