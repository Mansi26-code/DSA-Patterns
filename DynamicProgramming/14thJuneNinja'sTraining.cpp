class Solution {
public:

    // 🔁 Recursive DP function to calculate max points from day 0 to 'day' with last task as 'last'
    int solve(int day, int last, vector<vector<int>>& arr, vector<vector<int>>& dp) {
        
        // 🧱 Base Case: On day 0, pick the task that is NOT equal to 'last'
        if (day == 0) {
            int maxi = 0;

            for (int task = 0; task < 3; task++) {
                if (task != last) {
                    maxi = max(maxi, arr[0][task]);  // Pick best task not equal to last
                }
            }

            return dp[day][last] = maxi;
        }

        // 🧠 Memoization check
        if (dp[day][last] != -1)
            return dp[day][last];

        int maxi = 0;

        // 🔁 Try all 3 tasks except the one done on the last day
        for (int task = 0; task < 3; task++) {
            if (task != last) {
                int point = arr[day][task] + solve(day - 1, task, arr, dp);
                maxi = max(maxi, point);  // Take max of all possible choices
            }
        }

        return dp[day][last] = maxi;
    }

    int maximumPoints(vector<vector<int>>& arr) {
        int n = arr.size();  // 🔢 Total number of days

        // 🧾 DP array: dp[day][lastTask]
        // lastTask ∈ {0,1,2,3} → 3 means "no task was done yesterday" (used only at start)
        vector<vector<int>> dp(n, vector<int>(4, -1));

        // 🔁 Start from last day, with 'no last task' = 3
        return solve(n - 1, 3, arr, dp);
    }
};


Time Complexity: O(n)

Space Complexity: O(n) (DP array) + O(n) (recursion stack) = O(n)