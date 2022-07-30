#include<iostream>
using namespace std;

int subs(string input,string output[])
{
    if(input.empty())
    {
        output[0]="";
        return 1;
    }
    int small = subs(input.substr(1),output);
    for(int i=0;i<=small;i++)
    {
        output[small+i]=input[0]+output[i];
    }
    return 2*small;
}

int main()
{
    string input = "abc";
    string output[1000] = {""};
    int count = subs(input,output);
    for(int i=0;i<count;i++)
    {
        cout<<output[i]<<endl;
    }
    return 0;
}