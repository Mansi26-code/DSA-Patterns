class Solution {
   public:
    int effort;
    vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    bool isSafe(int m, int n, int x, int y) c xc {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    int MinimumEffort(vector<vector<int>> &heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> dist(m, vector<int>(n, 1e9));
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>, greater<>>
            pq;

        pq.push({0, {0, 0}});
        dist[0][0] = 0;

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            effort = top.first;
            int x = top.second.first;
            int y = top.second.second;

            if (x == m - 1 && y == n - 1) return effort;

            for (auto &dir : directions) {
                int new_x = x + dir[0];
                int new_y = y + dir[1];

                if (isSafe(m, n, new_x, new_y)) {
                    int newEffort =
                        max(abs(heights[x][y] - heights[new_x][new_y]), effort);
                    if (newEffort < dist[new_x][new_y]) {
                        dist[new_x][new_y] = newEffort;
                        pq.push({newEffort, {new_x, new_y}});
                    }
                }
            }
        }
        return effort;
    }
};

Time Complexity:O(m*n*log(m*n)) due to the priority queue operations, where m and n are the dimensions of the heights matrix.
Space Complexity:O(m*n) to store the distance matrix dist and the priority queue can potentially hold all cells of the matrix in the worst case.

