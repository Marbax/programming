#include <iostream>
#include <memory>

using namespace std;

int main()
{
    /* auto_ptr<int> ap1(new int(333));
    cout << *ap1 << endl;

    auto_ptr<int> ap2 = ap1; // внутри снимается константность
    cout << *ap2 << endl;
    cout << *ap1 << endl; */

    unique_ptr<int> pt1(new int(111));
    cout << *pt1 << endl;
    cout << "sizeof " << sizeof(unique_ptr<int>) << endl;

    //unique_ptr<int> pt2 = pt1; //копирование запрещено
    unique_ptr<int> pt2 = move(pt1); //перемещает
    cout << *pt2 << endl;

    /* //unique_ptr<int *> arr(new int[131]); // нет перегруженого `[]`
    unique_ptr<int[]> arr(new int[5]); // сам почистит память 
    for (size_t i = 0; i < 5; i++)
    {
        arr[i] = rand() % 20;
        cout << arr[i] << " ";
    }
    cout << endl; */

    shared_ptr<int> sp1(new int(2312));
    cout << *sp1 << endl;
    shared_ptr<int> sp2 = sp1; // увеличивает счетчик ,два указателя в одно место
    cout << *sp1 << " " << *sp2 << " " << sp1.use_count() << endl;
    sp1.reset(); // обновляет указатель ,как в nullptr , отдельно nullptr использовать нельзя
    //cout << *sp1 << endl; //  его нет
    cout << "sizeof " << sizeof(shared_ptr<int>) << endl
         << endl;

    //shared_ptr<int[]> arr(new int[5]);
    //arr[0] = 3;

    weak_ptr<int> wp = sp2;
    cout << sp2.use_count() << endl;
    cout << wp.lock().use_count() << endl;
    cout << sp2.use_count() << endl;
    //*(wp.lock());

    int a = 6;
    unique_ptr<int> up(&a); // нельзя указывать на что либо в стеке , т.к. попытается удалить ту память и вылетит программа
}