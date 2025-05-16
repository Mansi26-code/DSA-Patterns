// Given an array consisting of only 0, 1, and 2, sort the array in-place without using any extra space.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // ✅ Approach 1: Count Zeros and Ones using In-place Swaps (Two-Pass)
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    void sortZeroOneTwo_CountSwap(vector<int>& nums) {
        int zeros = 0;

        // 🔹 First pass: Move all 0s to the front
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                swap(nums[i], nums[zeros]);
                zeros++;
            }
        }

        int ones = zeros;

        // 🔹 Second pass: Move all 1s after 0s
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                swap(nums[i], nums[ones]);
                ones++;
            }
        }
    }

    // ✅ Approach 2: Dutch National Flag Algorithm (Optimal - One Pass)
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    void sortZeroOneTwo_DNF(vector<int>& nums) {
        int low = 0, mid = 0;
        int high = nums.size() - 1;

        // Traverse and sort the array in one pass
        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else { // nums[mid] == 2
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }

    // ✅ Approach 3: Simple Sorting (Built-in sort) — Not In-place Logic
    // Time Complexity: O(n log n)
    // Space Complexity: O(1) extra (but not constant in sorting internals)
    void sortZeroOneTwo_Sort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    }
};
