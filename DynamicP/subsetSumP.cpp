#include <bits/stdc++.h>
using namespace std;

int equalPartition(int N, int arr[]) // top-down dp approach
{
    // code here    
    int sum = 0;                      // knapsack variation as here we have only 1 array and sum is like our kanpsack
    for (int i = 0; i < N; i++)        // and we have to choose either not to include in our knapsack or not;
    {
        sum = sum + arr[i];
    }
    if (sum % 2 != 0)
    {
        return false;
    }
    sum = sum / 2;
    bool t[N + 1][sum + 1];
    for (int i = 0; i < N + 1; i++)
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
    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                t[i][j] = (t[i - 1][j - arr[i - 1]] || t[i - 1][j]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[N][sum];
}
int main()
{
    // main 
}