#include <bits/stdc++.h>
using namespace std;
// different approach expalined here "https://leetcode.com/problems/find-the-duplicate-number/solution/"
// approach 1-> while traversing the array search for each element if found then return the element --> brute force ;

int findDuplicate(vector<int> &nums)
{
    int i = 0;
    int n = nums.size();

    while (i < n)
    {
        int ele = nums[i];
        for (int k = i + 1; k <= n; k++)
        {
            if (nums[k] == ele)
            {
                return ele;
            }
        }
        i++;
    }
    return 0;
}

// approach 2 --> Optimised approach  --> using variation of floyd's hare and torotoise algorithm;

int findduplicate(vector<int> &nums)
{
        
}