//Given an array nums of size n containing numbers from 1 to n. One number is repeated and one is missing. Find both.

// Time Complexity: O(n^2)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find repeating and missing numbers
    vector<int> findMissingRepeatingNumbers(vector<int>& nums) {
        int n = nums.size();
        int repeating = -1, missing = -1;

        // Check for each number from 1 to n
        for (int i = 1; i <= n; i++) {
            int cnt = 0;

            // Count occurrences of number i in the array
            for (int j = 0; j < n; j++) {
                if (nums[j] == i) cnt++;
            }

            if (cnt == 2) repeating = i;
            else if (cnt == 0) missing = i;

            // Break early if both are found
            if (repeating != -1 && missing != -1) break;
        }

        return {repeating, missing};
    }
};



// Time Complexity: O(n)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find repeating and missing numbers
    vector<int> findMissingRepeatingNumbers(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        vector<int> ans(2); // [repeating, missing]

        // Count frequency of each number
        for (int num : nums) {
            freq[num]++;
        }

        // Check for missing and repeating
        for (int i = 1; i <= n; ++i) {
            if (freq[i] == 0) {
                ans[1] = i; // Missing number
            } else if (freq[i] > 1) {
                ans[0] = i; // Repeating number
            }
        }

        return ans;
    }
};






// Time Complexity: O(n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find repeating and missing numbers using XOR
    vector<int> findMissingRepeatingNumbers(vector<int>& nums) {
        int n = nums.size();
        int xr = 0;

        // XOR all elements in the array and numbers from 1 to n
        for (int i = 0; i < n; i++) {
            xr ^= nums[i];
            xr ^= (i + 1);
        }

        // Find the rightmost set bit (used to separate two groups)
        int bit = xr & ~(xr - 1);

        int zero = 0, one = 0;

        // Divide elements into two groups and XOR separately
        for (int i = 0; i < n; i++) {
            if (nums[i] & bit)
                one ^= nums[i];
            else
                zero ^= nums[i];
        }

        for (int i = 1; i <= n; i++) {
            if (i & bit)
                one ^= i;
            else
                zero ^= i;
        }

        // Determine which is missing and which is repeating
        int cnt = count(nums.begin(), nums.end(), zero);
        if (cnt == 2) {
            return {zero, one}; // zero is repeating, one is missing
        } else {
            return {one, zero}; // one is repeating, zero is missing
        }
    }
};
