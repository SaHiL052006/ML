// 0-1 Knapsack using DP

#include <iostream>
using namespace std;

class Knapsack{
public:
    // 0/1 Knapsack using Dynamic Programming
    int zeroOneKnapsack(int weight[], int profit[], int n, int capacity) {

        int dp[100][100];  //Rows represent how many items we are considering. Columns represent the capacity of the bag.
        
       for(int i = 0; i <= n; i++) {  //i means number of items considered.,  w means current bag capacity.
            for(int w = 0; w <= capacity; w++) {  // the program calculates the maximum profit for every combination of item count and capacity.

                if(i == 0 || w == 0) {
                    dp[i][w] = 0;
                }

                else if(weight[i-1] <= w) {

                    dp[i][w] = max(profit[i-1] + dp[i-1][w-weight[i-1]], dp[i-1][w] );
                }

                else {
                    dp[i][w] = dp[i-1][w];
                }
            }
        }

        return dp[n][capacity];
    }
};
int main(){
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

    int zeroOne = k.zeroOneKnapsack(weight, profit, n, capacity);

    cout << "\n0/1 Knapsack Profit: " << zeroOne;

    return 0;

}
