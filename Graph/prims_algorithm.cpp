#include <bits/stdc++.h>
using namespace std;

int findMinVertex(bool *visited, int *weight, int n)
{
    int minVertex = -1;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && (minVertex == -1 || weight[i] < weight[minVertex]))
        {
            minVertex = i;
        }
    }
    return minVertex;
}

void prims(int **edge, int n)
{
    bool *visited = new bool[n];
    int *parent = new int[n];
    int *weight = new int[n];

    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
        weight[i] = INT_MAX;
    }
    parent[0] = -1;
    weight[0] = 0;

    for (int i = 0; i < n; i++)
    {
        int minVertex = findMinVertex(visited, weight, n);
        visited[minVertex] = true;

        for (int j = 0; j < n; j++)
        {
            if (edge[minVertex][j] != 0 && !visited[j])
            {
                if (edge[minVertex][j] < weight[j])
                {
                    weight[j] = edge[minVertex][j];
                    parent[j] = minVertex;
                }
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        cout << i << " " << parent[i] << endl;
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    int **edge = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edge[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edge[i][j] = 0;
        }
    }
    for (int i = 0; i < e; i++)
    {
        int f, s, w;
        cin >> f >> s >> w;
        edge[f][s] = w;
        edge[s][f] = w;
    }
    prims(edge, n);
    return 0;
}