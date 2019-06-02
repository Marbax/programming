#include <iostream>

using namespace std;

class Point
{
  private:
    int x;
    int y;
    int val;

  public:
    Point(int _x, int _y) //кониструктор , при создани обьекта отрабатывает гарантированы
    {
        if (_x && _y > 0)
        {
            x = _x;
            y = _y;
        }
    }
    Point() //кониструктор , перегрузка
    {
        x = 0;
        y = 0;
    }
    void Init(int _x, int _y)
    {
        if (_x && _y > 0)
        {
            x = _x;
            y = _y;
        }
    }
    void SetX(int val)
    {
        if (val > 0)
            x = val;
    }
    int GetX()
    {
        return x;
    }
    void SetY(int val)
    {
        if (val > 0)
            y = val;
    }
    int GetY()
    {
        return y;
    }
    void Print_point()
    {
        cout << "x = " << x << "  y = " << y; // cout << "x = " << this->x << "  y = " << this->y; тоже самое  
    }
};

int main()
{
    Point a;
    Point b(111, 111);
    // Point b(); - нельзя так писать ,т.к. думает что это прототип какой-то ф-и
    a.SetX(234);
    a.SetY(2);
    a.Init(222, 3333);
    cout << a.GetX() << "  " << a.GetY();
    cout << endl;
    a.Print_point();
    cout << endl;
    b.Print_point();
}

// this->  ключевое слово для передачи адреса в памяти 