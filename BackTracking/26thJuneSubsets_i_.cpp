
// Given an array of integers nums, find the sum of all possible subsets of the array.
// A subset can be empty, and output all subset sums in any order.

class Solution {
public:
    // Recursive function to generate all subset sums
    void solve(int index, vector<int>& res, vector<int>& nums, int currentSum) {
        // ✅ Base case: if we have considered all elements
        if (index == nums.size()) {
            res.push_back(currentSum); // store the sum of this subset
            return;
        }

        // 🔁 Choice 1: Exclude current element
        solve(index + 1, res, nums, currentSum);

        // 🔁 Choice 2: Include current element
        solve(index + 1, res, nums, currentSum + nums[index]);
    }

    vector<int> subsetSums(vector<int>& nums) {
        vector<int> res;  // stores all subset sums
        solve(0, res, nums, 0);  // start recursion from index 0 and sum = 0
        return res;
    }
};


// Time Complexity: O(2^n)
// Space Complexity: O(2^n) (for storing all subset sums)