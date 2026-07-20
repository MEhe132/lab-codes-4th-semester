// give kruskal algorithm to find the minimum spanning tree of a graph
// give easy and documented code
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Edge {
	int u, v, wt;
};
// Disjoint Set Union (DSU) or Union-Find structure
class DSU {
public:
	vector<int> parent, rank;
	DSU(int n) {
		parent.resize(n);
		rank.resize(n, 0);
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}
	int find(int x) {
		if (parent[x] != x) {
			parent[x] = find(parent[x]); // Path compression
		}
		return parent[x];
	}
	void unite(int x, int y) {
		int rootX = find(x);
		int rootY = find(y);
		if (rootX != rootY) {
			if (rank[rootX] > rank[rootY]) {
				parent[rootY] = rootX;
			} else if (rank[rootX] < rank[rootY]) {
				parent[rootX] = rootY;
			} else {
				parent[rootY] = rootX;
				rank[rootX]++;
			}
		}
	}
};
int main() {
	int N, E;
	cout << "Enter number of vertices and edges: ";
	cin >> N >> E;

	vector<Edge> edges(E);
	cout << "Enter edges (u v weight):\n";
	for (int i = 0; i < E; i++) {
		cin >> edges[i].u >> edges[i].v >> edges[i].wt;
	}

	// Kruskal's Algorithm
	DSU dsu(N);
	vector<Edge> mstEdges;

	// Sort edges based on weight
	sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
		return a.wt < b.wt;
	});

	for (auto edge : edges) {
		int rootU = dsu.find(edge.u);
		int rootV = dsu.find(edge.v);

		if (rootU != rootV) { // If u and v are in different sets
			dsu.unite(rootU, rootV); // Union the sets
			mstEdges.push_back(edge); // Add edge to MST
		}
	}

	// Print the edges in the MST
	cout << "\nEdges in the Minimum Spanning Tree:\n";
	for (auto edge : mstEdges) {
		cout << edge.u << " - " << edge.v << " (Weight: " << edge.wt << ")\n";
	}

	return 0;
}

// 5 7
// 0 1 10
// 0 2 20
// 1 2 30
// 1 3 5
// 2 3 15
// 3 4 8
// 2 4 25