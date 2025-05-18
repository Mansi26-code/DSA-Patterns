// ✅ Problem: Longest Consecutive Sequence
// 🔹 Goal: Find the length of the longest sequence of consecutive integers in an unsorted array

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Helper function to perform linear search
    bool linearSearch(vector<int>& a, int num) {
        int n = a.size(); 
        for (int i = 0; i < n; i++) {
            if (a[i] == num)
                return true;
        }
        return false;
    }

public:
    // ✅ Approach 1: Brute Force using Linear Search
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int n = nums.size();
        int longest = 1; 

        // Check for every number if it can be the start of a sequence
        for (int i = 0; i < n; i++) {
            int x = nums[i]; 
            int cnt = 1; 

            // Try to extend the sequence starting from x
            while (linearSearch(nums, x + 1) == true) {
                x += 1; 
                cnt += 1; 
            }

            longest = max(longest, cnt);
        }
        return longest;
    }
};

/*
🔍 Time Complexity: O(N^2) in worst case due to linear search inside loop
🧠 Space Complexity: O(1), no extra space used except variables
*/


// ✅ Approach 2: Better Approach using Sorting
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        sort(nums.begin(), nums.end());  // Sort the array

        int maxLen = 1;   // Stores the maximum length found
        int len = 1;      // Stores the current consecutive sequence length

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) 
                continue; // Skip duplicate elements

            if (nums[i] - nums[i - 1] == 1) {
                len++; // Sequence continues
            } else {
                len = 1; // Sequence breaks, reset length
            }
            maxLen = max(maxLen, len); // Update max if needed
        }
        return maxLen;
    }
};

/*
🔍 Time Complexity: O(N log N) due to sorting
🧠 Space Complexity: O(1) if in-place sorting is considered
*/

