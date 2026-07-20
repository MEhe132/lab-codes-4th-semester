#include <bits/stdc++.h>
using namespace std;

// Global time counter
int timer;

// DFS to find articulation points
void dfs(int u, int parent,
        vector<int>& disc, vector<int>& low,
        vector<bool>& visited,
        vector<vector<int>>& adj,
        vector<bool>& isArt) {

    visited[u] = true;

    // Set discovery time and low-link value
    disc[u] = low[u] = ++timer;

    int children = 0; // number of DFS children

    for (int v : adj[u]) {

        if (!visited[v]) {
            children++;
            dfs(v, u, disc, low, visited, adj, isArt);

            // Update low-link after child DFS
            low[u] = min(low[u], low[v]);

            // Non-root articulation condition
            if (parent != -1 && low[v] >= disc[u])
                isArt[u] = true;

        } else if (v != parent) {
            // Found back edge
            low[u] = min(low[u], disc[v]);
        }
    }

    // Root node special case
    if (parent == -1 && children > 1)
        isArt[u] = true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;  // nodes and edges

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        // Undirected edge
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> disc(n, 0), low(n, 0);
    vector<bool> visited(n, false), isArt(n, false);

    timer = 0;

    // Run DFS from every unvisited node
    for (int i = 0; i < n; i++)
        if (!visited[i])
            dfs(i, -1, disc, low, visited, adj, isArt);

    // Print articulation points
    cout << "Articulation points:\n";
    for (int i = 0; i < n; i++)
        if (isArt[i])
            cout << i << " ";

    return 0;
}

// 6 7
// 0 1
// 1 2
// 2 0
// 1 3
// 3 4
// 3 5
// 4 5