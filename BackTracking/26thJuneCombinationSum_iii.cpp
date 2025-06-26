// Find all unique combinations of k numbers (from 1 to 9, used once only) such that their sum equals n.
// No number can repeat, and the result must have distinct combinations only.



// Time Complexity: O(C(9, k))
// Space Complexity: O(k) (recursion depth)



class Solution {
public:
    void solve(int index, int k, int n, vector<vector<int>>& res, 
               vector<int>& current, vector<int>& num) {
        
        // ✅ Base Case: If sum is n and we picked k numbers, it's valid
        if (n == 0 && k == 0) {
            res.push_back(current);
            return;
        }

        // ❌ Invalid path
        if (index >= num.size() || n < 0 || k < 0) return;

        // 🔁 Decision 1: Skip current number
        solve(index + 1, k, n, res, current, num);

        // 🔁 Decision 2: Pick current number if it doesn't exceed sum
        if (num[index] <= n) {
            current.push_back(num[index]); // choose
            solve(index + 1, k - 1, n - num[index], res, current, num); // move to next index
            current.pop_back(); // backtrack
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> num;
        for (int i = 1; i <= 9; i++) num.push_back(i); // Allowed digits: 1 to 9

        vector<vector<int>> res;
        vector<int> current;
        solve(0, k, n, res, current, num);
        return res;
    }
};
