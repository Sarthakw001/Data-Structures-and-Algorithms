#include <bits/stdc++.h>
using namespace std;

// Approach 1-> using 2 pointer approach i.e just swapping the first and last characters


void reverseString(vector<char> &s)
{
    int i=0,j=s.size()-1;
    while(i<j)
    {
        swap(s[i],s[j]);
        i++;
        j--;
    }
}

// T.C -> O(N);
// S.C -> O(1);

int main()
{
    vector<char> s = {'e','v','e','n'};
    reverseString(s);
    for(int i=0;i<4;i++)
    {
        cout<<s[i]<<" ";
    }
    return 0;
}