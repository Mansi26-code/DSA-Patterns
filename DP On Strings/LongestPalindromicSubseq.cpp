class Solution {
public:
    int LCS(string& str1, string& str2) {
        int m = str1.size();
        int n = str2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
    int longestPalindromeSubseq(string s) {
        string str1 = s;
        string str2 = str1; // Make a copy
        reverse(str2.begin(), str2.end());
        return LCS(str1, str2);
    }
};

//TC & SC= O(m*n)