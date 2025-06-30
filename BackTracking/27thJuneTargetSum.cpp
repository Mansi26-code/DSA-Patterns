#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int targetSum(int n, int target, vector<int>& nums) {
        const int mod = 1e9 + 7;
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        // If target is out of possible sum range or invalid parity, return 0
        if (abs(target) > totalSum || (target + totalSum) % 2 != 0)
            return 0;

        // Convert to subset sum problem: find subsets summing to this value
        int subsetSum = (target + totalSum) / 2;

        // dp[i][j] = number of ways to pick first i elements to get sum j
        vector<vector<int>> dp(n + 1, vector<int>(subsetSum + 1, 0));

        // Base case: one way to make sum 0 (select no elements)
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= subsetSum; j++) {
                // Not take current element
                dp[i][j] = dp[i - 1][j];

                // Take current element if it fits
                if (nums[i - 1] <= j) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - nums[i - 1]]) % mod;
                }
            }
        }

        return dp[n][subsetSum];
    }
};


✅ Explanation
Why we convert to subset sum?

We are assigning + and - signs. This is equivalent to partitioning the array into two subsets:

Subset S1: elements with + sign

Subset S2: elements with - sign

We want:

sum(S1) - sum(S2) = target

And since:

sum(S1) + sum(S2) = totalSum

Adding the equations:

2 * sum(S1) = target + totalSum

So:

sum(S1) = (target + totalSum) / 2

Hence the problem reduces to count the number of subsets with sum = subsetSum.


