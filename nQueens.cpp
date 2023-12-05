/*
 * Name: Prahalad Gururajan	
 * Date Submitted: November 20, 2023
 * Lab Section: 007
 * Assignment Name: Using Recursion to Solve the N-Queens Problem
 */

/*Description: The code efficiently solves the n-queens problem, where the task is to place n queens 
on an n × n chess board such that no two queens attack each other. The algorithm uses a recursive 
backtracking approach, exploring all possible queen placements row by row while ensuring that each 
placement is safe. The isSafe function verifies the safety of a queen's position, and the main nQueens 
function initializes the chess board and invokes the recursive helper function to count the distinct 
solutions for a given n. Thank you for reviewing my code!!!! :):):)                       */

#include <iostream>
#include <vector>

using namespace std;

// Function to check if a queen can be placed in a specific position
bool isSafe(const vector<int>& board, int row, int col) {
    // Check if there is a queen in the same column
    for (int i = 0; i < row; ++i) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

// Recursive function to count distinct solutions for placing queens
int nQueensHelper(vector<int>& board, int row, int n) {
    if (row == n) {
        // All queens are placed successfully, increment the count
        return 1;
    }

    int count = 0;
    for (int col = 0; col < n; ++col) {
        if (isSafe(board, row, col)) {
            // Place queen in the current position
            board[row] = col;

            // Recursively check for the next row
            count += nQueensHelper(board, row + 1, n);

            // Backtrack and try the next column
            board[row] = -1;
        }
    }

    return count;
}

//Uses recursion to count how many solutions there are for
//placing n queens on an nxn chess board
int nQueens(int n)
{
    // Initialize the board with all positions set to -1
    vector<int> board(n, -1);

    // Start with the first row
    return nQueensHelper(board, 0, n);
}

/*int main()
{
    cout << "1: " << nQueens(1) << endl;
    cout << "2: " << nQueens(2) << endl;
    cout << "3: " << nQueens(3) << endl;
    cout << "4: " << nQueens(4) << endl;
    cout << "5: " << nQueens(5) << endl;
    cout << "6: " << nQueens(6) << endl;
    cout << "7: " << nQueens(7) << endl;
    cout << "8: " << nQueens(8) << endl;
    cout << "9: " << nQueens(9) << endl;
    cout << "10: " << nQueens(10) << endl;
    cout << "11: " << nQueens(11) << endl;
    cout << "12: " << nQueens(12) << endl;
    return 0;
}*/