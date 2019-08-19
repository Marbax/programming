/* 
1) Дана строка, в которой буква h встречается как минимум два раза. Разверните последовательность символов,
 заключенную между первым и последним появлением буквы h, в противоположном порядке. +
2) Дана строка. Удалите из этой строки все символы n. + 
3) Дана строка. Замените в этой строке все появления буквы h на букву H, кроме первого и последнего вхождения. +
4) Дана строка. Удалите из нее все символы, чьи индексы делятся на 3. +
5) Дана строка. Замените в этой строке все цифры 1 на слово one. +
 */
#include <iostream>
#include <string>

using namespace std;

string reverseMiddle(const string str, const char sep) // 1) 
{
    string new_str;
    int first = str.find_first_of(sep) + 1;
    int last = str.find_last_of(sep) - 1;
    new_str = str.substr(0, first);
    for (size_t i = last; i >= first; i--)
    {
        new_str += str[i];
    }
    new_str += str.substr(last + 1);

    return new_str;
}

string symbolDel(const string str, const char sym) // 2) 
{
    string new_str;
    for (size_t i = 0; i < str.size(); i++)
    {
        if (str[i] != sym)
        {
            new_str += str[i];
        }
    }

    return new_str;
}

string replaceMiddle(const string str, const char old_sym, const char new_sym) // 3) 
{
    string new_str;
    int first = str.find_first_of(old_sym) + 1;
    int last = str.find_last_of(old_sym) - 1;
    new_str = str.substr(0, first);
    for (size_t i = first; i < last; i++)
    {
        if (str[i] == old_sym)
        {
            new_str += new_sym;
        }
        else
            new_str += str[i];
    }

    new_str += str.substr(last + 1);

    return new_str;
}

string everyDel(const string str, const int index) // 4) 
{
    string new_str;
    for (size_t i = 0; i < str.size(); i++)
    {
        if (!(i % index == 0))
        {
            new_str += str[i];
        }
    }

    return new_str;
}

string replaceInt(const string str, const char old_int, const string word) // 5) 
{
    string new_str;
    for (size_t i = 0; i < str.size(); i++)
    {
        if (str[i] == old_int)
        {
            new_str += word;
        }
        else
            new_str += str[i];
    }

    return new_str;
}

int main()
{
    cout << reverseMiddle("hama haminisova heart under dhark", 'h') << endl;
    cout << endl;
    cout << symbolDel("Zulndjinn shnounld bne nrevenged", 'n') << endl;
    cout << endl;
    cout << replaceMiddle("Zulndjinn shnounld bne nrevenged", 'n', 'N') << endl;
    cout << endl;
    cout << everyDel("Zulndjinn shnounld bne nrevenged", 3) << endl;
    cout << endl;
    cout << replaceInt("Zulndjinn 11 shnounld 1bne1 nreven1ged", '1',"one") << endl;
}
