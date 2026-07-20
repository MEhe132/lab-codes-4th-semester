#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, wt;
};

int main() {
    int N, E;
    cout << "Enter number of vertices and edges: ";
    cin >> N >> E;

    vector<Edge> edges;

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({u, v, wt});
    }

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    const int INF = 1e9;
    vector<int> dist(N + 1, INF); // ✅ FIXED

    // Step 1: Initialize
    dist[src] = 0;

    // Step 2: Relax edges
    for (int i = 1; i <= N - 1; i++) {
        for (auto it : edges) {
            if (dist[it.u] != INF && dist[it.u] + it.wt < dist[it.v]) {
                dist[it.v] = dist[it.u] + it.wt;
            }
        }
    }

    // Step 3: Detect negative cycle
    bool hasNegativeCycle = false;
    for (auto it : edges) {
        if (dist[it.u] != INF && dist[it.u] + it.wt < dist[it.v]) {
            cout << "Negative Cycle Detected!\n";
            hasNegativeCycle = true;
            break;
        }
    }

    // Step 4: Print result
    if (!hasNegativeCycle) {
        cout << "\nShortest distances from source " << src << ":\n";
        for (int i = 1; i <= N; i++) {
            if (dist[i] == INF)
                cout << "Node " << i << " : INF\n";
            else
                cout << "Node " << i << " : " << dist[i] << "\n";
        }
    }

    return 0;
}
// sample input 
// Enter number of vertices and edges: 7 10
// Enter edges (u v weight):
// 1 2 6
// 1 4 5
// 1 3 5
// 2 5 -1
// 3 2 -2
// 3 5 1
// 4 3 -2
// 4 6 -1
// 5 7 3 
// 6 7 3

// For neg cycle 
// N E : 4 5 
// u v wt: 
// 1 2 4 
// 1 4 5
// 2 4 5
// 3 2 -10
// 4 3 3