#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <iterator>
#include <random>
#include <set>
#include <functional>
#include <numeric>

using namespace std;

int main()
{
    /* random_device rd;
     mt19937 gen(rd());
     uniform_int_distribution<int> uid(10,45);
     uniform_real_distribution<double > urd(0,5);
     for (int i = 0; i < 10; ++i)
     {
         cout<<uid(gen)<<" ";
     }
     cout<<endl;
     for (int i = 0; i < 10; ++i)
     {
         cout<<urd(gen)<<" ";
     }
     cout<<endl;*/
    random_device rd;
    mt19937 gen(rd());
    list<int> l(10);
    int min = 1, max = 10;

    auto f = [&](int min, int max) -> function<int()>
    {
        return [&, min, max]() -> int
        {
            uniform_int_distribution<int> uid(min, max);
            return uid(gen);
        };
    };
    generate(l.begin(), l.end(), f(min, max));
    ostream_iterator<int> osi(cout, " ");
    cout << "list: ";
    copy(l.begin(), l.end(), osi);
    cout << endl;
    vector<int> v;
    generate_n(back_inserter(v), 10, f(min, max));
    cout << "vector: ";
    copy(v.begin(), v.end(), osi);
    cout << endl;
    vector<int> even_v;
    copy_if(v.begin(), v.end(), back_inserter(even_v),[](int val){
        return val%2==0;
    });
    cout << "even vector: ";
    copy(even_v.begin(), even_v.end(), osi);
    cout << endl;

    /*auto it = find(v.begin(), v.end(), 19);
    if (it != v.end())
    {
        cout << *it << " pos -> " << it - v.begin() << endl;
    }
    else
    {
        cout << "Error. There is no such element" << endl;
    }*/
    auto it = find_if(v.begin(), v.end(), [](int val) -> bool
    {
        return val % 2 == 0;
    });
    if (it != v.end())
    {
        cout << *it << " pos -> " << it - v.begin() << endl;
    }
    else
    {
        cout << "Error. There is no such element" << endl;
    }
    //int n = count(v.begin(), v.end(), 19);
    int n = count_if(v.begin(), v.end(), [](int val) -> bool
    {
        return val % 2 == 0;
    });
    cout << n << endl;
    int sum = accumulate(v.begin(), v.end(),0);
    cout<<"Sum = "<<sum<<endl;
    int prod = accumulate(v.begin(), v.end(),1,[](int a,int b)->int{
        return a*b;
    });
    cout<<"Product = "<<prod<<endl;
    transform(v.begin(), v.end(), v.begin(), [](int val) -> int
    {
        return val * 2;
    });
    cout << "vector: ";
    copy(v.begin(), v.end(), osi);
    cout << endl;
    vector<string> vs;
    transform(v.begin(), v.end(), back_inserter(vs), [](int val) -> string
    {
        return to_string(val) + "!";
    });
    cout << "vector: ";
    copy(vs.begin(), vs.end(), ostream_iterator<string>(cout, " "));
    cout << endl;

    /*copy(l.begin(), l.end(), osi);
    cout << endl;
    copy(l.rbegin(), l.rend(), osi);
    cout << endl;
    vector<int> v;
    copy(l.begin(), l.end(), back_inserter(v));
    copy(v.begin(), v.end(), osi);
    cout << endl;
    shuffle(v.begin(), v.end(), random_device());
    copy(v.begin(), v.end(), osi);
    cout << endl;
    sort(v.begin(), v.end(),compare);
     copy(v.begin(), v.end(), osi);
     cout << endl;
    set<int> s;
    copy(v.begin(), v.end(), inserter(s, s.begin()));
    copy(s.begin(), s.end(), osi);
    cout << endl;*/

}