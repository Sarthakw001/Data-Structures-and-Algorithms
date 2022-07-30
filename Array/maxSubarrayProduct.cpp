#include <bits/stdc++.h>
using namespace std;

// approach 1 -> Using 2 traversal technique which is indirect way of applying kadane's algo i.e we traverse from left to right first and then from right to left to find out max of both traversal subarray sum; only case we have to handle is when product become zero i.e we again initialise our sproduct to zero;

long long maxProduct(vector<int> arr, int n)
{
    long long curr_pro = 1;
    long long max_pro = INT_MIN;

    for(int i=0;i<n;i++)
    {
        curr_pro*= arr[i];
        max_pro = max(curr_pro,max_pro);
        if(curr_pro==0)
        {
            curr_pro=1;
        }
    }
    curr_pro=1;
    for(int i=n-1;i>=0;i--)
    {
        curr_pro*= arr[i];
        max_pro = max(curr_pro,max_pro);
        if(curr_pro==0)
        {
            curr_pro=1;
        }
    }
    return max_pro;
}


// approach 2 -> maintain the minVal pro & maxVal pro during the traversal form left to right if negative number is found then swap the minVal and maxVal and update the max_product_so_far with maxVal pro;

int max_pro(vector<int> arr, int n)
{
    int maxV = arr[0];
    int minV = arr[0];

    int max_pro = INT_MIN;

    for(int i=0;i<n;i++)
    {
        if(arr[i]<0)
        {
            swap(minV,maxV);
        }

        maxV = max(arr[i],maxV*arr[i]);
        minV = min(arr[i],minV*arr[i]);

        max_pro = max(max_pro,maxV);
    }
    return max_pro;
}