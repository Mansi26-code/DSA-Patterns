// You're given an array of integers (which may contain duplicates) and a target value.
// Find all unique combinations where each number is used at most once, and the numbers add up to the target.

// ✔️ No repeated use of the same element.
// ✔️ Avoid duplicate combinations like [1, 2, 2] and [2, 1, 2].













class Solution {
public:
    void solve(int index, vector<int>& candidates, vector<vector<int>>& res, 
               vector<int>& current, int target) {
        if (target == 0) {
            res.push_back(current);
            return;
        }

        for (int i = index; i < candidates.size(); ++i) {
            if (i > index && candidates[i] == candidates[i - 1]) continue; // skip duplicates
            if (candidates[i] > target) break;

            current.push_back(candidates[i]);
            solve(i + 1, candidates, res, current, target - candidates[i]);
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> current;
        solve(0, candidates, res, current, target);
        return res;
    }
};


// Time Complexity: O(2^n)
// Space Complexity: O(k)