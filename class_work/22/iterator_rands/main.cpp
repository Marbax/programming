#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <iterator>   // доп итераторы
#include <random>     // randoms
#include <functional> // сравнения
#include <set>

using namespace std;

int rand_10_20()
{
    return rand() % 10 + 10;
}

template <typename T1, typename T2>
void my_gen(T1 b, T1 e, T2 f) // то же что и ф-я generate
{
    for (auto i = b; i != e; i++)
    {
        *i = f();
    }
}

// функциональный обьект(функтор)
class NumbersRow
{
private:
    int n;

public:
    NumbersRow(int val = 1) : n(val) {}

    ~NumbersRow() {}

    int operator()() { return n++; }
};

int main()
{
    list<int> l(10);

    //------------------------------------__РАНДОМЫ_---------------------------------------
    srand(time(0));

    //mt19937 gen;       // генератор псевдо случайных чисел (обьект) ,алгоритм по которому раскидываются числа "Mercon Twister"
    //gen.seed(time(0)); // от чего генерить`

    //random_device rd;  // псевдо случайные числа (не из времени) но ОЧЕНЬ МЕДЛЕННО
    //mt19937 gen_r(rd); // лучший рандом

    //uniform_int_distribution<int> uid(10, 45);  // спец алгоритм для выбора диапазона целых чисел
    //uniform_real_distribution<float> urd(0, 5); // спец алгоритм для выбора диапазона дробных чисел

    //------------------------------------//------------------------------------//------------------------------------
    my_gen(l.begin(), l.end(), NumbersRow());

    ostream_iterator<int> osi(cout, " "); // создание обьекта итератор

    for (auto i = l.begin(); i != l.end(); i++) // list<int>::iterator
    {
        cout << *i << " ";
    }
    cout << endl
         << "list : ";

    copy(l.rbegin(), l.rend(), ostream_iterator<int>(cout, " ")); // перебирает и копирует в поток вывода
    cout << endl
         << "vector throught object : ";

    vector<int> v;
    copy(l.begin(), l.end(), back_inserter(v)); // back_inserter  итератор который пушит в конец контейнера ,если там есть ф-я пуш бек
    copy(v.rbegin(), v.rend(), osi);            // перебирает и копирует в поток вывода через обьект вывода
    cout << endl
         << " bad shuffle : ";

    random_shuffle(v.begin(), v.end()); // устаревший метод ,лучше не использовать
    copy(v.rbegin(), v.rend(), osi);    // перебирает и копирует в поток вывода через обьект вывода
    cout << endl
         << " NORM shuffle : ";

    shuffle(v.begin(), v.end(), random_device()); // норм
    copy(v.begin(), v.end(), osi);                // перебирает и копирует в поток вывода через обьект вывода
    cout << endl
         << " sort : ";

    //sort(v.begin(), v.end());           // универсальный (не сортирует список )
    //sort(v.begin(), v.end()), less<>(); // универсальный (не сортирует список ) ,тоже что и выше (дэфолт)
    sort(v.begin(), v.end()), greater<>(); // универсальный (не сортирует список )
    copy(v.begin(), v.end(), osi);         // перебирает и копирует в поток вывода через обьект вывода
    cout << endl
         << " sort by set : ";

    // сортировка сетом
    set<int> s;
    copy(v.begin(), v.end(), inserter(s, s.begin())); // inserter итератора вставки (куда,в какую позицию) (set'у все равно на позицию ,он всегда отсортирован)
    copy(s.begin(), s.end(), osi);                    // перебирает и копирует в поток вывода через обьект вывода
}