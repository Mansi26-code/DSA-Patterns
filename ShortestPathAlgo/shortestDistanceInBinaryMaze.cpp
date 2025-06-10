class Solution {
   public:
    vector<vector<int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    bool isSafe(int m, int n, int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        int m = grid.size();
        int n = grid[0].size();

        int x_dest = destination.first;
        int y_dest = destination.second;
        int x_ini = source.first;
        int y_ini = source.second;

        if (grid[x_dest][y_dest] == 0 || grid[x_ini][y_ini] == 0) return -1;

        vector<vector<int>> dist(m, vector<int>(n, 1e9));
        dist[x_ini][y_ini] = 0;

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>, greater<>>
            pq;
        pq.push({0, {x_ini, y_ini}});

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            x_ini = top.second.first;
            y_ini = top.second.second;
            int distance = top.first;

            // ✅ Return when destination is popped (shortest guaranteed)
            if (x_ini == x_dest && y_ini == y_dest) return distance;

            for (auto &dir : directions) {
                int new_x = x_ini + dir[0];
                int new_y = y_ini + dir[1];

                if (isSafe(m, n, new_x, new_y) && grid[new_x][new_y] == 1) {
                    if (dist[x_ini][y_ini] + 1 < dist[new_x][new_y]) {
                        dist[new_x][new_y] = dist[x_ini][y_ini] + 1;
                        pq.push({dist[new_x][new_y], {new_x, new_y}});
                    }
                }
            }
        }

        return -1;  // destination not reachable
    }
};

Time Complexity:The time complexity is O(m*n*log(m*n)) 
Space Complexity:The space complexity is O(m*n)