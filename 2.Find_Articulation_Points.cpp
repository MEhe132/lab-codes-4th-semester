#include <bits/stdc++.h>
using namespace std;

void AP_DFS(int u, int parent, vector<vector<int>>& adj, vector<bool>& visited, 
            vector<int>& disc, vector<int>& low, vector<bool>& ap, int &time) {
    
    visited[u] = true;
    disc[u] = low[u] = ++time;
    int children = 0;

    for (int v : adj[u]) {
        if (!visited[v]) {
            children++;
            AP_DFS(v, u, adj, visited, disc, low, ap, time);
            low[u] = min(low[u], low[v]);

            // Case 1: u is root of DFS and has two or more children
            if (parent == -1 && children > 1)
                ap[u] = true;

            // Case 2: u is not root and low[v] >= disc[u]
            if (parent != -1 && low[v] >= disc[u])
                ap[u] = true;
        }
        else if (v != parent) {
            low[u] = min(low[u], disc[v]);
        }
    }
}
// input :                // output:  Articulation Points are: 1 3             
// 5
// 5
// 0 1                      
// 0 2
// 1 2
// 1 3
// 3 4

void findArticulationPoints(int V, vector<vector<int>>& adj) {
    vector<bool> visited(V, false);
    vector<int> disc(V, -1);
    vector<int> low(V, -1);
    vector<bool> ap(V, false);
    int time = 0;

    for (int i = 0; i < V; i++)
        if (!visited[i])
            AP_DFS(i, -1, adj, visited, disc, low, ap, time);

    cout << "Articulation Points are: ";
    for (int i = 0; i < V; i++)
        if (ap[i])
            cout << i << " ";
    cout << endl;
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> adj(V);
    cout << "Enter edges (u v) undirected:\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    findArticulationPoints(V, adj);
}





