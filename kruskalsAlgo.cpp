#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

int find(int u, vector<int> &parent) {
    if (u != parent[u])
        parent[u] = find(parent[u], parent); // Path compression
    return parent[u];
}

void kruskals(int n, vector<Edge> &edges) {
    sort(edges.begin(), edges.end(), compare);

    vector<int> parent(n);
    for (int i = 0; i < n; ++i) parent[i] = i;

    int mstWeight = 0;
    cout << "Edges in the MST:\n";
    for (auto &edge : edges) {
        int u = find(edge.u, parent);
        int v = find(edge.v, parent);

        if (u != v) { // No cycle
            cout << edge.u << " - " << edge.v << " | Weight: " << edge.weight << "\n";
            mstWeight += edge.weight;
            parent[u] = v;
        }
    }
    cout << "Total Weight of MST: " << mstWeight << "\n";
}

int main() {
    int n, e;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> e;

    vector<Edge> edges(e);
    cout << "Enter the edges (u, v, weight):\n";
    for (int i = 0; i < e; ++i)
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;

    kruskals(n, edges);
    return 0;
}
