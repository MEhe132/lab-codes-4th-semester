#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, edges;
    cout << "Enter the number of vertices and edges: ";
    cin >> n >> edges;

    // Adjacency List declaration
    vector<int> adj[n + 1];

    cout << "Enter the edges (u v):\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // For undirected graph
    }

    int start;
    cout << "Enter the starting vertex: ";
    cin >> start;

    vector<bool> visited(n + 1, false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    cout << "The nodes which are reachable are:\n";

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        // Look at only actual neighbors
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    return 0;
}

/*
Sample Input:
8 9
1 2
1 3
1 4
2 5
2 6
3 8
4 8
5 7
6 7
1
*/
