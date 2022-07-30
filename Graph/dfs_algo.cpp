#include<bits/stdc++.h>
#include"graph.h"
using namespace std;

int main()
{
    graph<int> g;
    int e;
    cin>>e;
    for(int i=1;i<=e;i++)
    {
        int f,s;
        cin>>f>>s;
        g.add_edge(f,s,1);
    }
    g.dfs();                     //for algorithm refer to header file "graph.h"
}
//O(V+E) v-> vertex e->edge -----   time complexity
//O(V) -------------- space complexity 