

#include <iostream>
#include "List.h"

using namespace std;




int main()
{
   List<int> l;
   l.pushBack(123);
   l.pushBack(34);
   l.pushBack(567);
   l.pushBack(84);
   l.pushBack(295);
   l.print();
   l.popBack();
   l.print();



}

