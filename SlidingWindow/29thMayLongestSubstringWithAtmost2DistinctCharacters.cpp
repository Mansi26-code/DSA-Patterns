// Problem: Longest Substring with At Most Two Distinct Characters
// Link: https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/
// Difficulty: Medium

/*
Approach:
We use the sliding window technique along with a hash map (unordered_map) to keep track of character frequencies within the window.
- Expand the window by moving `right` and adding characters to the map.
- If the size of the map exceeds 2 (more than 2 distinct characters), 
  shrink the window from the left until there are only 2 distinct characters.
- Update the maximum length at each step.

Time Complexity: O(n), where n is the length of the string.
    - Each character is visited at most twice (once by `right`, once by `left`)
Space Complexity: O(1), since there are only 26 possible lowercase/uppercase letters at most.

*/

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int left = 0, maxLen = 0;
        unordered_map<char, int> mp;  // Map to store character frequencies in the current window

        for (int right = 0; right < s.length(); right++) {
            // Add the current character to the map and increment its count
            mp[s[right]]++;

            // If we have more than 2 distinct characters, shrink the window from the left
            while (mp.size() > 2) {
                mp[s[left]]--;  // Decrement count of the leftmost character
                if (mp[s[left]] == 0) {
                    mp.erase(s[left]);  // Remove the character if its count becomes 0
                }
                left++;  // Move the left pointer forward
            }

            // Update the max length of the valid window found so far
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
