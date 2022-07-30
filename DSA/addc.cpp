#include<iostream>
using namespace std;
#include "complex.cpp"

int main()
{
    complex c1(1,-2);
    complex c2(1,1);

    // c1.add(c2);

    // c1.display();
    // c2.display();

    c1.multiply(c2);
    c1.display();
}