// ✅ OPTIMAL APPROACH — Using Sliding Window (only works when elements are non-negative, e.g., 0s and 1s)
class Solution {
public:

    // Helper function to count subarrays with sum less than or equal to given goal
    int solve(vector<int>& nums, int goal) {
        int left = 0;      // Left pointer of the sliding window
        int count = 0;     // To store the total number of valid subarrays
        int sum = 0;       // Current sum of the window
        int n = nums.size();
        int right = 0;     // Right pointer of the sliding window

        // If goal is negative, it's impossible to get such a subarray with non-negative values
        if (goal < 0) return 0;

        // Iterate over the array using the right pointer
        while (right < n) {
            sum += nums[right];  // Add current element to the window

            // Shrink the window from the left if the sum exceeds the goal
            while (sum > goal) {
                sum -= nums[left];
                left++;
            }

            // All subarrays ending at `right` and starting from `left` to `right` are valid
            count += right - left + 1;

            // Move the right pointer forward
            right++;
        }

        return count;
    }

    // Main function to count the number of subarrays with exact sum equal to 'goal'
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // Count of subarrays with sum exactly equal to 'goal'
        // = count of subarrays with sum ≤ goal - count of subarrays with sum ≤ goal-1
        return solve(nums, goal) - solve(nums, goal - 1);
    }
};

/*
🧠 Time Complexity: O(n), where n is the size of the array
    - Each element is processed at most twice (once by `right`, once by `left`)
🧠 Space Complexity: O(1)
    - Uses constant extra space
*/



// ❌ BRUTE FORCE APPROACH — Check all subarrays using two nested loops
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count = 0;           // To store number of valid subarrays
        int n = nums.size();

        // Loop through all possible starting points
        for (int i = 0; i < n; i++) {
            int sum = 0;

            // Loop through all possible ending points for subarrays starting at i
            for (int j = i; j < n; j++) {
                sum += nums[j];

                // If the sum of current subarray equals the goal, increment count
                if (sum == goal) {
                    count++;
                }
            }
        }

        return count;
    }
};

/*
🧠 Time Complexity: O(n^2), where n is the size of the array
    - Each subarray is checked individually
🧠 Space Complexity: O(1)
    - No extra space used besides simple variables
*/
