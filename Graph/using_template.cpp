#include <bits/stdc++.h>
using namespace std;
template <typename T>

class graph
{
public:
    map<T, list<pair<T, int>>> adj;

    void add_edge(T f, T s, int dist, int bidirect = 1)
    {
        adj[f].push_back(make_pair(s, dist));
        if (bidirect)
        {
            adj[s].push_back(make_pair(f, dist));
        }
    }
    void print_adj()
    {
        for (auto a : adj)
        {
            cout << a.first << " ->";
            for (auto b : a.second)
            {
                cout << b.first << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    graph<int> g;
    int e;
    cin >> e;
    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        g.add_edge(f, s, 1, 1);
    }
    g.print_adj();
    return 0;
}