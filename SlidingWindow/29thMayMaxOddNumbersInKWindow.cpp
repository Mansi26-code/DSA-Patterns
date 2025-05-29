// Time Complexity: O(n)
// Space Complexity: O(1)
// Sliding window approach

class Solution {
public:
    int maxOddinKSizeWindow(vector<int>& nums, int k) {
        int count = 0;       // count of odd numbers in current window
        int maxCount = 0;    // stores the maximum count of odd numbers
        int left = 0;        // left pointer for sliding window

        // Traverse the array with right pointer
        for (int right = 0; right < nums.size(); right++) {

            // If current number is odd, increase count
            if (nums[right] % 2 != 0)
                count++;

            // If window size exceeds k, shrink from the left
            if (right - left + 1 > k) {
                if (nums[left] % 2 != 0)
                    count--; // decrease count if outgoing element was odd
                left++;
            }

            // When window size is exactly k, check for maxCount
            if (right - left + 1 == k) {
                maxCount = max(maxCount, count);
            }
        }

        return maxCount;
    }
};
