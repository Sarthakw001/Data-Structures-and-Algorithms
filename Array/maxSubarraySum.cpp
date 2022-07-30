#include <bits/stdc++.h>
using namespace std;

// Approach 1 -> Kadane's Algorithm

//  kadane algo won't work if all the no. are negative so to handle that case we found the max of all negative number and return that

long long maxSubarraySum(int arr[], int n)
{
    int mx = *max_element(arr, arr + n);
    if (mx < 0)
    {
        return mx;
    }
    long long curr_sum = 0;
    long long max_sum = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        curr_sum += arr[i];
        max_sum = max(max_sum, curr_sum);
        if (curr_sum < 0)
        {
            curr_sum = 0;
        }
    }
    return max_sum;
}