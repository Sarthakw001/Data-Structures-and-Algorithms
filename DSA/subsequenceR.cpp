#include<iostream>
using namespace std;

void subs(string input,string output){
    if(input.empty())
    {
        cout<<output<<endl;
        return;
    }
    subs(input.substr(1),output);
    subs(input.substr(1),input[0]+output);
}

int main()
{
    string s="kahtras";
    string s1="";
    subs(s,s1);
    return 0;
}