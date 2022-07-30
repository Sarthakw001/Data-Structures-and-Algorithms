#include <iostream>
using namespace std;
#include "dynamicArray.cpp"

int main()
{
    int m;
    cin>>m;
    array a1;
    for(int i=0;i<m;i++)
    {
        int n;
        cin>>n;
        a1.addElement(n);
    }

    a1.displayElement();

    
}