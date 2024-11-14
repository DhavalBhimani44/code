#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Edge {
public:
    int src, dest, weight;
};
    
class Graph {
public:
    int V, E;
    vector<Edge> edges;

    Graph(int V, int E) {
        this->V = V;
        this->E = E;
        edges.resize(E);
    }

    void addEdge(int i, int u, int v, int w) {
        edges[i].src = u;
        edges[i].dest = v;
        edges[i].weight = w;
    }
};

class DisjointSets {
public:
    vector<int> parent, rank;

    DisjointSets(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void merge(int u, int v) {
        u = find(u);
        v = find(v);

        if (rank[u] < rank[v])
            parent[u] = v;
        else if (rank[u] > rank[v])
            parent[v] = u;
        else {
            parent[v] = u;
            rank[u]++;
        }
    }
};

bool compareEdges(Edge e1, Edge e2) {
    return e1.weight < e2.weight;
}

void kruskalMST(Graph& graph) {
    vector<Edge> result;
    int V = graph.V;

    sort(graph.edges.begin(), graph.edges.end(), compareEdges);

    DisjointSets ds(V);

    for (Edge edge : graph.edges) {
        int u = ds.find(edge.src);
        int v = ds.find(edge.dest);

        if (u != v) {
            result.push_back(edge);
            ds.merge(u, v);
        }
    }

    int totalWeight = 0;
    cout << "Edge \tWeight" << endl;
    for (Edge e : result) {
        cout << e.src << " - " << e.dest << "\t" << e.weight << endl;
        totalWeight += e.weight;
    }
    cout << "Total weight of MST: " << totalWeight << endl;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;

    cout << "Enter the number of edges: ";
    cin >> E;

    Graph graph(V, E);

    cout << "Enter the edges (source, destination, weight):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph.addEdge(i, u, v, w);
    }

    kruskalMST(graph);

    return 0;
}
