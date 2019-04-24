#include <iostream>
#include <locale>
#include <string>

using namespace std;

int main()
{

    string text="plan kuril plan tupil";
    string x = "plan";  // slovo pod zamenu
    string y = "bleep"; // slovo zmenitel

    //cin >> text;

    size_t pos;
    while (pos = text.find(x) != std::string::npos)
    {
        text.erase(pos, x.size());
        text.insert(pos, y);
    }
    cout << text << endl;

    system("PAUSE");
    return EXIT_SUCCESS;
}