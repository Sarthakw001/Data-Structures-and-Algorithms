#include <bits/stdc++.h>
using namespace std;

void printLCS(int n, int m, string s1, string s2)
{
    int t[n + 1][m + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                t[i][j] = 1 + t[i - 1][j - 1];
            }
            else
            {
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
    }
    string s = "";
    int i = n, j = m;
    while (i > 0 && j > 0)              // follow the path of dp table 
    {
        if (s1[i - 1] == s2[j - 1])
        {
            s.push_back(s1[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (t[i - 1][j] > t[i][j - 1])      // finding the which is greater 
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.length(); i++)
    {
        cout << s[i] << " ";
    }
}

int main()
{
    // main code
    string s1 ,s2;
    cin>>s1>>s2;
    int n = s1.length();
    int m = s2.length();
    printLCS(n,m,s1,s2);
    return 0;
}