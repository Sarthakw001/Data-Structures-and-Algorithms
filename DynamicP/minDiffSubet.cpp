#include <bits/stdc++.h>
using namespace std;

vector<int> subset(int arr[], int n, int sum)  // returning vector that conatains all the subset of sum till (sum+1)/2;
{
    bool t[n + 1][sum + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
            {
                t[i][j] = false;
            }
            if (j == 0)
            {
                t[i][j] = true;
            }
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    vector<int> ans;
    for (int j = 0; j <= (sum + 1) / 2; j++)
    {
        if (t[n][j])
        {
            ans.push_back(j);
        }
    }
    return ans;
}
int minDifference(int arr[], int n) // s1 - s2 = diff ;   s1+s2 = arrSum ;  solving we get arrSum - 2s1 = diff
{
    // Your code goes here
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    vector<int> s1 = subset(arr, n, sum);
    int minD = INT_MAX;
    for (int i = 0; i < s1.size(); i++)
    {
        minD = min(minD, sum - (2 * s1[i]));
    }
    return abs(minD);
}
int main()
{
    //main code
}