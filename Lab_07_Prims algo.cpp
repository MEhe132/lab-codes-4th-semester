// give prims algorithm to find the minimum spanning tree of a graph
// give easy and documented code
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct Edge {
	int u, v, wt;
};

int main() {
	int N, E;
	cout << "Enter number of vertices and edges: ";
	cin >> N
	>> E;

	vector<vector<pair<int, int>>> adj(N);
	cout << "Enter edges (u v weight):\n";
	for (int i = 0; i < E; i++) {
		int u, v, wt;
		cin >> u >> v >> wt;
		adj[u].push_back({v, wt});
		adj[v].push_back({u, wt}); // For undirected graph
	}

	// Prim's Algorithm
	vector<bool> inMST(N, false);
	vector<int> key(N, INT_MAX);
	vector<int> parent(N, -1);
	key[0] = 0; // Start from the first vertex
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, 0}); // {key, vertex}

	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();

		if (inMST[u]) continue; // Skip if already included in MST
		inMST[u] = true;

		for (auto it : adj[u]) {
			int v = it.first;
			int wt = it.second;

			if (!inMST[v] && wt < key[v]) {
				key[v] = wt;
				parent[v] = u;
				pq.push({key[v], v});
			}
		}
	}

	// Print the edges in the MST
	cout << "\nEdges in the Minimum Spanning Tree:\n";
	for (int i = 1; i < N; i++) {
		if (parent[i] != -1) {
			cout << parent[i] << " - " << i << " (Weight: " << key[i] << ")\n";
		}
	}
	return 0;
}


// sample input
5 7
0 1 10
0 2 20
1 2 30
1 3 5
2 3 15
3 4 8
2 4 25
