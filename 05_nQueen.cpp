
//  N - Queen Problem

#include <iostream>
using namespace std;

#define N 10

class NQueens {

    int board[N][N];   //Creates a 2D array representing the chessboard.
    int n;   //Stores the actual board size entered by the user.

public:

    // Constructor
    NQueens(int size) {
        n = size;

        for(int i = 0; i < n; i++) {   // row
            for(int j = 0; j < n; j++) {    // column
                board[i][j] = 0;
            }
        }
    }

    // Check whether placing queen is safe
    
    /*Notice that we only check rows above the current 
    row because our algorithm places queens from top to bottom. */
    
    bool isSafe(int row, int col) {
        
        // Check column
        for(int i = 0; i < row; i++) {
            if(board[i][col] == 1)
                return false;
        }

        // Check upper left diagonal
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if(board[i][j] == 1)
                return false;
        }

        // Check upper right diagonal
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {

            if(board[i][j] == 1)
                return false;
        }

        return true;
    }

    // Recursive function to solve N-Queens
    bool solve(int row) {

        // Base condition
        if(row == n)
            return true;

        // Try placing queen in each column
        for(int col = 0; col < n; col++) {

            if(isSafe(row, col)) {

                // Place queen
                board[row][col] = 1;

                // Recursive call for next row
                if(solve(row + 1)){
                    return true;
                }

                // Backtracking
                board[row][col] = 0;
            }
        }

        return false;
    }

    // Display chessboard
    void display() {

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {

                if(board[i][j] == 1)
                    cout << " Q ";
                else
                    cout << " . ";
            }
            cout << endl;
        }
    }
};

int main() {

    int n;

    cout << "Enter number of queens: ";
    cin >> n;

    if(n < 1 || n > N) {
        cout << "Invalid board size!";
        return 0;
    }

    NQueens q(n);

    if(q.solve(0)) {
        cout << "\nSolution exists:\n";
        q.display();
    }
    else {
        cout << "\nNo solution exists!";
    }

    return 0;
}