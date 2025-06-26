// You are given an array of unique integers (candidates) and a target value.
// Find all unique combinations where the chosen numbers sum to the target. Each number can be used unlimited times.


class Solution {
public:

    // Recursive helper function to explore all combinations
    void solve(int index, vector<int>& candidates, vector<vector<int>>& res, 
               vector<int>& currentCombination, int target) {
        
        // ✅ Base Case: If target becomes 0, we found a valid combination
        if (target == 0) {
            res.push_back(currentCombination);
            return;
        }

        // ❌ If index is out of bounds or target becomes negative, stop exploring
        if (index >= candidates.size() || target < 0) {
            return;
        }

        // 🔁 RECURSIVE CASE

        // 1️⃣ Option 1: Skip current candidate and move to next index
        solve(index + 1, candidates, res, currentCombination, target);

        // 2️⃣ Option 2: Take current candidate (allowed multiple times)
        if (target >= candidates[index]) {
            currentCombination.push_back(candidates[index]); // choose
            solve(index, candidates, res, currentCombination, target - candidates[index]); // stay on same index
            currentCombination.pop_back(); // backtrack
        }
    }

    // Main function to be called
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;                // to store final combinations
        vector<int> currentCombination;         // to store current path
        solve(0, candidates, res, currentCombination, target);  // start recursion
        return res;
    }
};



when T is the target sum
Time Complexity: O(2^T)
Space Complexity: O(T)