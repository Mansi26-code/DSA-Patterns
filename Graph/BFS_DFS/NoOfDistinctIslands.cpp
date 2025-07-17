class Solution {
   public:
    vector<vector<int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    void dfs(int row, int col, vector<vector<int>> &grid,
             vector<vector<int>> &vis, vector<pair<int, int>> &shape,
             int baseRow, int baseCol) {
        int m = grid.size();
        int n = grid[0].size();
        vis[row][col] = 1;
        shape.push_back({row - baseRow, col - baseCol});

        for (auto &dir : directions) {
            int newRow = row + dir[0];
            int newCol = col + dir[1];

            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n &&
                !vis[newRow][newCol] && grid[newRow][newCol] == 1) {
                dfs(newRow, newCol, grid, vis, shape, baseRow, baseCol);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        set<vector<pair<int, int>>> uniqueIslands;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    vector<pair<int, int>> shape;
                    dfs(i, j, grid, vis, shape, i, j);
                    uniqueIslands.insert(shape);
                }
            }
        }
        return uniqueIslands.size();
    }
};


Time Complexity:O(m*n) 

Space Complexity:O(m*n) 