
// 🔢 Problem: Power Set

// Given an array nums of unique integers, return all possible subsets (also known as the power set).

// ⚠️ The result should not contain duplicate subsets.



🧠 Time Complexity: O(2^n), where n = size of nums
🧠 Space Complexity: O(2^n * k), where k is the average subset length
(Each element has 2 choices → total subsets = 2ⁿ)


class Solution {
public:
    // Recursive function to generate subsets
    void solve(int index, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans) {
        // Base Case: We've reached the end of the array
        if (index == nums.size()) {
            ans.push_back(temp);  // Store the current subset
            return;
        }

        // ✅ Include the current element
        temp.push_back(nums[index]);
        solve(index + 1, nums, temp, ans);  // Move to next index
        temp.pop_back();  // Backtrack

        // ❌ Exclude the current element
        solve(index + 1, nums, temp, ans);
    }

    // Function to return all subsets (power set)
    vector<vector<int>> powerSet(vector<int>& nums) {
        vector<int> temp;               // Temporary subset
        vector<vector<int>> ans;        // Result to store all subsets
        solve(0, nums, temp, ans);      // Start recursion from index 0
        return ans;
    }
};
