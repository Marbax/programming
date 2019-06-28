#include <iostream>
//#include <string.h>
using namespace std;

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

    void Fractions_reduction() // сокращение дроби; алгоритм Эвклида
    {
        if (numerator != 0)
        {
            int tmp_den = denominator, tmp_num = numerator, mod = tmp_den % tmp_num;
            while (mod != 0)
            {
                tmp_den = tmp_num;
                tmp_num = mod;
                mod = tmp_den % tmp_num;
            }
            int nod = tmp_num;
            if (nod != 1)
            {
                numerator /= nod;
                denominator /= nod;
            }
        }
    }

    void Show() { cout << numerator << "\\" << denominator << endl; }

    Fraction operator+(Fraction &obj)
    {
        Fraction result;
        result.numerator = (denominator + numerator) * obj.denominator + (obj.denominator + obj.numerator) * denominator;
        result.denominator = denominator * obj.denominator;
        return result;
    }

    Fraction operator-(Fraction &obj) // НУЖНО ПРОВЕРИТЬ
    {
        Fraction result;
        result.numerator = (denominator + numerator) * obj.denominator - (obj.denominator + obj.numerator) * denominator;
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

    bool operator<(Fraction &obj) { return double(*this) < double(obj); }

    bool operator>(Fraction &obj) { return double(*this) > double(obj); }

    bool operator<=(Fraction &obj) { return double(*this) <= double(obj); }

    bool operator>=(Fraction &obj) { return double(*this) >= double(obj); }

    bool operator==(Fraction &obj)
    {
        return numerator * obj.denominator == denominator * obj.numerator;
    }

    bool
    operator!=(Fraction &obj)
    {
        return !(*this == obj);
    }
    operator double()
    {
        double result = (denominator + numerator) / denominator;
        return result;
    }
};

int main()
{
}
