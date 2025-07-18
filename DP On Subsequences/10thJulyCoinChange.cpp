class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, INT_MAX));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0; // 0 amount ke liye we need 0 coins
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                dp[i][j] = dp[i - 1][j];

                if (coins[i - 1] <= j && dp[i][j - coins[i - 1]] != INT_MAX) {
                    dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i][j]);
                }
            }
        }
        return dp[n][amount] == INT_MAX ? -1 : dp[n][amount];
    }
};

//TC & SC= O(n*amount)
