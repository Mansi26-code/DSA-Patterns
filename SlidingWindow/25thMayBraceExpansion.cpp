// Brace Expansion Problem
// Author: Your Name
// Description: Expands a string with braces into all possible combinations (lexicographically sorted)

class Solution {
public:
    vector<string> expand(string s) {
        vector<string> ans; // Stores final combinations
        vector<vector<char>> groups; // Stores character groups for each position

        // Step 1: Parse the input string into groups
        for (int i = 0; i < s.size(); i++) {
            vector<char> group;

            if (s[i] == '{') {
                i++; // Skip '{'
                while (s[i] != '}') {
                    if (s[i] != ',') {
                        group.push_back(s[i]); // Add character to group
                    }
                    i++;
                }
            } else {
                group.push_back(s[i]); // Single character (not in braces)
            }

            sort(group.begin(), group.end()); // Sort for lexicographical order
            groups.push_back(group); // Add group to list of groups
        }

        string res = "";
        generateCombinations(groups, 0, res, ans); // Start backtracking
        return ans;
    }

private:
    // Backtracking function to generate all combinations
    void generateCombinations(vector<vector<char>>& groups, int index, string& res, vector<string>& ans) {
        if (index == groups.size()) {
            ans.push_back(res); // Combination complete, add to answer
            return;
        }

        for (char c : groups[index]) {
            res.push_back(c); // Choose current character
            generateCombinations(groups, index + 1, res, ans); // Move to next group
            res.pop_back(); // Backtrack
        }
    }
};
