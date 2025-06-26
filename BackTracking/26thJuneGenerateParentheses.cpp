// Generate all combinations of n pairs of well-formed parentheses.
// Each combination must be valid (e.g., (), (()), (()()), but not ())().


// Time Complexity: O(4^n / √n) (Catalan number)
// Space Complexity: O(n) (recursion depth) + O(Cn) (result size)



class Solution {
public:
    // Recursive helper function
    void solve(int n, int open, int close, string temp, vector<string>& ans) {
        // ✅ Base case: If current string length is 2*n, it's complete
        if (temp.size() == 2 * n) {
            ans.push_back(temp);
            return;
        }

        // 🔁 Choice 1: Add '(' if open count is less than n
        if (open < n) {
            temp += '(';
            solve(n, open + 1, close, temp, ans);
            temp.pop_back(); // backtrack
        }

        // 🔁 Choice 2: Add ')' only if close count is less than open
        if (close < open) {
            temp += ')';
            solve(n, open, close + 1, temp, ans);
            temp.pop_back(); // backtrack
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(n, 0, 0, "", ans);  // Start with 0 open, 0 close, and empty string
        return ans;
    }
};
