#include <bits/stdc++.h>
using namespace std;

int parent[100];

int findParent(int x) {
    if(parent[x] == x)
        return x;
    return parent[x] = findParent(parent[x]);
}

void unionSet(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if(a != b)
        parent[b] = a;
}

int main() {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    map<char, int> mp;
    int idx = 0;

    vector<tuple<int,int,int>> edges; // weight, u, v

    cout << "Enter edges (format: a-b weight):\n";
    //this for loop code is only for converting a to 0, b to 1, c to 2 and so on. It is not a part of Prim's algorithm.
    for(int i = 0; i < m; i++) {
        string edge;
        int w;
        cin >> edge >> w;

        if(mp.find(edge[0]) == mp.end())
            mp[edge[0]] = idx++;

        if(mp.find(edge[2]) == mp.end())
            mp[edge[2]] = idx++;

        int u = mp[edge[0]];
        int v = mp[edge[2]];

        edges.push_back({w, u, v});
    }

    // initialize parent
    for(int i = 0; i < n; i++)
        parent[i] = i;

    // sort edges by weight
    sort(edges.begin(), edges.end());

    int totalCost = 0;

    for(auto e : edges) {
        int w = get<0>(e); //get is a built-in C++ function used to access values inside a tuple.here get<0>(e) means get the first value of the tuple e, which is the weight of the edge.
        int u = get<1>(e);
        int v = get<2>(e);

        if(findParent(u) != findParent(v)) {
            unionSet(u, v);
            totalCost += w;
        }
    }

    cout << "MST: " << totalCost << endl;

    return 0;
}