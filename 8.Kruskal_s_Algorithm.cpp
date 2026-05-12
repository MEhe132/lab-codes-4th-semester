#include <bits/stdc++.h>
using namespace std;

int parent[100], RankArr[100];

// Find parent with path compression
int findParent(int node)
{
    if (node == parent[node])
        return node;

    return parent[node] = findParent(parent[node]);
}

// Union by rank
void unionSet(int u, int v)
{
    u = findParent(u);
    v = findParent(v);

    if (u != v)
    {
        if (RankArr[u] < RankArr[v])
            parent[u] = v;
        else if (RankArr[u] > RankArr[v])
            parent[v] = u;
        else
        {
            parent[v] = u;
            RankArr[u]++;
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    // each edge = {weight, u, v}
    vector<vector<int>> edges;

    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }

    // sort by weight
    sort(edges.begin(), edges.end());

    // initialize DSU (disjoint set union)
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        RankArr[i] = 0;
    }

    int totalCost = 0;

    for (auto edge : edges)
    {
        int w = edge[0];
        int u = edge[1];
        int v = edge[2];

        if (findParent(u) != findParent(v))
        {
            totalCost += w;
            unionSet(u, v);
        }
    }

    cout << "Total cost of MST = " << totalCost << endl;   //Minimum Spanning Tree

    return 0;
}