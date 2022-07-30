#include <bits/stdc++.h>
using namespace std;
template <typename T>

class graph
{
public:
    map<int, bool> visited;
    map<T, list<int>> adj;

    void add_edge(T f, T s, int bidirect = 1)
    {
        adj[f].push_back(s);
        if (bidirect)
        {
            adj[s].push_back(f);
        }
    }
    void dfs_util(T v) // for connected graph only!!!!!!!!
    {
        visited[v] = true;
        cout << v << " ";
        list<int>::iterator it;
        for (it = adj[v].begin(); it != adj[v].end(); it++)
        {
            if (!visited[*it])
            {
                dfs_util(*it);
            }
        }
    }
    void dfs() // funtion for complete graph DFS Since it also include disconnected graph
    {
        for (auto i : adj)
        {
            if (!visited[i.first])
            {
                dfs_util(i.first);
            }
        }
    }
    void bfs_util(T v)
    {
        queue<T> q;
        q.push(v);
        visited[v] = true;
        while (!q.empty())
        {
            T front_ele = q.front();
            cout << front_ele << " ";
            q.pop();
            list<int>::iterator it;
            for (it = adj[v].begin(); it != adj[v].end(); it++)
            {
                if (!visited[*it])
                {
                    q.push(*it);
                    visited[*it] = true;
                }
            }
        }
    }
    void bfs()
    {
        for (auto i : adj)
        {
            if (!visited[i.first])
            {
                bfs_util(i.first);
            }
        }
    }

    bool has_path_bfs(T s, T e) // if graph has a path from s to e
    {
        queue<T> q;
        q.push(s);
        visited[s] = true;

        while (!q.empty())
        {
            T f = q.front();
            q.pop();
            for (auto i : adj[f])
            {
                if (i == e)
                {
                    return true;
                }
                if (!visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
        return false;
    }
    void has_path_dfs_util(T s)
    {
        visited[s] = true;
        for (auto i : adj[s])
        {
            if (!visited[i])
            {
                has_path_dfs_util(i);
            }
        }
    }
    bool has_path_dfs(T s, T e)
    {
        has_path_dfs_util(s);
        if (visited[e] == true)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
   
};