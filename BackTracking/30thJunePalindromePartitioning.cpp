/**
 * @file PalindromePartitioning.cpp
 * @brief Solves the Palindrome Partitioning problem using recursive backtracking.
 * @author 
 * @date 
 *
 * This solution generates all possible partitions of a string such that every substring is a palindrome.
 */

class Solution {
public:

    /**
     * @brief Checks whether a given string is a palindrome.
     * @param s The string to check.
     * @return true if s is palindrome, false otherwise.
     */
    bool isPalindrome(const string& s) {
        int i = 0, j = s.size() - 1;
        while (i <= j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    /**
     * @brief Recursive helper to generate all palindrome partitions.
     * @param s The input string.
     * @param index Current index from which to partition.
     * @param temp Current list of palindromic substrings.
     * @param ans Final list of all partitions.
     */
    void solve(const string& s, int index, vector<string>& temp, vector<vector<string>>& ans) {
        // Base case: if we reach the end of the string
        if (index == s.size()) {
            ans.push_back(temp);
            return;
        }

        // Explore all possible partitions starting from index
        for (int i = index; i < s.size(); i++) {
            // Extract substring from index to i
            string sub = s.substr(index, i - index + 1);

            // If substring is a palindrome, include it in the current partition
            if (isPalindrome(sub)) {
                temp.push_back(sub);
                solve(s, i + 1, temp, ans);
                temp.pop_back(); // Backtrack
            }
        }
    }

    /**
     * @brief Main function to compute all palindrome partitions.
     * @param s The input string.
     * @return A vector of vectors containing all possible palindrome partitions.
     */
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(s, 0, temp, ans);
        return ans;
    }
};

//TC=O(n*2^n)
//SC= O(n^2)