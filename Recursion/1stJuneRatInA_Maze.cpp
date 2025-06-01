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

//instead of finding the path, if we had to find total ways to reach the destination

// Problem: Count total unique valid paths from (0,0) to (m-1,n-1)

class Solution {
public:
    void solve(int i, int j, int m, int n, vector<vector<int>> &grid,
               vector<vector<int>> &visited, int &count) {

        // Base condition: if destination reached, increment count
        if (i == m - 1 && j == n - 1) {
            count++;
            return;
        }

        // Mark current cell as visited
        visited[i][j] = 1;

        // Explore Up
        if (i - 1 >= 0 && grid[i - 1][j] == 1 && !visited[i - 1][j]) {
            solve(i - 1, j, m, n, grid, visited, count);
        }

        // Explore Down
        if (i + 1 < m && grid[i + 1][j] == 1 && !visited[i + 1][j]) {
            solve(i + 1, j, m, n, grid, visited, count);
        }

        // Explore Left
        if (j - 1 >= 0 && grid[i][j - 1] == 1 && !visited[i][j - 1]) {
            solve(i, j - 1, m, n, grid, visited, count);
        }

        // Explore Right
        if (j + 1 < n && grid[i][j + 1] == 1 && !visited[i][j + 1]) {
            solve(i, j + 1, m, n, grid, visited, count);
        }

        // Backtrack: unmark visited
        visited[i][j] = 0;
    }

    int countPaths(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();

        // If start or end is blocked
        if (grid[0][0] == 0 || grid[m - 1][n - 1] == 0)
            return 0;

        vector<vector<int>> visited(m, vector<int>(n, 0));
        int count = 0;

        solve(0, 0, m, n, grid, visited, count);
        return count;
    }
};
Time Complexity:
In worst case, the rat can explore all 4 directions recursively →
So O(4^(m*n)) in brute-force case (like in a 1-filled grid with no optimization).

Space Complexity:
O(m*n) for the visited matrix + O(path length) recursion stack =
O(m*n) in total.





//Return only those valid paths (from (0,0) to (m-1,n-1)) whose length is minimum among all.

class Solution {
public:
    void solve(int i, int j, int m, int n, string &path,
               vector<vector<int>> &grid, vector<vector<int>> &visited,
               vector<string> &res, int &minLen) {

        // Base case: reached destination
        if (i == m - 1 && j == n - 1) {
            if (path.length() < minLen) {
                res.clear();               // clear older longer paths
                res.push_back(path);       // store current shortest path
                minLen = path.length();    // update min length
            }
            else if (path.length() == minLen) {
                res.push_back(path);       // add path of same shortest length
            }
            return;
        }

        visited[i][j] = 1;

        // Move: U D L R (in any fixed order)
        if (i - 1 >= 0 && grid[i - 1][j] == 1 && !visited[i - 1][j]) {
            path.push_back('U');
            solve(i - 1, j, m, n, path, grid, visited, res, minLen);
            path.pop_back();
        }
        if (i + 1 < m && grid[i + 1][j] == 1 && !visited[i + 1][j]) {
            path.push_back('D');
            solve(i + 1, j, m, n, path, grid, visited, res, minLen);
            path.pop_back();
        }
        if (j - 1 >= 0 && grid[i][j - 1] == 1 && !visited[i][j - 1]) {
            path.push_back('L');
            solve(i, j - 1, m, n, path, grid, visited, res, minLen);
            path.pop_back();
        }
        if (j + 1 < n && grid[i][j + 1] == 1 && !visited[i][j + 1]) {
            path.push_back('R');
            solve(i, j + 1, m, n, path, grid, visited, res, minLen);
            path.pop_back();
        }

        visited[i][j] = 0; // backtrack
    }

    vector<string> findShortestPaths(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<string> res;
        if (grid[0][0] == 0 || grid[m - 1][n - 1] == 0)
            return res;

        vector<vector<int>> visited(m, vector<int>(n, 0));
        string path = "";
        int minLen = INT_MAX;

        solve(0, 0, m, n, path, grid, visited, res, minLen);
        return res;
    }
};



// 🧩 Problem Tweak 3:
// ❓ “You're now allowed to move diagonally towards bottom-right (i+1, j+1). Return all valid paths.”


class Solution {
public:
    void solve(int i, int j, int m, int n, string &path,
               vector<vector<int>> &grid, vector<vector<int>> &visited,
               vector<string> &res) {

        // If reached destination (bottom-right)
        if (i == m - 1 && j == n - 1) {
            res.push_back(path);  // store current path
            return;
        }

        visited[i][j] = 1;

        // Move Up
        if (i - 1 >= 0 && grid[i - 1][j] == 1 && !visited[i - 1][j]) {
            path.push_back('U');
            solve(i - 1, j, m, n, path, grid, visited, res);
            path.pop_back();
        }

        // Move Down
        if (i + 1 < m && grid[i + 1][j] == 1 && !visited[i + 1][j]) {
            path.push_back('D');
            solve(i + 1, j, m, n, path, grid, visited, res);
            path.pop_back();
        }

        // Move Left
        if (j - 1 >= 0 && grid[i][j - 1] == 1 && !visited[i][j - 1]) {
            path.push_back('L');
            solve(i, j - 1, m, n, path, grid, visited, res);
            path.pop_back();
        }

        // Move Right
        if (j + 1 < n && grid[i][j + 1] == 1 && !visited[i][j + 1]) {
            path.push_back('R');
            solve(i, j + 1, m, n, path, grid, visited, res);
            path.pop_back();
        }

        // 🆕 Diagonal Move: Down-Right ↘️
        if (i + 1 < m && j + 1 < n && grid[i + 1][j + 1] == 1 && !visited[i + 1][j + 1]) {
            path.push_back('X'); // 'X' represents diagonal ↘️
            solve(i + 1, j + 1, m, n, path, grid, visited, res);
            path.pop_back();
        }

        visited[i][j] = 0; // backtrack
    }

