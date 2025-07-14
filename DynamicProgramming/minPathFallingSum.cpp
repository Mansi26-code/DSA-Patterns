class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int left = (j > 0) ? dp[i - 1][j - 1] : INT_MAX;
                int right = (j < n - 1) ? dp[i - 1][j + 1] : INT_MAX;
                int down = dp[i - 1][j];

                dp[i][j] = matrix[i][j] + min({left, right, down});
            }
        }
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};