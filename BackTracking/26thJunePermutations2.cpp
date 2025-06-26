// Given a list of integers nums that may contain duplicates, return all unique permutations of the array.
// Each number must be used exactly once in each permutation, and the result should not contain duplicates.


class Solution {
public:
    // Recursive function to generate permutations
    void solve(int index, vector<vector<int>>& res, vector<int>& nums) {
        // Base case: If current index reached the end, store the permutation
        if (index == nums.size()) {
            res.push_back(nums);
            return;
        }

        unordered_set<int> used;  // To avoid duplicate swaps at this level

        for (int i = index; i < nums.size(); ++i) {
            // Skip if the number is already used at this level of recursion
            if (used.count(nums[i])) continue;
            used.insert(nums[i]);

            swap(nums[index], nums[i]);                 // Choose
            solve(index + 1, res, nums);                // Explore
            swap(nums[index], nums[i]);                 // Unchoose (Backtrack)
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());  // Sort to make it easier to skip duplicates
        solve(0, res, nums);
        return res;
    }
};

Time Complexity: O(n × n!)
SC: O(n)