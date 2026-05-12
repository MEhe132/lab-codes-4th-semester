#include <bits/stdc++.h>
using namespace std;

void dfs1(int v, vector<vector<int>>& adj, vector<bool>& vis, stack<int>& st) {
    vis[v] = true;
    for (int u : adj[v])
        if (!vis[u])
            dfs1(u, adj, vis, st);
    st.push(v);
}

void dfs2(int v, vector<vector<int>>& rev, vector<bool>& vis, vector<int>& component) {
    vis[v] = true;
    component.push_back(v);
    for (int u : rev[v])
        if (!vis[u])
            dfs2(u, rev, vis, component);
}

int countSCC(int V, vector<vector<int>>& adj) {
    stack<int> st;
    vector<bool> vis(V, false);

    // Step 1: Order vertices by finish time
    for (int i = 0; i < V; i++)
        if (!vis[i])
            dfs1(i, adj, vis, st);

    // Step 2: Reverse graph
    vector<vector<int>> rev(V);
    for (int i = 0; i < V; i++)
        for (int j : adj[i])
            rev[j].push_back(i);

    // Step 3: DFS in reverse order and collect SCCs
    fill(vis.begin(), vis.end(), false);
    int sccCount = 0;

    while (!st.empty()) {
        int v = st.top();
        st.pop();
        if (!vis[v]) {
            vector<int> component;
            dfs2(v, rev, vis, component);
            sccCount++;
            cout << "SCC " << sccCount << ": ";
            for (int node : component)
                cout << node << " ";
            cout << endl;
        }
    }
    return sccCount;
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> adj(V);

    cout << "Enter edges (u v) meaning u -> v:\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    int totalSCC = countSCC(V, adj);
    cout << "The number of SCC is : " << totalSCC << endl;
}

// for input you have to start the vertex number form 0 

// input:
// Enter number of vertices: 5
// Enter number of edges: 5
// Enter edges (u v) meaning u -> v:
// 0 3
// 0 2
// 1 0
// 2 1
// 3 4
// output:
// SCC 1: 0 1 2 
// SCC 2: 3
// SCC 3: 4
// The number of SCC is : 3



