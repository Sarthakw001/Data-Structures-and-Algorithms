#include <bits/stdc++.h>
using namespace std;

int knapSack(int W, int wt[], int val[], int n) // top-down approach
{
    int t[n + 1][W + 1];
    for (int i = 0; i < n + 1; i++) // initialise using recursive base condition
    {
        for (int j = 0; j < W + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
        }
    }
    for (int i = 1; i < n + 1; i++) // fill the matrix using recursive approach and using choice diagram
    {
        for (int j = 1; j < W + 1; j++)
        {
            if (wt[i - 1] <= j)
            {
                t[i][j] = max(val[i - 1] + t[i][j - wt[i - 1]], t[i - 1][j]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][W];
}
int knapSackUtil(int w, int wt[], int val[], int n, int **t) // recursive approach
{
    if (n < 0) // base condition
    {
        return 0;
    }
    if (t[n][w] != -1) // memoization
    {
        return t[n][w];
    }
    if (wt[n] <= w)
    {
        t[n][w] = max(val[n] + knapSackUtil(w - wt[n], wt, val, n, t), knapSackUtil(w, wt, val, n - 1, t));
        return t[n][w];
    }
    else if (wt[n] > w)
    {
        t[n][w] = knapSackUtil(w, wt, val, n - 1, t);
        return t[n][w];
    }
}
int knapSack(int W, int wt[], int val[], int n)
{
    // Your code here
    int **t = new int *[n];
    for (int i = 0; i < n; i++)
    {
        t[i] = new int[W + 1];
        for (int j = 0; j < W + 1; j++)
        {
            t[i][j] = -1;
        }
    }

    int max = knapSackUtil(W, wt, val, n - 1, t);
    return max;
}
int main()
{
    // main code
}