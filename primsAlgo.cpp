#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Function to find the vertex with the minimum key value that is not yet included in the MST
int findMinVertex(vector<int>& key, vector<bool>& inMST, int V) {
    int minKey = INT_MAX;
    int minVertex = -1;
    
    for (int i = 0; i < V; i++) {
        if (!inMST[i] && key[i] < minKey) {
            minKey = key[i];
            minVertex = i;
        }
    }
    
    return minVertex;
}

// Prim's Algorithm implementation
void primMST(vector<vector<int>>& graph, int V) {
    vector<int> parent(V, -1);     // Stores the MST
    vector<int> key(V, INT_MAX);   // Minimum edge weight to reach each vertex
    vector<bool> inMST(V, false);  // Track vertices included in the MST
    int totalCost = 0;             // To store the total cost of the MST

    // Start from the first vertex
    key[0] = 0;

    for (int i = 0; i < V - 1; i++) {
        int u = findMinVertex(key, inMST, V);
        inMST[u] = true;

        // Update key and parent of the adjacent vertices
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Print the MST and calculate the total cost
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << "\n";
        totalCost += graph[i][parent[i]];
    }

    // Print the total cost of the MST
    cout << "Total cost of MST: " << totalCost << endl;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;

    // Initialize a VxV adjacency matrix
    vector<vector<int>> graph(V, vector<int>(V, 0));

    cout << "Enter the number of edges: ";
    cin >> E;

    cout << "Enter the edges in the format (u v w) where u and v are vertices and w is the weight:\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;  // Since the graph is undirected
    }

    // Run Prim's algorithm
    primMST(graph, V);

    return 0;
}

// Sample Input
// 0 1 10
// 0 2 4
// 2 1 2
// 2 4 1
// 1 4 6
// 1 3 3