#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int countPartitions(int n, int diff, vector<int>& arr) {
        int total = accumulate(arr.begin(), arr.end(), 0);
        int target = (total + diff) / 2;
        int mod = 1e9 + 7;
        if ((total + diff) % 2 != 0 || total < diff) return 0;
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

        // dp[i][0]=true;
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                if (arr[i - 1] <= j) {
                    dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - arr[i - 1]]) % mod;
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][target];
    }
};

//TC & SC=O(n*target)