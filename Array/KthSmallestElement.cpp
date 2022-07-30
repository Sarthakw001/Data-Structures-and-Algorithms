#include <bits/stdc++.h>
using namespace std;

//approach 1;
int solve(int arr[],int n,int k)       
{
    priority_queue<int>pq;              // using max heap;
    for(int i=0;i<n;i++)
    {
        if(pq.size()<k)
        {
            pq.push(arr[i]);
        }
        else
        {
            if(arr[i]<pq.top())
            {
                pq.pop();
                pq.push(arr[i]);
            }
        }
    }
    return pq.top();
}

//approach 2;
