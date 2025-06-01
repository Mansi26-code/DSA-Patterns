// Leetcode Problem 51: N-Queens
// Link: https://leetcode.com/problems/n-queens/

// Time Complexity:O(N! * N^2) due to the recursive calls and the isSafe function's checks in each call.
// Space Complexity:O(N^2) primarily due to storing the board configuration and the auxiliary space used by the recursion stack.



class Solution {
public:
    // Function to check whether placing a queen at (row, col) is safe
    bool isSafe(int &n, int row, int col, vector<string>& board) {
        // Check vertically upwards
        for (int i = row - 1; i >= 0; i--) {
            if (board[i][col] == 'Q') return false;
        }

        // Check diagonally to the upper left
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }

        // Check diagonally to the upper right
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }

    // Backtracking function to try placing queens row by row
    void Queens(vector<string>& board, int row, int &n, vector<vector<string>>& ans) {
        if (row == n) {
            ans.push_back(board); // A valid configuration found
            return;
        }

        // Try placing a queen in every column of the current row
        for (int col = 0; col < n; col++) {
            if (isSafe(n, row, col, board)) {
                board[row][col] = 'Q';              // Place queen
                Queens(board, row + 1, n, ans);      // Move to next row
                board[row][col] = '.';              // Backtrack
            }
        }
    }

    // Main function to be called with input n
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));     // Initialize empty board
        vector<vector<string>> ans;                  // Stores all valid solutions
        Queens(board, 0, n, ans);
        return ans;
    }
};



//count solutions (How many possible configurations possible )

class Solution {
public:
    bool isSafe(int row, int col, vector<string>& board, int n) {
        // Check column
        for (int i = 0; i < row; i++)
            if (board[i][col] == 'Q') return false;

        // Check left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 'Q') return false;

        // Check right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
            if (board[i][j] == 'Q') return false;

        return true;
    }

    void solve(int row, int n, vector<string>& board, int& count) {
        if (row == n) {
            count++;
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                solve(row + 1, n, board, count);
                board[row][col] = '.'; // backtrack
            }
        }
    }

    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        int count = 0;
        solve(0, n, board, count);
        return count;
    }
};


//find only 1 valid configuration

class Solution {
public:
    bool isSafe(int row, int col, vector<string>& board, int n) {
        for (int i = 0; i < row; i++)
            if (board[i][col] == 'Q') return false;
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 'Q') return false;
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
            if (board[i][j] == 'Q') return false;
        return true;
    }

    bool solve(int row, int n, vector<string>& board, vector<string>& result) {
        if (row == n) {
            result = board;
            return true; // Stop after finding one
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                if (solve(row + 1, n, board, result)) return true;
                board[row][col] = '.'; // backtrack
            }
        }
        return false;
    }

    vector<string> oneNQueens(int n) {
        vector<string> board(n, string(n, '.')), result;
        solve(0, n, board, result);
        return result;
    }
};




//what if there is one blocked cell

class Solution {
public:
    bool isSafe(int row, int col, vector<string>& board, int n) {
        if (board[row][col] == 'X') return false; // Blocked cell
        for (int i = 0; i < row; i++)
            if (board[i][col] == 'Q') return false;
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 'Q') return false;
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
            if (board[i][j] == 'Q') return false;
        return true;
    }

    void solve(int row, int n, vector<string>& board, vector<vector<string>>& ans) {
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                solve(row + 1, n, board, ans);
                board[row][col] = '.'; // backtrack
            }
        }
    }

    vector<vector<string>> solveBlockedNQueens(vector<string>& board) {
        int n = board.size();
        vector<vector<string>> ans;
        solve(0, n, board, ans);
        return ans;
    }
};

//K Queens on N x N board

class Solution {
public:
    bool isSafe(int row, int col, vector<string>& board, int n) {
        for (int i = 0; i < row; i++)
            if (board[i][col] == 'Q') return false;
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 'Q') return false;
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
            if (board[i][j] == 'Q') return false;
        return true;
    }

    void solve(int row, int placed, int k, int n, vector<string>& board, vector<vector<string>>& ans) {
        if (placed == k) {
            ans.push_back(board);
            return;
        }
        if (row == n) return;

        for (int col = 0; col < n; col++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                solve(row + 1, placed + 1, k, n, board, ans);
                board[row][col] = '.';
            }
        }

        // Try skipping this row (no queen placed)
        solve(row + 1, placed, k, n, board, ans);
    }

    vector<vector<string>> solveKQueens(int n, int k) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        solve(0, 0, k, n, board, ans);
        return ans;
    }
};