    vector<string> findPath(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<string> res;
        if (grid[0][0] == 0 || grid[m - 1][n - 1] == 0)
            return res;

        vector<vector<int>> visited(m, vector<int>(n, 0));
        string path = "";

        solve(0, 0, m, n, path, grid, visited, res);
        return res;
    }
};


// 🧩 Problem Tweak 4:
// ❓ “Each cell has a cost. You must find a path from (0,0) to (m-1,n-1) with minimum total cost. Return both the minimum cost and one such path.”


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Direction vectors: Down, Right, Up, Left
    vector<pair<int, char>> dir = {
        {1, 'D'}, {0, 'R'}, {-1, 'U'}, {0, 'L'}
    };

    // Custom comparator for priority_queue (min-heap)
    struct Cell {
        int cost, x, y;
        string path;
        bool operator>(const Cell &other) const {
            return cost > other.cost;
        }
    };

    pair<int, string> minCostPath(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Min cost grid initialized with high values
        vector<vector<int>> minCost(m, vector<int>(n, INT_MAX));
        minCost[0][0] = grid[0][0];

        // Min-heap (priority queue) to pick the cell with the lowest cost
        priority_queue<Cell, vector<Cell>, greater<Cell>> pq;
        pq.push({grid[0][0], 0, 0, ""});

        while (!pq.empty()) {
            Cell curr = pq.top();
            pq.pop();

            int cost = curr.cost;
            int i = curr.x;
            int j = curr.y;
            string path = curr.path;

            // If destination reached
            if (i == m - 1 && j == n - 1)
                return {cost, path};

            // Explore all 4 directions
            vector<pair<int, int>> moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
            vector<char> dirChar = {'D', 'R', 'U', 'L'};

            for (int d = 0; d < 4; d++) {
                int ni = i + moves[d].first;
                int nj = j + moves[d].second;

                // Check bounds
                if (ni >= 0 && nj >= 0 && ni < m && nj < n) {
                    int newCost = cost + grid[ni][nj];
                    if (newCost < minCost[ni][nj]) {
                        minCost[ni][nj] = newCost;
                        pq.push({newCost, ni, nj, path + dirChar[d]});
                    }
                }
            }
        }

        // If no path exists
        return {-1, ""};
    }
};


5. Return lexicographically smallest path
❓ "Return only the lexicographically smallest path among all valid ones?"

Store all paths, then use sort(res.begin(), res.end()) and return res[0].




🧩 Tweak 7: Cycle Detection
❓ "If the grid has cycles and you forget to mark visited properly, what happens? How will you avoid infinite recursion?"

❗️Problem:
In recursive DFS, if we don’t mark cells as visited, or forget to unmark on backtrack, the same cell can be visited repeatedly.

This causes infinite recursion / Time Limit Exceeded (TLE) due to cycles in the graph.

✅ Correct Practice:
✅ Mark visited[i][j] = 1 before exploring neighbors.

✅ After exploring all paths from that cell, backtrack by setting visited[i][j] = 0.

✅ Code With Explanation:
Here’s a working and safe DFS solution with visited matrix handled correctly to prevent cycles.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int i, int j, int m, int n, string &path, vector<vector<int>> &grid,
               vector<vector<int>> &visited, vector<string> &res) {
        
        // Base condition: reached destination
        if (i == m - 1 && j == n - 1) {
            res.push_back(path);
            return;
        }

        // Mark current cell as visited to avoid revisiting
        visited[i][j] = 1;

        // 4 possible directions: D, R, U, L
        vector<pair<int, int>> moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        vector<char> dirs = {'D', 'R', 'U', 'L'};

        for (int k = 0; k < 4; ++k) {
            int ni = i + moves[k].first;
            int nj = j + moves[k].second;

            // Check boundaries and valid move
            if (ni >= 0 && nj >= 0 && ni < m && nj < n && grid[ni][nj] == 1 && visited[ni][nj] == 0) {
                path.push_back(dirs[k]);
                solve(ni, nj, m, n, path, grid, visited, res);
                path.pop_back(); // backtrack
            }
        }

        // ✅ Unmark visited (backtrack step) so that other paths can reuse it
        visited[i][j] = 0;
    }

    vector<string> findPaths(vector<vector<int>> &grid) {
        vector<string> res;
        int m = grid.size(), n = grid[0].size();

        // If start or end is blocked
        if (grid[0][0] == 0 || grid[m-1][n-1] == 0)
            return res;

        vector<vector<int>> visited(m, vector<int>(n, 0));
        string path = "";
        solve(0, 0, m, n, path, grid, visited, res);
        return res;
    }
};
