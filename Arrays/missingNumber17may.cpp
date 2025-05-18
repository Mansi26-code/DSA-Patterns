// Given an array containing n distinct numbers from the range 0 to n, find the one number that is missing.
// Return the number that does not appear in the array.



// Brute Force Approach: Check for each number from 0 to n if it exists in the array
// Time Complexity: O(n^2) — Outer loop runs n+1 times, inner loop runs up to n times
// Space Complexity: O(1) — No extra space used apart from variables

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumberBrute(vector<int>& nums) {
        int N = nums.size();  // Size of input array is n, meaning elements are from 0 to n

        // Iterate from 0 to N (inclusive) to check for the missing number
        for (int i = 0; i <= N; i++) {
            bool found = false;

            // Linear search to check if i is present in the array
            for (int j = 0; j < N; j++) {
                if (nums[j] == i) {
                    found = true;
                    break;
                }
            }

            // If not found, it's the missing number
            if (!found) return i;
        }

        // Just in case (should never be reached)
        return -1;
    }
};





// Optimal Approach: Use Sum Formula -> Missing = Total Sum - Actual Sum
// Time Complexity: O(n) — One pass to calculate actual sum
// Space Complexity: O(1) — Only variables used, no extra space

class SolutionOptimal {
    public:
        int missingNumber(vector<int>& nums) {
            int n = nums.size();
    
            // Sum of first n natural numbers: 0 to n
            int totalSum = (n * (n + 1)) / 2;
            int actualSum = 0;
    
            // Calculate the sum of all elements in the array
            for (int num : nums) {
                actualSum += num;
            }
    
            // The difference is the missing number
            return totalSum - actualSum;
        }
    };
    