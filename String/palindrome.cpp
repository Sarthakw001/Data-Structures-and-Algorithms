#include <bits/stdc++.h>
using namespace std;


// Approach -> Just checking whether last character is same as first character

int isPalindrome(string S)
{
    int n = S.length();
    int i = 0, j = n - 1;

    while (i < j)
    {
        if (S[i] != S[j])
        {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

// T.C -> O(N);
// S.C -> O(1);