#include <iostream>
using namespace std;

class student
{
public:
    int age;
    int rollNo;

    student()
    {
        cout << "contructor 1" << endl;
    }
    student(int a, int r)
    {
        age = a;
        rollNo = r;
        cout << "constructor 2" << endl;
    }

    void display()
    {
        cout << age << " " << rollNo << endl;
    }
    void set(int r, int a)
    {
        age = a;
        rollNo = r;
    }
};


int main()
{
    student s1;
    s1.set(1,2);

    s1.display();


    student * s2 = new student(3,4);
    s2 -> display();

    return 0;
}
