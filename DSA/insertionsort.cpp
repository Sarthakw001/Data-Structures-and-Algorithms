#include<iostream>
using namespace std;

void insertion(int a[],int size)
{   
    int key=0;
    int j=0;
    for(int i=1;i<size;i++)
    {
        key=a[i];
        j=i-1;
        while(j>=0 && a[j]>key)
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=key;
    }
}

int main()
{
    int a[5]={5,4,3,2,1};
    insertion(a,5);
    for(int i=0;i<5;i++)
    {
        cout<<a[i]<<",";
    }
}