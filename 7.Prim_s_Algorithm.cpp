#include <bits/stdc++.h>
using namespace std;

#define INF 1e9  // A large value representing infinity

int main()
{
    int n, e;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> e;

    // Adjacency list: for each node store (neighbor, weight)
    vector<pair<int, int>> adj[n + 1];

    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        // Undirected graph → store both directions
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // key[i] = minimum weight edge to connect node i
    vector<int> key(n + 1, INF);

    // parent[i] = parent of node i in MST
    vector<int> parent(n + 1, -1);

    // inMST[i] = true if node i is already included in MST
    vector<bool> inMST(n + 1, false);

    // Min-heap (weight, node)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Start from node 1
    key[1] = 0;
    pq.push({0, 1});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        // Skip if already included
        if (inMST[u])
            continue;

        // Include node in MST
        inMST[u] = true;

        // Check all adjacent nodes
        for (auto it : adj[u])
        {
            int v = it.first;
            int weight = it.second;

            // If v not in MST and found smaller edge
            if (!inMST[v] && weight < key[v])
            {
                key[v] = weight;     // update minimum weight
                parent[v] = u;       // update parent
                pq.push({key[v], v}); // push into heap
            }
        }
    }

    int totalCost = 0;
    cout << "\nEdges in Prim's MST:\n";

    // Print MST edges
    for (int i = 2; i <= n; i++)
    {
        if (parent[i] != -1)
        {
            cout << parent[i] << " - " << i << " = " << key[i] << endl;
            totalCost += key[i];
        }
    }

    cout << "Total cost of MST = " << totalCost << endl;

    return 0;
}