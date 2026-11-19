
#include <iostream>
#include <climits>
using namespace std;

class TSP {

    int n;
    int cost[10][10];

    int bestCost = INT_MAX;
    int path[10], bestPath[10];

    int calculateBound(int visited, int currentCost) {

        int bound = currentCost;

        for(int i = 0; i < n; i++) {

            if(!(visited & (1 << i))) {

                int minCost = INT_MAX;

                for(int j = 0; j < n; j++) {
                    if(i != j && cost[i][j] < minCost)
                        minCost = cost[i][j];
                }

                bound += minCost;
            }
        }

        return bound;
    }

    void solve(int current, int visited,
               int currentCost, int level) {

        if(level == n) {

            int totalCost = currentCost + cost[current][0];

            if(totalCost < bestCost) {

                bestCost = totalCost;

                for(int i = 0; i < n; i++)
                    bestPath[i] = path[i];

                bestPath[n] = 0;
            }

            return;
        }

        int bound = calculateBound(visited, currentCost);

        if(bound >= bestCost)
            return;

        // Visit unvisited cities
        for(int i = 0; i < n; i++) {

            if(!(visited & (1 << i))) {

                path[level] = i;

                solve(i, visited | (1 << i),
                      currentCost + cost[current][i],
                      level + 1);
            }
        }
    }

public:

    void input() {

        cout << "Enter number of cities: ";
        cin >> n;

        cout << "Enter cost matrix:\n";

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> cost[i][j];
            }
        }
    }

    void display() {

        path[0] = 0;

        solve(0, 1, 0, 1);

        cout << "\nOptimal Path: ";

        for(int i = 0; i <= n; i++)
            cout << bestPath[i] << " ";

        cout << "\nMinimum Cost: " << bestCost << endl;
    }
};

int main() {

    TSP t;

    t.input();
    t.display();

    return 0;
}
