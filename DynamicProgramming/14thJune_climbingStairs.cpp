class Solution {
public:
    int climbStairs(int n) {
        // Step 1: Create a DP array of size (n+1) to store number of ways to reach each step
        // dp[i] will represent the number of distinct ways to reach step i
        vector<int> dp(n + 1, 0);

        // Step 2: Base Cases
        // There's only 1 way to stay at the ground (step 0) - do nothing
        dp[0] = 1;

        // There's only 1 way to reach step 1 - by taking a single step
        dp[1] = 1;

        // Step 3: Fill the dp array using bottom-up approach
        // For each step i from 2 to n:
        // You can reach step i either from step (i-1) by taking 1 step,
        // or from step (i-2) by taking 2 steps.
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
            // dp[i-1]: number of ways to reach (i-1)
            // dp[i-2]: number of ways to reach (i-2)
            // Add both to get total ways to reach step i
        }

        // Step 4: Return the total number of ways to reach step n
        return dp[n];
    }
};



//TC & SC=O(n)