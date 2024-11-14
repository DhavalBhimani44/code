#include <bits/stdc++.h>
using namespace std;

void floydWarshall(vector<vector<int>>& dist, int V) {
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                // If vertex k is on the shortest path from i to j,
                // then update the value of dist[i][j]
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX &&
                    dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

void printSolution(const vector<vector<int>>& dist, int V) {
    cout << "Adjacency matrix of Flyod Warshall:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INT_MAX)
                cout << "INF\t";
            else
                cout << dist[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    // Initialize the distance matrix
    vector<vector<int>> dist(V, vector<int>(V, INT_MAX));

    // Setting the diagonal to zero since the distance from any vertex to itself is zero
    for (int i = 0; i < V; i++) {
        dist[i][i] = 0;
    }

    int E;
    cout << "Enter the number of edges: ";
    cin >> E;

    cout << "Enter each edge in the format: src dest weight\n";
    for (int i = 0; i < E; i++) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        dist[src][dest] = weight;
    }

    floydWarshall(dist, V);

    printSolution(dist, V);

    return 0;
}

//Input
// 0 1 4
// 1 4 6
// 4 0 1
// 1 2 1
// 2 0 2
// 0 3 5
// 2 3 3
// 3 2 1
// 4 3 4
// 3 4 2