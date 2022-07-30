#include <bits/stdc++.h>
#include "graph.h"
using namespace std;

int main()
{
    graph<int> g;
    int E;
    cin >> E;
    for (int i = 1; i <= E; i++)
    {
        int f, s;
        cin >> f >> s;
        g.add_edge(f, s, 1);
    }
    int s, f;
    cin >> s >> f;
    bool ans =g.has_path_dfs(s,f);
    bool ans =g.has_path_bfs(s,f);

    return 0;                       // for algorithm refer to header file "graph.h"
}