// BFS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of vertices:";
    cin >> n;
    //define graph as 2D vector
    vector<vector<int>> graph(n + 1, vector<int>(n + 1));

    cout << "Enter graph data in matrix form:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> graph[i][j];
        }
    }

    int start;
    cout << "Enter the starting vertex:";
    cin >> start;

    vector<bool> visited(n + 1, false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    cout << "The node which are reachable are:\n";

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int i = 1; i <= n; i++) {
            if (graph[node][i] == 1 && !visited[i]) { 
                visited[i] = true;
                q.push(i);
            }
        }
    }

    return 0;
}


//example input
/*
Enter the number of vertices:5
Enter graph data in matrix form:
0 1 1 0 0
1 0 0 1 1
1 0 0 0 0
0 1 0 0 0
0 1 0 0 0
Enter the starting vertex:1 
The node which are reachable are:
1 2 3 4 5 
*/
