
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class BellmanFord {

    int V, E;

    struct Edge {
        int src, dest, weight;
    };

    vector<Edge> edges;

public:

    // Constructor
    BellmanFord(int v, int e) {
        V = v;
        E = e;
    }

    // Add edge
    void addEdge(int u, int v, int w) {
        edges.push_back({u, v, w});
    }

    // Bellman-Ford Algorithm
    void findShortestPath(int source) {

        vector<int> dist(V, INT_MAX);

        dist[source] = 0;

        // Relax all edges V-1 times
        for(int i = 1; i <= V - 1; i++) {

            for(int j = 0; j < E; j++) {

                int u = edges[j].src;
                int v = edges[j].dest;
                int w = edges[j].weight;

                if(dist[u] != INT_MAX &&
                   dist[u] + w < dist[v]) {

                    dist[v] = dist[u] + w;
                }
            }
        }

        // Check for negative weight cycle
        for(int j = 0; j < E; j++) {

            int u = edges[j].src;
            int v = edges[j].dest;
            int w = edges[j].weight;

            if(dist[u] != INT_MAX &&
               dist[u] + w < dist[v]) {

                cout << "Graph contains negative weight cycle!";
                return;
            }
        }

        // Display shortest distances
        cout << "\nVertex\tDistance from Source\n";

        for(int i = 0; i < V; i++) {

            cout << i << "\t";

            if(dist[i] == INT_MAX)
                cout << "INF";
            else
                cout << dist[i];

            cout << endl;
        }
    }
};

int main() {

    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    BellmanFord graph(V, E);

    cout << "Enter source, destination and weight:\n";

    for(int i = 0; i < E; i++) {

        int u, v, w;
        cin >> u >> v >> w;

        graph.addEdge(u, v, w);
    }

    int source;

    cout << "Enter source vertex: ";
    cin >> source;

    graph.findShortestPath(source);

    return 0;
}
