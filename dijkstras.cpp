#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits>

using namespace std;

void dijkstra(int src, const vector<vector<pair<int, int>>> &graph, vector<int> &dist, vector<bool> &sptSet) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;  
        pq.pop();

        sptSet[u] = true;

        for (const auto &neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            // If the distance to v can be minimized
            if (!sptSet[v] && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});  
            }
        }
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    // Graph representation: adjacency list
    vector<vector<pair<int, int>>> graph(V);

    cout << "Enter edges (source, destination, weight):\n";
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});  // Remove this line if the graph is directed
    }

    int src;
    cout << "Enter the source vertex: ";
    cin >> src;

    vector<int> dist(V, numeric_limits<int>::max());

    vector<bool> sptSet(V, false);

    dijkstra(src, graph, dist, sptSet);

    cout << "\nShortest distances from source vertex " << src << ":\n";
    for (int i = 0; i < V; ++i) {
        if (dist[i] == numeric_limits<int>::max()) {
            cout << "Vertex " << i << ": Unreachable\n";
        } else {
            cout << "Vertex " << i << ": " << dist[i] << "\n";
        }
    }

    cout << "\nVertices in the Shortest Path Tree (SPT):\n";
    for (int i = 0; i < V; ++i) {
        if (sptSet[i]) {
            cout << "Vertex " << i << " is included in the SPT.\n";
        }
    }

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