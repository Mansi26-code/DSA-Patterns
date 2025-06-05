class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();         // Rows
        int n = mat[0].size();      // Columns

        // Queue for BFS
        queue<pair<int, int>> q;

        // Directions: down, right, up, left
        vector<vector<int>> direction = {{1,0}, {0,1}, {-1,0}, {0,-1}};

        // Result matrix initialized with -1 (unvisited)
        vector<vector<int>> res(m, vector<int>(n, -1));

        // Step 1: Push all '0's into the queue and mark their distance as 0
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    res[i][j] = 0;        // Distance of 0 from itself
                    q.push({i, j});       // Push position of 0 to BFS queue
                }
            }
        }

        // Step 2: BFS from all 0s
        while (!q.empty()) {
            auto top = q.front();   // Get current cell
            q.pop();

            int x = top.first;
            int y = top.second;

            // Visit all 4 directions
            for (auto &dir : direction) {
                int new_x = x + dir[0];
                int new_y = y + dir[1];

                // If the new cell is inside bounds and not visited yet
                if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && res[new_x][new_y] == -1) {
                    res[new_x][new_y] = 1 + res[x][y];   // Distance = parent's distance + 1
                    q.push({new_x, new_y});              // Push new cell into queue
                }
            }
        }

        // Final result matrix with distances to nearest 0
        return res;
    }
};


✅ Time Complexity: O(m * n)
✅ Space Complexity: O(m * n)

