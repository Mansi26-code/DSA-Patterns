/**
 * @file WordSearch.cpp
 * @brief Leetcode 79 - Word Search problem using backtracking with path pruning.
 * 
 * Given a 2D board and a word, check if the word exists in the grid by forming a path through adjacent cells.
 */

class Solution {
public:
    // 4 possible directions: up, down, left, right
    vector<vector<int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};

    /**
     * @brief Recursive function to perform backtracking search.
     * @param i Current row index
     * @param j Current column index
     * @param m Total rows
     * @param n Total columns
     * @param board The 2D character board
     * @param temp The current constructed string
     * @param word The target word to search
     * @param visited 2D matrix to track visited cells
     * @return true if the word is found, false otherwise
     */
    bool solve(int i, int j, int m, int n, vector<vector<char>>& board, string& temp, string& word, vector<vector<bool>>& visited) {
        // If current constructed string matches the word
        if (temp == word) {
            return true;
        }

        // Prune paths where current length already exceeds word
        if (temp.size() > word.size()) {
            return false;
        }

        // Mark current cell as visited
        visited[i][j] = true;

        // Explore all 4 directions
        for (auto& dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            // Check for bounds and if the next cell is not visited
            if (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && !visited[new_i][new_j]) {
                temp.push_back(board[new_i][new_j]);

                // Early pruning: proceed only if temp is still a valid prefix
                if (word.substr(0, temp.size()) == temp) {
                    if (solve(new_i, new_j, m, n, board, temp, word, visited))
                        return true;
                }

                // Backtrack
                temp.pop_back();
            }
        }

        // Unmark current cell before backtracking
        visited[i][j] = false;
        return false;
    }

    /**
     * @brief Main function to check if the word exists in the board.
     * @param board The 2D board of characters
     * @param word The word to search for
     * @return true if word exists, false otherwise
     */
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Try to start from every cell that matches the first character
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    string temp;
                    temp.push_back(board[i][j]);

                    if (solve(i, j, m, n, board, temp, word, visited))
                        return true;
                }
            }
        }
        return false;
    }
};


//SC & TC= O(m*n)