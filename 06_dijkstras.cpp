
#include <iostream>
using namespace std;

#define MAX 10
#define INF 99999

class CityGraph {

    int graph[MAX][MAX];  // It represents our adjacency matrix., Each cell stores the distance between two vertices. 
    int n;  //stores the total number of vertices.

public:

    // Constructor
    CityGraph(int vertices) {

        n = vertices;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {

                if(i == j)
                    graph[i][j] = 0;
                else
                    graph[i][j] = INF;
            }
        }
    }

    // Add road between landmarks
    void addEdge(int u, int v, int weight) {   //This function adds a connection between two vertices.

        graph[u][v] = weight;
        graph[v][u] = weight;
    }

    // Dijkstra's Algorithm
    void dijkstra(int source) {

        int dist[MAX];  //array stores the shortest known distance from the source vertex to every other vertex.
        bool visited[MAX]; //It tells us whether a vertex has been processed or not., When we finish selecting and processing a vertex, we mark it as true.


        // Initialize arrays
        for(int i = 0; i < n; i++) {

            dist[i] = INF;
            visited[i] = false;
        }

        dist[source] = 0;

        // Repeat until all vertices are processed
        for(int count = 0; count < n - 1; count++) {

            int minDist = INF; //Stores the minimum distance found so far.
            int u = -1;  //Stores the vertex number having the minimum distance.

            // Find minimum distance unvisited vertex
            for(int i = 0; i < n; i++) {

                if(!visited[i] && dist[i] < minDist) { //Check whether this vertex is unvisited and whether its distance is smaller than our current minimum distance

                    minDist = dist[i];
                    u = i;
                }
            }

            if(u == -1) //u represents the selected vertex.
                break;

            visited[u] = true;

            // Update adjacent vertices
            //check all vertices to see whether they are connected to our selected vertex u.
            for(int v = 0; v < n; v++) {  //v represents the vertex we are checking.

                if(!visited[v] && graph[u][v] != INF && dist[u] + graph[u][v] < dist[v]) {

                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }

        // Display shortest distances
        cout << "\nShortest distances from Landmark "
             << source << ":\n";

        for(int i = 0; i < n; i++) {

            if(dist[i] == INF)
                cout << "Landmark " << i << " = Unreachable\n";
            else
                cout << "Landmark " << i
                     << " = " << dist[i] << endl;
        }
    }
};

int main() {

    int n, edges;

    cout << "Enter number of landmarks: ";
    cin >> n;

    CityGraph city(n);

    cout << "Enter number of roads: ";
    cin >> edges;

    cout << "\nEnter roads (source destination distance):\n";

    for(int i = 0; i < edges; i++) {

        int u, v, w;

        cin >> u >> v >> w;

        city.addEdge(u, v, w);
    }

    int source;

    cout << "\nEnter source landmark: ";
    cin >> source;

    city.dijkstra(source);

    return 0;
}
