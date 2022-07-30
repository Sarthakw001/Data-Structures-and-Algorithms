#include <bits/stdc++.h>
using namespace std;

class edge
{
public:
    int source;
    int desti;
    int weight;
};

bool comapareWeight(edge w1, edge w2)
{
    return (w1.weight < w2.weight);
}

int findParent(int v, int *parent)
{
    if (parent[v] == v)
    {
        return parent[v];
    }
    return findParent(parent[v], parent);
}

void kruskal_algo(edge *input, int n, int e)
{
    sort(input, input + e, comapareWeight);
    edge *output = new edge[n - 1];

    int *parent = new int[n];
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    int count = 0;
    int i = 0;
    while (count != n - 1)
    {
        edge currentEdge = input[i];

        int sourceParent = findParent(currentEdge.source, parent);
        int destParent = findParent(currentEdge.desti, parent);

        if (sourceParent != destParent)
        {
            output[count] = currentEdge;
            parent[sourceParent] = destParent;
            count++;
        }
        i++;
    }
    for (int j = 0; j < n - 1; j++)
    {
        if (output[j].source < output[j].desti)
        {
            cout << output[j].source << " " << output[j].desti << " " << output[j].weight << endl;
        }
        else
        {
            cout << output[j].desti << " " << output[j].source << " " << output[j].weight << endl;
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    edge *input = new edge[e];
    for (int i = 0; i < e; i++)
    {
        int s, d, w;
        cin >> s >> d >> w;
        input[i].source = s;
        input[i].desti = d;
        input[i].weight = w;
    }
    kruskal_algo(input, n, e);

    return 0;
}