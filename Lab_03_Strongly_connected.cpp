#include <bits/stdc++.h>
using namespace std;

// First DFS — go deep and then store nodes in a stack
void dfs1(int node, vector<vector<int>>& graph, vector<bool>& visited, stack<int>& st) {
    visited[node] = true;
    for (int nxt : graph[node])
        if (!visited[nxt])
            dfs1(nxt, graph, visited, st);

    st.push(node); // push AFTER finishing children
}

// Second DFS on reversed graph — prints one SCC
void dfs2(int node, vector<vector<int>>& revGraph, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";
    for (int nxt : revGraph[node])
        if (!visited[nxt])
            dfs2(nxt, revGraph, visited);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;  // number of nodes and edges

    vector<vector<int>> graph(n), revGraph(n);

    // read directed edges
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        revGraph[v].push_back(u);  // reverse edge
    }

    vector<bool> visited(n, false);
    stack<int> st;

    // phase 1: normal DFS, fill stack by finish time
    for (int i = 0; i < n; i++)
        if (!visited[i])
            dfs1(i, graph, visited, st);

    // reset visited for second pass
    fill(visited.begin(), visited.end(), false);

    // phase 2: pop from stack and run DFS on reversed graph
    cout << "SCCs:\n";
    while (!st.empty()) {
        int v = st.top();
        st.pop();

        if (!visited[v]) {
            dfs2(v, revGraph, visited);
            cout << "\n"; // one SCC done
        }
    }
    return 0;
}

    // 6 7
    // 0 1
    // 1 2
    // 2 3
    // 3 0
    // 1 3
    // 4 5
    // 5 4