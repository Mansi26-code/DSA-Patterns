class Solution {
public:
    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();

        // Step 1: dp[i] will store the minimum energy required to reach step i
        vector<int> dp(n, 0);

        // Step 2: Iterate from the 1st step to the last
        for (int i = 1; i < n; i++) {
            int minEnergy = INT_MAX;

            // Step 3: Try all possible jumps from i-1 to i-k
            for (int j = 1; j <= k; j++) {
                if (i - j >= 0) {
                    int jumpEnergy = dp[i - j] + abs(heights[i] - heights[i - j]);
                    minEnergy = min(minEnergy, jumpEnergy);
                }
            }

            // Step 4: Store the minimum energy to reach step i
            dp[i] = minEnergy;
        }

        // Step 5: Return energy to reach the last step
        return dp[n - 1];
    }
};


//TC=O(n*k)
//SC=O(n)

