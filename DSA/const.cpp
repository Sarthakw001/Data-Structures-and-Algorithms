#include <iostream>
using namespace std;

class student
{
public:
    int age;
    const int rollNo;

    student(int age, int rollNo) : age(age), rollNo(rollNo)
    {
    }

    int getRollNo() const
    {
        return rollNo;
    }
    int getAge()
    {
        return age;
    }
};

int main()
{
    student s(5, 5);
    cout << s.getAge() << endl;
    cout << s.getRollNo() << endl;
}

