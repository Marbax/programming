#include <iostream>
using namespace std;

class Outer
{
public:
    class Inner
    {
        static int id;
        int data;
    public:
        Inner(int);

        int getData() const;

        void setData(int data);
    };

private:
    Inner obj;
public:
    Outer(int);

    int getObj() const;

    void setObj(int);
};
int Outer::Inner::id = 0;
Outer::Outer(int val):obj(val)
{

}

int Outer::getObj() const
{
    return obj.getData();
}

void Outer::setObj(int val)
{
    this->obj.setData(val);
}

int Outer::Inner::getData() const
{
    return data;
}

void Outer::Inner::setData(int data)
{
    this->data = data;
}

Outer::Inner::Inner(int d)
{
    data = d;
}

int main()
{
   Outer::Inner a(12);
   a.setData(345);
   cout<<a.getData()<<endl;
   Outer b(234);
   b.setObj(9789);
   cout<<b.getObj()<<endl;

}