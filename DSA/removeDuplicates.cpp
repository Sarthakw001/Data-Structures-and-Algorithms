#include<iostream>
using namespace std;
#include<string.h>
string remove(string s)
{
    if(s.empty())
    {
        return s;
    }
    string s1 = remove(s.substr(1));
    if(s[0] == s1[0])
    {
        return s1;
    }
    else{
        return s[0]+s1;
    }
}


int main()
{
    string s = "aaaaakkkktyyty";
    
    cout<<remove(s)<<endl;
}