#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void prims(int n, vector<vector<int>> &graph) {
    vector<int> key(n, INT_MAX);  
    vector<bool> inMST(n, false); 
    vector<int> parent(n, -1);    
    int totalWeight = 0;          

    key[0] = 0; 

    for (int count = 0; count < n - 1; ++count) {
        int u = -1;

        // Find the smallest key node not in MST
        for (int i = 0; i < n; ++i)
            if (!inMST[i] && (u == -1 || key[i] < key[u]))
                u = i;

        inMST[u] = true;

        // Update keys for adjacent vertices
        for (int v = 0; v < n; ++v)
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
    }

    // Print MST
    cout << "Edges in the MST:\n";
    for (int i = 1; i < n; ++i) {
        cout << parent[i] << " - " << i << " | Weight: " << graph[parent[i]][i] << "\n";
        totalWeight += graph[parent[i]][i];
    }
    cout << "Total Weight of MST: " << totalWeight << "\n";
}

int main() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    cout << "Enter the adjacency matrix (use 0 for no edge):\n";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> graph[i][j];

    prims(n, graph);
    return 0;
}
