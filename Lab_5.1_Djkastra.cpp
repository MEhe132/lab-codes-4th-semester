//Dijkstra's Algorithm
#include <bits/stdc++.h>
using namespace std;

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<pair<int, int>> adj[V + 1];

    cout<<"Enter edges (u v weight): "<<endl;
    for (int i = 0; i < E; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt}); // remove this line if directed graph
    }

    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    vector<int> dist(V + 1, INT_MAX);

    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int currentDistance = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node]) {
            int nextNode = it.first;
            int edgeWeight = it.second;

            if (currentDistance + edgeWeight < dist[nextNode]) {
                dist[nextNode] = currentDistance + edgeWeight;
                pq.push({dist[nextNode], nextNode});
            }
        }
    }

    for (int i = 1; i <= V; i++) {
        cout << "Distance from " << source << " to " << i << " = " << dist[i] << endl;
    }

    return 0;
}

/*
Enter number of vertices and edges: 6 8
Enter edges (u v weight): 
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
5 4 2
4 6 1
5 6 5
Enter source vertex: 1
Distance from 1 to 1 = 0
Distance from 1 to 2 = 2
Distance from 1 to 3 = 3
Distance from 1 to 4 = 8
Distance from 1 to 5 = 6
Distance from 1 to 6 = 9
*/