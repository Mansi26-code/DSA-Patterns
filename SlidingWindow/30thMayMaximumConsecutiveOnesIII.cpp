// Given a binary array nums and an integer k, return the maximum number of consecutive 1s in the array if you can flip at most k 0s.


class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // Initialize left pointer for the window, max length, and count of 1s in the window
        int left = 0, maxLen = 0, countOnes = 0;
       
        // Iterate through the array using right pointer
        for(int right = 0; right < nums.size(); right++) {
            // If current element is 1, increment count of 1s
            countOnes += nums[right];

            // If number of 0s in the current window exceeds k, shrink the window from the left
            // (total elements in window - number of 1s = number of 0s)
            while ((right - left + 1) - countOnes > k) {
                // If the element at left is 1, decrement countOnes since we are removing it from window
                if(nums[left] == 1) {
                    countOnes--;
                }
                // Move the left pointer to shrink the window
                left++;
            }

            // Update maxLen with the size of the current valid window
            maxLen = max(maxLen, right - left + 1);
        }

        // Return the maximum length found
        return maxLen;
    }
};
