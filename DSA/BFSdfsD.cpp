#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void dfs(int s, vector<int> adjM[], bool *vis)
{
    cout << s << " ";
    vis[s] = true;
    for (int i = 0; i < adjM[s].size(); i++)
    {
        if (vis[adjM[s][i]] == false)
        {
            dfs(adjM[s][i], adjM, vis);
        }
    }
}

void bfs(int s, vector<int> adjM[], bool *vis)
{
    queue<int> q;
    q.push(s);
    vis[s] = true;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        cout << x << " ";
        for (int i = 0; i < adjM[x].size(); i++)
        {
            if (vis[adjM[x][i]] == false)
            {
                q.push(adjM[x][i]);
                vis[adjM[x][i]] = true;
            }
        }
    }
}

int main()
{
    int v, e;
    cin >> v >> e;
    vector<int> adjM[v];
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adjM[u].push_back(v);
        adjM[v].push_back(u);
    }
    bool *vis = new bool[v];
    for (int i = 0; i < v; i++)
    {
        vis[i] = false;
    }
    dfs(0, adjM, vis);
    cout << endl;
    for (int i = 0; i < v; i++)
    {
        vis[i] = false;
    }
    bfs(0, adjM, vis);
    return 0;
}