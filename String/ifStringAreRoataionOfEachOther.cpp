#include <bits/stdc++.h>
using namespace std;

// Approach 1-->
//  1.concatenate str1 to itself and find whether str 2 is part of str1;
//  T.C -> O(n*n) -> n is length of string
//  S.c -> O(n)

bool areRotations(string str1, string str2)
{

    if (str1.length() != str2.length())
        return false;

    string temp = str1 + str1;
    return (temp.find(str2) != string::npos);
}

//Approach 2 --> 
// If the size of both the strings is not equal, then it can never be possible.
// Push the original string into a queue q1.
// Push the string to be checked inside another queue q2.
// Keep popping q2‘s and pushing it back into it till the number of such operations are less than the size of the string.
// If q2 becomes equal to q1 at any point during these operations, it is possible. Else not.

bool areRotations1(string str1, string str2)
{

    int m=str2.length();
    int n=str1.length();
    if(n!=m)
    {
        return false;
    }
    queue<char> q1;
    queue<char> q2;

    for(int i=0;i<n;i++)
    {
        q1.push(str1[i]);
        q2.push(str2[i]);
    }
    
    while(m--)
    {
        char ch = q2.front();
        q2.pop();
        q2.push(ch);

        if(q1==q2)
        {
            return true;
        }
    }
    return false;
}