
#include <iostream>
#include <algorithm>
using namespace std;

class Knapsack {

public:

    // Fractional Knapsack using Greedy
    double fractionalKnapsack(int weight[], int profit[], int n, int capacity) {

        double ratio[100];  //create an array called ratio

        for(int i = 0; i < n; i++) {
            ratio[i] = (double)profit[i] / weight[i];
        }

        // Sort items by profit/weight ratio
        // We sort the items in descending order of their ratios.
        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {

                if(ratio[i] < ratio[j]) {
                    swap(ratio[i], ratio[j]);
                    swap(weight[i], weight[j]);
                    swap(profit[i], profit[j]);
                }
            }
        }

        double totalProfit = 0;

        for(int i = 0; i < n; i++) {

            if(weight[i] <= capacity) {
                totalProfit += profit[i];
                capacity -= weight[i];
            }
            else {
                totalProfit += ratio[i] * capacity;
                break;
            }
        }

        return totalProfit;
    }
};

int main() {

    Knapsack k;

    int n, capacity;

    int weight[100], profit[100];

    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter weights of items:\n";
    for(int i = 0; i < n; i++) {
        cin >> weight[i];
    }

    cout << "Enter profits of items:\n";
    for(int i = 0; i < n; i++) {
        cin >> profit[i];
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    double fractional = k.fractionalKnapsack(weight, profit, n, capacity);

    cout << "\nFractional Knapsack Profit: " << fractional;

    return 0;
}
