class Solution {
public:
    int numberOfSubstrings(string s) {
        int left = 0;
        int substrings = 0;
        int n = s.size();
        unordered_map<char, int> mp;  // To count frequency of 'a', 'b', and 'c'

        for (int right = 0; right < n; right++) {
            mp[s[right]]++;  // Include current character in the window

            // Check if window contains at least one of each: 'a', 'b', 'c'
            while (mp['a'] >= 1 && mp['b'] >= 1 && mp['c'] >= 1) {
                // All substrings starting at current `left` and ending from `right` to `n-1` are valid
                substrings += (n - right);
                // Shrink the window from the left
                mp[s[left]]--;
                left++;
            }
        }

        return substrings;
    }
};
