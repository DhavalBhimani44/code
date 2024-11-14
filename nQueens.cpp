#include <iostream>
#include <vector>
using namespace std;

#define N 8

void printBoard(vector<vector<int>>& board) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout << endl;
    }
    cout << endl;
}

// Function to check if it's safe to place a queen at board[row][col]
bool isSafe(vector<vector<int>>& board, int row, int col) {
    // Check the row on the left side
    for (int i = 0; i < col; i++) {
        if (board[row][i]) {
            return false;
        }
    }

    // Check the upper diagonal on the left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    // Check the lower diagonal on the left side
    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}

// Function to solve the N Queens problem using backtracking
bool solveNQueensUtil(vector<vector<int>>& board, int col) {
    // Base case: If all queens are placed
    if (col >= N) {
        return true;
    }

    // Try placing a queen in each row of the current column
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            // Place the queen
            board[i][col] = 1;

            // Recursively place the rest of the queens
            if (solveNQueensUtil(board, col + 1)) {
                return true;
            }

            // If placing the queen doesn't lead to a solution, backtrack
            board[i][col] = 0;
        }
    }

    // If the queen cannot be placed in any row in this column, return false
    return false;
}

// Function to solve the N Queens problem
bool solveNQueens() {
    vector<vector<int>> board(N, vector<int>(N, 0));  // Initialize an N x N board with 0s

    if (!solveNQueensUtil(board, 0)) {
        cout << "Solution does not exist" << endl;
        return false;
    }

    printBoard(board);
    return true;
}

int main() {
    solveNQueens();
    return 0;
}
