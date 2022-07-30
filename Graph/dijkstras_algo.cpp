#include <bits/stdc++.h>
using namespace std;

int findMinVertex(bool *visited, int *distance, int n)
{
    int minVertex = -1;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && (minVertex == -1 || distance[i] < distance[minVertex]))
        {
            minVertex = i;
        }
    }
    return minVertex;
}

void dijkstras(int **edge, int n)
{
    bool *visited = new bool[n];
    int *distance = new int[n];

    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
        distance[i] = INT_MAX;
    }

    distance[0] = 0;

    for (int i = 0; i < n; i++)
    {
        int minVertex = findMinVertex(visited, distance, n);
        visited[minVertex] = true;
        for (int j = 0; j < n; j++)
        {
            if (edge[minVertex][j] != 0 && !visited[j])
            {
                int dist = distance[minVertex] + edge[minVertex][j];
                if (dist < distance[j])
                {
                    distance[j] = dist;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << i << " " << distance[i] << endl;
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
    dijkstras(edge, n);
    return 0;
}