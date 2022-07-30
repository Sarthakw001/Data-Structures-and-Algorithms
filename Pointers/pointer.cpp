#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num = 5;

    cout << num << endl;

    // addrress of Operator "&"

    cout << &num << endl;

    int *ptr = &num; // initialising pointer to address of num

                    // ptr -> stores address of num

                    // pointer -> special variable to store the adress of normal variable

    cout << *ptr << endl;
                    
                     // "*" -> derefrence operator
                    
                    // "*" -> returns the value pointer is pointing to.
                    
    cout << ptr << endl;
    cout << endl;
    int **p = &ptr;
    cout << p << endl;
    cout << **p << endl;
    cout << ptr << endl;
    cout << *ptr << endl;

    return 0;
}