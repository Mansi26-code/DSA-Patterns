class Solution {
public:
    // Helper function to count subarrays with at most k odd numbers
    int countAtMostKOdd(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int count = 0;      // To count odd numbers in the current window
        int total = 0;      // To store total valid subarrays

        for (right = 0; right < nums.size(); right++) {
            // If current number is odd, increment the count of odds in window
            if (nums[right] % 2 != 0) {
                count++;
            }

            // If the count exceeds k, move the left pointer to shrink the window
            while (count > k) {
                if (nums[left] % 2 != 0) {
                    count--;
                }
                left++;
            }

            // All subarrays ending at 'right' and starting from 'left' to 'right' are valid
            total += right - left + 1;
        }

        return total;
    }

    // Main function to count subarrays with exactly k odd numbers
    int numberOfOddSubarrays(vector<int>& nums, int k) {
        // Subarrays with exactly k odd numbers =
        // Subarrays with at most k odd numbers - Subarrays with at most (k - 1) odd numbers
        return countAtMostKOdd(nums, k) - countAtMostKOdd(nums, k - 1);
    }
};
