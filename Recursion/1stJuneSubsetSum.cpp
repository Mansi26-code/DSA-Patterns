/**
🧩 Problem: Subsets I – Return Sum of All Subsets

Given an array nums of n integers, return the sum of every possible subset of the array. The output should contain all possible subset sums.

📌 Examples:
Input: nums = [2, 3]
Output: [0, 3, 2, 5]
(Explanation: {}, {3}, {2}, {2,3})

Input: nums = [5, 2, 1]
Output: [0, 1, 2, 3, 5, 6, 7, 8]
(Explanation: All combinations of subsets and their sums)

🛠 Approach:
We use backtracking/recursion to explore each possibility of taking or skipping every element from the array.
At each index, we have two choices:

Include the element in the current sum.

Exclude it and move on.

When we reach the end of the array, we record the current sum.

🧠 Time Complexity: O(2^n)
🧠 Space Complexity: O(2^n) (to store all subset sums)

*/

class Solution {
public:
    // Helper recursive function to explore all subsets
    void solve(vector<int>& nums, int i, int sum, vector<int>& res) {
        // Base case: if we've considered all elements
        if (i == nums.size()) {
            res.push_back(sum); // store the current subset sum
            return;
        }

        // ✅ Include the current element in the subset
        solve(nums, i + 1, sum + nums[i], res);

        // ❌ Exclude the current element from the subset
        solve(nums, i + 1, sum, res);
    }

    vector<int> subsetSums(vector<int>& nums) {
        vector<int> res; // to store all subset sums
        solve(nums, 0, 0, res); // start recursion
        return res;
    }
};
c