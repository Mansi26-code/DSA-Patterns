class Solution {
public:

    // Helper function to explore all paths recursively
    void solve(int n, int i, int j, vector<vector<int>> &grid, vector<vector<int>> &visited,
               string &path, vector<string> &result) {
        
        // Base case: destination reached
        if (i == n - 1 && j == n - 1) {
            result.push_back(path);
            return;
        }

        // Mark current cell as visited
        visited[i][j] = 1;

        // Move in all 4 directions: U, D, L, R
        // UP
        if (i - 1 >= 0 && grid[i - 1][j] == 1 && !visited[i - 1][j]) {
            path.push_back('U');
            solve(n, i - 1, j, grid, visited, path, result);
            path.pop_back(); // Backtrack
        }
        // DOWN
        if (i + 1 < n && grid[i + 1][j] == 1 && !visited[i + 1][j]) {
            path.push_back('D');
            solve(n, i + 1, j, grid, visited, path, result);
            path.pop_back();
        }
        // LEFT
        if (j - 1 >= 0 && grid[i][j - 1] == 1 && !visited[i][j - 1]) {
            path.push_back('L');
            solve(n, i, j - 1, grid, visited, path, result);
            path.pop_back();
        }
        // RIGHT
        if (j + 1 < n && grid[i][j + 1] == 1 && !visited[i][j + 1]) {
            path.push_back('R');
            solve(n, i, j + 1, grid, visited, path, result);
            path.pop_back();
        }

        // Unmark current cell during backtracking
        visited[i][j] = 0;
    }

    // Main function
    vector<string> findPath(vector<vector<int>> &grid) {
        int n = grid.size();
        vector<string> result;

        // If start or end is blocked
        if (grid[0][0] == 0 || grid[n - 1][n - 1] == 0) {
            return result;
        }

        vector<vector<int>> visited(n, vector<int>(n, 0));
        string path;

        // Start solving from (0,0)
        solve(n, 0, 0, grid, visited, path, result);

        // If no path found, return -1 as per problem statement
        if (result.empty()) {
            result.push_back("-1");
        }

        return result;
    }
};
