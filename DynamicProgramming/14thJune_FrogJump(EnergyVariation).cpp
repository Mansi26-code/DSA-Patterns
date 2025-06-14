class Solution {
public:
    int frogJump(vector<int>& heights) {
        int n = heights.size(); // Total number of steps

        // Step 1: Create a DP array of size n
        // dp[i] represents the minimum energy required to reach step i
        vector<int> dp(n, 0);

        // Step 2: Base Case
        // Frog is already on step 0, so 0 energy is required
        dp[0] = 0;

        // Step 3: For step 1, frog jumps from step 0
        // So energy = absolute difference in heights between step 1 and step 0
        dp[1] = abs(heights[1] - heights[0]);

        // Step 4: Iterate from step 2 to n-1 to fill the dp array
        for (int i = 2; i < n; i++) {
            // Option 1: Jump from step (i-1) to i (1 step jump)
            int oneStep = dp[i - 1] + abs(heights[i] - heights[i - 1]);

            // Option 2: Jump from step (i-2) to i (2 steps jump)
            int twoSteps = dp[i - 2] + abs(heights[i] - heights[i - 2]);

            // Choose the minimum energy path
            dp[i] = min(oneStep, twoSteps);
        }

        // Step 5: Return the minimum energy required to reach the last step
        return dp[n - 1];
    }
};


//SC & TC= O(n)