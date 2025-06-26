// Given an array nums (which may contain duplicates), return all possible subsets (power set).
// Each subset must be unique, meaning no duplicate subsets in the output.


// Time Complexity: O(2^n)
// Space Complexity: O(2^n) (for result) + O(n) (recursion depth)



class Solution {
public:
    // Helper function to recursively generate unique subsets
    void solve(int index, vector<vector<int>>& res, vector<int>& nums, vector<int>& temp) {
        // Push the current subset (can be empty)
        res.push_back(temp);

        // Explore all possible elements to include in the subset
        for (int i = index; i < nums.size(); ++i) {
            // ❌ Skip duplicates at the same recursive level
            if (i > index && nums[i] == nums[i - 1]) continue;

            // ✅ Choose the current element
            temp.push_back(nums[i]);

            // 🔁 Recur for the next elements
            solve(i + 1, res, nums, temp);

            // 🔙 Backtrack
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Sort to bring duplicates together
        vector<vector<int>> res;        // Result container
        vector<int> temp;               // Current subset
        solve(0, res, nums, temp);      // Start recursion
        return res;
    }
};
