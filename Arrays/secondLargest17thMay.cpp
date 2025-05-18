#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // ✅ Brute Force Approach: Sort the array and find second largest
    // Time Complexity: O(n log n) due to sorting
    // Space Complexity: O(1)
    int secondLargest_Brute(vector<int>& nums) {
        int n = nums.size();

        if (n < 2) return -1; // Edge case: no second largest possible

        sort(nums.begin(), nums.end()); // Sort in ascending order

        int largest = nums[n - 1]; // Last element is largest

        // Traverse from second last to find second largest
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] != largest)
                return nums[i];
        }

        return -1; // All elements are the same
    }

    // ✅ Better Approach: Two passes without sorting
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    int secondLargest_Better(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return -1;

        int largest = INT_MIN;
        int secondLargest = INT_MIN;

        // First pass to find largest
        for (int i = 0; i < n; i++) {
            largest = max(largest, nums[i]);
        }

        // Second pass to find second largest
        for (int i = 0; i < n; i++) {
            if (nums[i] != largest) {
                secondLargest = max(secondLargest, nums[i]);
            }
        }

        return (secondLargest == INT_MIN) ? -1 : secondLargest;
    }

    // ✅ Optimal Approach: Single pass, constant space
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    int secondLargest_Optimal(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return -1;

        int largest = INT_MIN;
        int secondLargest = INT_MIN;

        for (int i = 0; i < n; i++) {
            if (nums[i] > largest) {
                secondLargest = largest;
                largest = nums[i];
            } else if (nums[i] > secondLargest && nums[i] != largest) {
                secondLargest = nums[i];
            }
        }

        return (secondLargest == INT_MIN) ? -1 : secondLargest;
    }
};


