#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,e;
    cin>>n>>e;
    int** edge = new int*[n];
    for(int i=0;i<n;i++)
    {
        edge[i] = new int[n];
        for(int j=0;j<n;j++)
        {
            edge[i][j] = 0;
        }
    }
    for(int i=0;i<e;i++)
    {
        int f,s;
        cin>>f>>s;
        edge[f][s] = 1;
        edge[s][f] = 1;
    }
    return 0;
}
