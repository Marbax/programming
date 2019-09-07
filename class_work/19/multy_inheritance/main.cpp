#include "StudentMedic.h"
using namespace std;


int main()
{
    StudentMedic obj("Petya", 20,"dantist",12432);
    cout<<obj.getName()<<" "<<obj.getSpec()<<endl;
    cout<<obj.getName()<<endl;

    StudentMedic a("Dantist",12432);
    cout<<a.getName()<<" "<<obj.getId()<<endl<<endl;
    cout<<a.getName()<<endl;

    Student stud("Student",25,777);
    cout<<stud.getName()<<" "<<stud.getAge()<<" "<<stud.getId()<<endl;
}

