class Solution {
public:
    // Helper function to check if all characters in pattern[0..i] are '*'
    bool isAllStars(string &pat, int i) {
        for (int j = 0; j <= i; j++) {
            if (pat[j] != '*') return false;
        }
        return true;
    }

    // Core recursive function with memoization
    bool wildCardMatchingUtil(string &pat, string &str, int i, int j, vector<vector<int>>& dp) {
        // Base Case 1: Both pattern and string fully matched
        if (i < 0 && j < 0) return true;

        // Base Case 2: Pattern exhausted but string still has characters
        if (i < 0 && j >= 0) return false;

        // Base Case 3: String exhausted but pattern might still be valid only if all are '*'
        if (j < 0 && i >= 0) return isAllStars(pat, i);

        // If already computed, return cached value
        if (dp[i][j] != -1) return dp[i][j];

        // Match character or '?'
        if (pat[i] == str[j] || pat[i] == '?') {
            return dp[i][j] = wildCardMatchingUtil(pat, str, i - 1, j - 1, dp);
        }

        // Match '*' - two options:
        // 1. Treat '*' as empty (move pattern index i - 1)
        // 2. Treat '*' as matching one character (move string index j - 1)
        if (pat[i] == '*') {
            return dp[i][j] = wildCardMatchingUtil(pat, str, i - 1, j, dp) || 
                              wildCardMatchingUtil(pat, str, i, j - 1, dp);
        }

        // Characters don't match and it's not a wildcard
        return dp[i][j] = false;
    }

    // Main function
    bool wildCard(string str, string pat) {
        int n = str.size();
        int m = pat.size();

        // Initialize dp table with -1
        vector<vector<int>> dp(m, vector<int>(n, -1));

        // Start recursive matching from end of both strings
        return wildCardMatchingUtil(pat, str, m - 1, n - 1, dp);
    }
};
