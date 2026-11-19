
#include <iostream>
using namespace std;

#define INF 999

class FloydWarshall {

public:

    void calculate(int dist[10][10], int n) {

        for(int k = 0; k < n; k++) {  // k = Intermediate vertex
            for(int i = 0; i < n; i++) {  // i = Starting vertex
                for(int j = 0; j < n; j++) {  // j = Destination vertex

                    if(dist[i][k] != INF && dist[k][j] != INF) {

                        if(dist[i][k] + dist[k][j] < dist[i][j]) {

                            dist[i][j] = dist[i][k] + dist[k][j];   // Distance from i to j through k

                        }
                    }
                }
            }
        }
    }

    void display(int dist[10][10], int n) {

        cout << "\nShortest Distance Matrix:\n";

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < n; j++) {

                if(dist[i][j] == INF)
                    cout << "INF\t";
                else
                    cout << dist[i][j] << "\t";

            }

            cout << endl;
        }
    }
};

int main() {

    int n;
    int dist[10][10];

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix (999 for no edge):\n";

    for(int i = 0; i < n; i++) {

        for(int j = 0; j < n; j++) {

            cin >> dist[i][j];

        }
    }

    FloydWarshall f;

    f.calculate(dist, n);

    f.display(dist, n);

    return 0;
}
