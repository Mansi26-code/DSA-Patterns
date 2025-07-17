class Solution {
   public:
    vector<vector<int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    bool isSafe(int new_x, int new_y, int m, int n) {
        return (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int m = image.size();
        int n = image[0].size();
        int originalColor = image[sr][sc];

        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;
        if (originalColor == color) return image;
        while (!q.empty()) {
            auto top = q.front();
            q.pop();
            int x = top.first;
            int y = top.second;

            for (auto& dir : directions) {
                int new_x = x + dir[0];
                int new_y = y + dir[1];

                if (isSafe(new_x, new_y, m, n) &&
                    image[new_x][new_y] == originalColor) {
                    image[new_x][new_y] = color;

                    q.push({new_x, new_y});
                }
            }
        }
        return image;
    }
};

✅ Time Complexity (TC):
O(m × n)


✅ Space Complexity (SC):
O(m × n)