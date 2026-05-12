#include <bits/stdc++.h>
using namespace std;

struct node {
    int u, v, wt;
    node(int _u, int _v, int _wt) {
        u = _u;
        v = _v;
        wt = _wt;
    }
};

int main() {

    int N, m;
    cout << "Enter number of nodes and edges: ";
    cin >> N >> m;           //N=nodes, m=edges

    vector<node> edges;
    cout << "Enter edges (u v weight): " << endl;
    for(int i = 0; i < m; i++) {
        int u, v, wt;

        cin >> u >> v >> wt;
        edges.push_back(node(u, v, wt)); 
    }
    int src;
    cout << "Enter source node: ";
    cin >> src;
    int inf = 10000000;
    vector<int> dist(N, inf);
    dist[src] = 0;

    //Relaxation step (N-1 times)
    for(int i = 1; i <= N - 1; i++) {
        for(auto it : edges) {
            if(dist[it.u] != inf && dist[it.u] + it.wt < dist[it.v]) {
                dist[it.v] = dist[it.u] + it.wt;
            }
        }
    }

    //Relaxation step (1 more time to detect negative cycle).cause bellman ford can be relaxed only n-1 times. if we can still relax then there is a negative cycle
    //Negative cycle detection 
    int flag = 0;
    for(auto it : edges) {
        if(dist[it.u] != inf && dist[it.u] + it.wt < dist[it.v]) {
            cout << "Negative Cycle" << endl;
            flag = 1;
            break;
        }
    }

    //Print distances from source to all vertices
    if(!flag) {
        cout<<"vertex"<<" "<<"distance from source"<<endl;
        for(int i = 0; i < N; i++) {
            cout << i << "       ";
            if(dist[i] == inf) cout << "INF" << endl;
            else cout << dist[i] << endl;
        }
    }

    return 0;
}

