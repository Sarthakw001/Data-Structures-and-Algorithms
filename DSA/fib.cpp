#include<iostream>
using namespace std;

int fibonaacci(int n)
{
    if(n==0)
    return 0;
    if(n==1)
    return 1;

    return fibonaacci(n-1)+fibonaacci(n-2);
}

int main(){
    int n;
    cin>>n;
    cout<<fibonaacci(n);
}