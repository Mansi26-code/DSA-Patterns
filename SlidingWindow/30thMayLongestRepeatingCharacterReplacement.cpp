class Solution {
public:
    int characterReplacement(string s, int k) {
        // Map to store the frequency of characters in the current window
        unordered_map<char, int> mp;

        int left = 0;           // Left pointer of the sliding window
        int maxLen = 0;         // Stores the maximum length of valid window
        int maxFreq = 0;        // Stores the count of the most frequent character in the current window

        // Traverse the string with the right pointer
        for (int right = 0; right < s.size(); right++) {
            mp[s[right]]++;     // Increase frequency of current character
            maxFreq = max(maxFreq, mp[s[right]]);  // Update maxFreq with highest char frequency in window

            /*
              Check if number of characters to change > k
              i.e. Total window size - max frequency char count > k
              If yes, then it's an invalid window, so shrink it from the left
            */
            if ((right - left + 1) - maxFreq > k) {
                mp[s[left]]--;  // Remove leftmost character from frequency map
                left++;         // Move window to the right
            }

            // Update maxLen with current window size
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen; // Return the maximum length of valid substring found
    }
};
