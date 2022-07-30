#include <bits/stdc++.h>
using namespace std;

//approach 1;

void segregateElements(int arr[], int n)
{
    queue<int> v;
    queue<int> v1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
        {
            v.push(arr[i]);
        }
        else
        {
            v1.push(arr[i]);
        }
    }
    vector<int> v3;
    while (!v.empty())
    {
        v3.push_back(v.front());
        v.pop();
    }
    while (!v1.empty())
    {
        v3.push_back(v1.front());
        v1.pop();
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = v3[i];
    }
}

//approach 2;

void segregateElements(int arr[], int n)
{
    vector<int> v;
    vector<int> v1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
        {
            v.push_back(arr[i]);
        }
        else
        {
            v1.push_back(arr[i]);
        }
    }
    int i=0,j=0;
    for(int k=0;k<n;k++)
    {
        if(k<v.size())
        {
            arr[k]=v[i++];
        }
        else
        {
            arr[k] = v1[j++];
        }
    }
}