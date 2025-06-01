/*
🧩 Problem: Given a square matrix `grid` of size m x n filled with 0s and 1s.
- A cell with 1 means it is traversable (rat can move there),
- A cell with 0 means it is blocked.

📍 Starting point: Top-left cell (0, 0)
📍 Destination: Bottom-right cell (m-1, n-1)

✅ Task:
- Find all possible paths from start to destination **only through cells having value 1**.
- You can move in 4 directions: Down, Left, Right, Up (D, L, R, U)
- Output all paths in the form of strings like: "DRRD", "RRDDLU", etc.

⚠️ Constraints:
- You can visit a cell only **once** in a single path.
- If start or end is blocked (0), return empty list.
*/


class Solution {
public:
    // 🔁 Recursive function to explore all paths from (i,j) to destination
    void solve(int i, int j, int m, int n, string &path,
               vector<vector<int>> &grid, vector<vector<int>> &visited,
               vector<string> &res) {
        
        // ✅ Base condition: If reached destination, save the current path
        if (i == m - 1 && j == n - 1) {
            res.push_back(path);
            return;
        }

        // ✅ Mark current cell as visited
        visited[i][j] = 1;

        // 🔽 1. Move Down (i+1, j)
        if (i + 1 < m && grid[i + 1][j] == 1 && !visited[i + 1][j]) {
            path.push_back('D');                 // add direction to path
            solve(i + 1, j, m, n, path, grid, visited, res);
            path.pop_back();                     // backtrack (remove last direction)
        }

        // ▶️ 2. Move Right (i, j+1)
        if (j + 1 < n && grid[i][j + 1] == 1 && !visited[i][j + 1]) {
            path.push_back('R');
            solve(i, j + 1, m, n, path, grid, visited, res);
            path.pop_back();
        }

        // ◀️ 3. Move Left (i, j-1)
        if (j - 1 >= 0 && grid[i][j - 1] == 1 && !visited[i][j - 1]) {
            path.push_back('L');
            solve(i, j - 1, m, n, path, grid, visited, res);
            path.pop_back();
        }

        // 🔼 4. Move Up (i-1, j)
        if (i - 1 >= 0 && grid[i - 1][j] == 1 && !visited[i - 1][j]) {
            path.push_back('U');
            solve(i - 1, j, m, n, path, grid, visited, res);
            path.pop_back();
        }

        // ⏪ Unmark the cell to allow other paths (Backtracking step)
        visited[i][j] = 0;
    }

    // 🔍 Main function to be called
    vector<string> findPath(vector<vector<int>> &grid) {
        vector<string> res;                         // result to store all paths
        int m = grid.size();                        // number of rows
        int n = grid[0].size();                     // number of columns

        // ⚠️ If starting or ending cell is blocked, return empty
        if (grid[0][0] == 0 || grid[m - 1][n - 1] == 0) {
            return res;
        }

        // 🧭 Create a visited matrix of same size
        vector<vector<int>> visited(m, vector<int>(n, 0));

        string path = ""; // to store the current path

        // 🚀 Start from cell (0, 0)
        solve(0, 0, m, n, path, grid, visited, res);

        // 📦 Return all collected paths
        return res;
    }
};
