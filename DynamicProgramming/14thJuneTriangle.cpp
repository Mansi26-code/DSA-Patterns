class Solution {
public:
    int minTriangleSum(vector<vector<int>>& triangle) {
        int m = triangle.size();  // number of rows in the triangle

        // Step 1: Create a DP table with default values as INT_MAX
        // dp[i][j] will store the minimum path sum to reach triangle[i][j]
        vector<vector<int>> dp(m, vector<int>(m, INT_MAX));

        // Base case: The top of the triangle is the starting point
        dp[0][0] = triangle[0][0];

        // Step 2: Fill the DP table
        for (int i = 1; i < m; i++) {
            for (int j = 0; j <= i; j++) {
                // 🟩 If we are at the first element in the row,
                // we can only come from directly above
                if (j == 0) {
                    dp[i][j] = dp[i - 1][j] + triangle[i][j];
                }

                // 🟩 If we are at the last element in the row,
                // we can only come from the top-left (diagonal)
                else if (j == i) {
                    dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
                }

                // 🟩 For all other elements, we can come from either top or top-left
                else {
                    dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
                }
            }
        }

        // Step 3: Minimum path sum will be the minimum value in the last row
        return *min_element(dp[m - 1].begin(), dp[m - 1].end());
    }
};


//TC & SC = O(m^2)