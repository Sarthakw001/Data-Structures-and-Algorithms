#include<iostream>
using namespace std;
#include "student1.cpp"

int main()
{
    char name[]="abcd";
    student s1(5,name);
    s1.display();

    student s2(s1);
    s2.name[0]='x';

    s1.display();
    s2.display();
    

}

