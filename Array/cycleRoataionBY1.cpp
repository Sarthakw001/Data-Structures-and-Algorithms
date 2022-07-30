#include<bits/stdc++.h>
using namespace std;

//approach -> using 2 pointer

void rotate(int a[],int n)
{
    int i=0,j=n-1;
    while (i<j)
    {
        swap(a[i],a[j]);
        i++;
    }
}
