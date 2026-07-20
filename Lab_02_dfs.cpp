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
    stack<int> st;

    st.push(start);

    cout << "The nodes which are reachable are:\n";

    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (!visited[node]) {
            visited[node] = true;
            cout << node << " ";

            // Push neighbors into stack
            // (Reversing the loop is optional, but it helps match the exact order of recursive DFS if needed)
            for (int i = adj[node].size() - 1; i >= 0; i--) {
                int neighbor = adj[node][i];
                if (!visited[neighbor]) {
                    st.push(neighbor);
                }
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