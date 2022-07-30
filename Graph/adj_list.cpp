#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,e;
    cin>>n>>e;

    vector<int> adj[n];          // array of vectors
    for(int i=0;i<e;i++)
    {
        int f,s;
        cin>>f>>s;
        adj[f].push_back(s);
        adj[s].push_back(f);
    }

    for(int i=0;i<n;i++)
    {
        cout<<i<<" -> ";
        vector<int> :: iterator it;
        for(it= adj[i].begin();it!= adj[i].end();it++)
        {
            cout<<*it<<" ";
        }
        cout<<endl;
    }
    return 0;
}