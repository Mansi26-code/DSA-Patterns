/*
🔹 Problem: Maximum Product Subarray (Leetcode 152)
🔹 Task: Find the contiguous subarray within an array (containing at least one number) that has the largest product.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // ✅ Brute Force Approach
    // Time Complexity: O(N^3)
    // Space Complexity: O(1)
    int maxProductBrute(vector<int>& nums) {
        int result = INT_MIN;
        int n = nums.size();

        // Check every possible subarray using 3 nested loops
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int prod = 1;
                for (int k = i; k <= j; k++) {
                    prod *= nums[k]; // Multiply all elements in subarray nums[i..j]
                }
                result = max(result, prod); // Update max product found so far
            }
        }
        return result;
    }

    // ✅ Better Approach
    // Time Complexity: O(N^2)
    // Space Complexity: O(1)
    int maxProductBetter(vector<int>& nums) {
        int result = nums[0];
        int n = nums.size();

        // Try all subarrays starting at index i
        for (int i = 0; i < n; i++) {
            int prod = nums[i];
            result = max(result, prod); // Update result with single element

            for (int j = i + 1; j < n; j++) {
                prod *= nums[j]; // Multiply current subarray element
                result = max(result, prod); // Update result
            }
        }
        return result;
    }

    // ✅ Optimal Approach (Prefix and Suffix Traversal)
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    int maxProductOptimal(vector<int>& nums) {
        int n = nums.size();
        int prefix = 1, suffix = 1;
        int ans = INT_MIN;

        for (int i = 0; i < n; i++) {
            // Reset prefix/suffix when product becomes zero
            if (prefix == 0) prefix = 1;
            if (suffix == 0) suffix = 1;

            prefix *= nums[i];              // Traverse from left
            suffix *= nums[n - i - 1];      // Traverse from right

            ans = max(ans, max(prefix, suffix)); // Track max of both directions
        }
        return ans;
    }

    // 🔄 Wrapper to switch between versions (choose any to return)
    int maxProduct(vector<int>& nums) {
        // return maxProductBrute(nums);    // O(N^3)
        // return maxProductBetter(nums);   // O(N^2)
        return maxProductOptimal(nums);     // O(N)
    }
};
