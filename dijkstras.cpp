#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void dijkstra(int n, vector<vector<int>> &graph, int src) {
    vector<int> dist(n, INT_MAX);  // Shortest distances from the source
    vector<bool> sptSet(n, false); // SPT set: tracks nodes included in the shortest path tree
    vector<int> parent(n, -1);     // To store the SPT

    dist[src] = 0; // Distance to the source is 0

    for (int count = 0; count < n - 1; ++count) {
        int u = -1;

        // Find the nearest unvisited node
        for (int i = 0; i < n; ++i)
            if (!sptSet[i] && (u == -1 || dist[i] < dist[u]))
                u = i;

        sptSet[u] = true;

        // Update distances for adjacent nodes
        for (int v = 0; v < n; ++v) {
            if (graph[u][v] && !sptSet[v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Print the SPT set and distances
    cout << "SPT Set (Node: Parent -> Distance):\n";
    for (int i = 0; i < n; ++i)
        if (i == src)
            cout << "Node " << i << " : Root\n";
        else
            cout << "Node " << i << " : " << parent[i] << " -> " << dist[i] << "\n";

    cout << "\nShortest distances from node " << src << ":\n";
    for (int i = 0; i < n; ++i)
        cout << "Node " << i << " : " << dist[i] << "\n";
}

int main() {
    int n, m;
    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter the number of edges: ";
    cin >> m;

    vector<vector<int>> graph(n, vector<int>(n, 0));

    cout << "Enter the edges in the format (u v w):\n";
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w; // Directed edge from u to v
        graph[v][u] = w; // Uncomment this line if the graph is undirected
    }

    int src;
    cout << "Enter the source node: ";
    cin >> src;

    dijkstra(n, graph, src);

    return 0;
}



// 0 1 5
// 0 2 6
// 1 3 3
// 1 2 8
// 2 4 6
// 1 4 4
// 3 4 3
// 3 5 7
// 4 5 7