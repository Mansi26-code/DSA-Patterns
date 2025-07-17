class Solution {
    // Directions for top, bottom, right, left movements
    vector<vector<int>> directions = {{-1,0}, {1,0}, {0,1}, {0,-1}};
public:

    // Function to check if the cell (x, y) is within grid boundaries
    bool isSafe(int x, int y, int m, int n) {
        return (x >= 0 && x < m && y >= 0 && y < n);
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();           // number of rows
        int n = grid[0].size();        // number of columns
        int fresh = 0;                 // count of fresh oranges
        int time = 0;                  // max time taken for rot to spread

        queue<pair<pair<int, int>, int>> q;  // ((i, j), time)

        // Step 1: Count fresh oranges and push rotten ones into queue
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0}); // Rotten orange with time = 0
                } else if (grid[i][j] == 1) {
                    fresh++;            // Count fresh oranges
                }
            }
        }

        // Step 2: BFS traversal to rot adjacent fresh oranges
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            int x = front.first.first;
            int y = front.first.second;
            time = front.second;

            for (auto& dir : directions) {
                int new_x = x + dir[0];
                int new_y = y + dir[1];

                // If neighbor is fresh and within bounds
                if (isSafe(new_x, new_y, m, n) && grid[new_x][new_y] == 1) {
                    grid[new_x][new_y] = 2;               // Make it rotten
                    fresh--;                              // Decrease fresh count
                    q.push({{new_x, new_y}, time + 1});   // Push with increased time
                }
            }
        }

        // Step 3: If no fresh oranges left, return time. Else return -1.
        return fresh == 0 ? time : -1;
    }
};

✅ Time Complexity:
O(m × n) — Each cell is visited at most once in BFS.

m = number of rows, n = number of columns.

✅ Space Complexity:
O(m × n) — In worst case, the queue stores all cells.