#include <iostream>
#include <string.h>

using namespace std;

class Date
{
  private:
    static int n; // переменная класса,хранится в единственном экземпляре
    int day;
    char *month;
    int year;
    // mutable int day; разрешает менять константу - бред

  public:
    Date(int d, const char *m, int y) // конструктор отрабатывает первым
    {
        n++;
        cout << "Constr" << endl;
        day = d;
        /* month = new char[strlen(m) + 1];
        strcpy(month, m); */
        month = strdup(m); // то же что и выше (в вижуал студии с подчеркиванием)
        year = y;
    }
    Date()
    {
        n++;
        cout << "DEF Constr" << endl;
        day = 0;
        /* month = new char[strlen(m) + 1];
        strcpy(month, m); */
        month = strdup("None"); // то же что и выше (в вижуал студии с подчеркиванием)
        year = 0;
    }
    Date(const Date &obj) // конструктор копирования , обязательный при использовании динамической памяти
    {
        n++;
        cout << "CONSTR COPY" << endl;
        day = obj.day;
        month = strdup(obj.month);
        year = obj.year;
    }

    // Date(const Date&obj)=delete; запрещает использовать конструкторы копирования везде ( в классе тоже)

    ~Date() // деструктор , работает по принципу стека , уничтожает в обратном порядке
    {
        n--;
        cout << "boom" << endl;
        delete[] month;
    }
    void setDay(int d)
    {
        day = d;
    }
    int getDay()
    {
        return day;
    }
    void setYear(int y)
    {
        day = y;
    }
    int getYear()
    {
        return year;
    }
    void setMonth(const char *m)
    {
        delete[] month;
        month = strdup(m);
    }
    const char *getMonth()
    {
        return month;
    }
    void print_date()
    {
        cout << day << "." << month << "." << year << endl;
    }
    void print_date() const // константный метод - гарантирует что поля не будут меняться
    {
        cout << day << "." << month << "." << year << endl;
    }
    static int getN() // статический метод
    {
        return n;
    }
};
int Date::n = 0;

int main()
{
    cout << Date::getN() << endl; // вызов статического метода
    Date a(1, "June", 2019);
    Date b;
    Date *c = new Date(2, "ss", 222); // указатель
    Date g = a;                       // для того чтобы скопировать - нужно вызвать конструктор копирования , дэфолтный конструктор копирования может копировать только то ,что в стеке
    // новая память не выделяется для динамического массива чаров ( в данном случае)

    //================================
    const Date f(12, "May", 1995);
    f.print_date(); //нельзя так делать
    //=================================
    a.print_date();
    b.print_date();
    c->print_date();
    g.print_date();
    cout << endl;
    cout << a.getN() << endl;
    cout << endl;
}
