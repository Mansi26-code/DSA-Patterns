/*
🔸 Problem: Max Consecutive Ones II

Given a binary array `nums`, you can flip **at most one 0** to 1. Return the maximum number of consecutive 1s in the array after performing at most one flip.

Example:
Input: nums = [1,0,1,1,0]
Output: 4
Explanation: Flip the first 0 to get [1,1,1,1,0] or flip second 0 to get [1,0,1,1,1], longest streak = 4.
*/

// --------------------------------------------------------
// 🔹 Brute Force Approach (O(n^2))
// --------------------------------------------------------

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxLen = 0;
        int n = nums.size();

        // Try starting from each index
        for (int i = 0; i < n; i++) {
            int len = 0;
            int limit = 1;  // At most one 0 can be flipped

            for (int j = i; j < n; j++) {
                if (nums[j] == 1) {
                    len++;
                }
                else if (nums[j] == 0 && limit > 0) {
                    len++;
                    limit--;
                }
                else {
                    break;  // Can't flip more than one 0
                }

                maxLen = max(maxLen, len);
            }
        }

        return maxLen;
    }
};

/*
🕒 Time Complexity: O(n^2)
🧠 Space Complexity: O(1)
*/

// --------------------------------------------------------
// 🔹 Optimized Sliding Window Approach (O(n))
// --------------------------------------------------------

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int left = 0;
        int maxLen = 0;
        int limit = 1;  // Allow at most one 0 in the window

        for (int right = 0; right < nums.size(); right++) {
            // If we hit a zero, reduce our flip allowance
            if (nums[right] == 0) {
                limit--;
            }

            // If we’ve used more than 1 flip, shrink the window from the left
            while (limit < 0) {
                if (nums[left] == 0) {
                    limit++;
                }
                left++;
            }

            // Calculate current valid window length
            int len = right - left + 1;
            maxLen = max(maxLen, len);
        }

        return maxLen;
    }
};

/*
🕒 Time Complexity: O(n)
🧠 Space Complexity: O(1)
*/
