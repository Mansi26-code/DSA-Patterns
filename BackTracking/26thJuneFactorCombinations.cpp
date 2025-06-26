/*
254. Factor Combinations 🔢
---------------------------
Given an integer n, return all possible combinations of its factors (excluding 1 and n).
Each factor combination must be in non-decreasing order, and factors must be in [2, n-1].

Example:
Input: n = 12
Output: [[2, 6], [3, 4], [2, 2, 3]]

Approach:
- Use backtracking to try every factor from 2 to sqrt(n).
- At each step, if current `i` divides `n`, recurse with `n/i` and store `i` in the path.
- Base case: if n becomes 1 and path length > 1, store the result.

Time Complexity: O(2^logN) worst case (exponential in number of factors)
Space Complexity: O(logN) for recursion + result storage
*/



class Solution {
public:
    // Helper function for backtracking
    void solve(int start, vector<vector<int>>& res, vector<int>& factors, int n) {
        // Base case: if product of path is n and path has >1 elements
        if (n == 1 && factors.size() > 1) {
            res.push_back(factors);
            return;
        }

        // Try all possible factors from 'start' to 'n'
        for (int i = start; i <= n; i++) {
            if (n % i == 0) {
                factors.push_back(i);
                solve(i, res, factors, n / i);  // Reuse current factor
                factors.pop_back();             // Backtrack
            }
        }
    }

    // Main function to return all factor combinations of n
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;
        vector<int> factors;
        solve(2, res, factors, n);
        return res;
    }
};
