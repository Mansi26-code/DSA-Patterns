class Solution {
   public:
    int count(vector<int>& coins, int N, int amount) {
        int mod = 1e9 + 7;
        vector<vector<int>> dp(N + 1, vector<int>(amount + 1, 0));
        for (int i = 0; i <= N; i++) {
            dp[i][0] = 1;  // 0 amount ke liye we need 0 coins
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= amount; j++) {
                dp[i][j] = dp[i - 1][j];

                if (coins[i - 1] <= j && dp[i][j - coins[i - 1]] != INT_MAX) {
                    dp[i][j] = (dp[i][j - coins[i - 1]] + dp[i][j]) % mod;
                }
            }
        }
        return dp[N][amount] == INT_MAX ? 0 : dp[N][amount];
    }
};



//TC & SC= O(N * amount)