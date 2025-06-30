class Solution {
public:
    // Helper function to check if placing a Queen at (row, col) is safe
    bool isSafe(int row, int col, vector<vector<char>>& board) {
        int n = board.size();

        // Check vertically upward in the same column
        for (int i = row - 1; i >= 0; i--) {
            if (board[i][col] == 'Q')
                return false;
        }

        // Check upper-left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }

        // Check upper-right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q')
                return false;
        }

        // If no conflicts found, position is safe
        return true;
    }

    // Recursive backtracking function to place Queens row by row
    void solve(int row, vector<vector<char>>& board, vector<vector<string>>& ans) {
        int n = board.size();

        // Base case: If all rows are filled, a valid solution is found
        if (row == n) {
            vector<string> temp;
            // Convert the board from vector<char> to vector<string>
            for (auto& r : board) {
                temp.push_back(string(r.begin(), r.end()));
            }
            ans.push_back(temp);
            return;
        }

        // Try placing a Queen in each column of the current row
        for (int col = 0; col < n; col++) {
            // Check if it's safe to place the Queen
            if (isSafe(row, col, board)) {
                // Place the Queen
                board[row][col] = 'Q';
                // Recurse for the next row
                solve(row + 1, board, ans);
                // Backtrack: Remove the Queen for other possibilities
                board[row][col] = '.';
            }
        }
    }

    // Main function to solve the N-Queens problem
    vector<vector<string>> solveNQueens(int n) {
        // This will store all the valid solutions
        vector<vector<string>> ans;

        // Initialize the board with empty cells
        vector<vector<char>> board(n, vector<char>(n, '.'));

        // Start solving from the first row
        solve(0, board, ans);

        // Return all the solutions
        return ans;
    }
};



 Final Time Complexity:

O(n*n!)



S.C= O(n*n)
