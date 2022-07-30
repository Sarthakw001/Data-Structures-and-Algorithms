#include <bits/stdc++.h>
using namespace std;

// union

// approach 1 -> using Set;
// approach 2 -> USing Hash Map

// Intersection

// approach 1 -> making unordered map of larger array and finding the elements of smaller array in map 
// if found then add to our set DS to avoid repetition of numbers

vector<int> intersection(int a[], int n, int b[], int m)
{
    unordered_map<int, int> mp;

    int p = n > m ? n : m;

    if (p == n)
    {
        for (int i = 0; i < p; i++)
        {
            mp.insert({a[i], 1});
        }
    }
    else
    {
        for (int i = 0; i < p; i++)
        {
            mp.insert({b[i], 1});
        }
    }
    set<int> ans;

    if (p == n)
    {
        for (int i = 0; i < m; i++)
        {
            if (mp.find(b[i]) != mp.end())
            {
                ans.insert(b[i]);
            }
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (mp.find(a[i]) != mp.end())
            {
                ans.insert(a[i]);
            }
        }
    }
    vector<int> v;
    set<int> ::iterator it;
    for(it=ans.begin();it!=ans.end();it++)
    {
        v.push_back(*it);
    }
    return v;
}
