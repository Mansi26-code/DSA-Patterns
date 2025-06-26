// Given an array nums of distinct integers, generate and return all possible permutations of the array using backtracking.
// Every number must appear exactly once in each permutation.



// Leetcode 46: Permutations
// Problem Link: https://leetcode.com/problems/permutations/

class Solution {
public:
    // Backtracking helper function to generate all permutations
    void solve(int index, vector<vector<int>>& res, vector<int>& nums) {
        // Base case: If index reaches end, current permutation is complete
        if(index == nums.size()) {
            res.push_back(nums);
            return;
        }

        // Try swapping each element with the current index to generate permutations
        for(int i = index; i < nums.size(); i++) {
            swap(nums[index], nums[i]);               // Choose
            solve(index + 1, res, nums);              // Explore
            swap(nums[index], nums[i]);               // Backtrack
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;                      // Stores all permutations
        solve(0, res, nums);                          // Begin backtracking from index 0
        return res;
    }
};
