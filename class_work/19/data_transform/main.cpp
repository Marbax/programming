#include <iostream>
using namespace std;

int main()
{
    int a = 34;
    int *ipa = &a;
    void *vpa = static_cast<void *>(ipa);
    short *spa = static_cast<short *>(vpa);
    cout << *spa << endl;

    //new int[5];
    //void*malloc(sizeof(int)*5); // тоже самое 

    // new в отличии  malloc  вызывает конструкторы 
    
    // delete pt;
    // free(pt);
    
}