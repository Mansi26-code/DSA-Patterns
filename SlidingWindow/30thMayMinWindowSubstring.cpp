// 🌟 Brute Force Approach to find the Minimum Window Substring 🌟
// ✅ Time: O(n² + m), Space: O(1)

class Solution {
public:
    /*
     * 💡 Function to find the minimum length substring
     * in string s that contains all characters from string t.
     */
    string minWindow(string s, string t) {
        
        int minLen = INT_MAX;      // 🌈 Stores length of smallest valid window
        int sIndex = -1;           // 📌 Starting index of that minimum window
        
        // 🔁 Traverse every character as starting point
        for (int i = 0; i < s.size(); ++i) {
            int hash[256] = {0};   // 🧮 Frequency map for characters in t
            
            // 📝 Count frequency of each char in t
            for (char c : t) {
                hash[c]++;
            }

            int count = 0;         // ✅ Count of matched characters
            
            // 🔁 Try to expand window from i to j
            for (int j = i; j < s.size(); ++j) {
                if (hash[s[j]] > 0) count++;  // ✔️ Match found
                hash[s[j]]--;                 // 🔽 Decrease frequency

                // 🎯 If all characters matched
                if (count == t.size()) {
                    // ✨ Check for smaller window
                    if (j - i + 1 < minLen) {
                        minLen = j - i + 1;
                        sIndex = i;           // 🧭 Update starting index
                    }
                    break;  // ✅ Found the minimum window for this i
                }
            }
        }

        // 📤 Return the result
        return (sIndex == -1) ? "" : s.substr(sIndex, minLen);
    }
};




// 🚀 Optimized Sliding Window Approach to find Minimum Window Substring
// ✅ Time: O(n + m), Space: O(1)

class Solution {
public:
    /*
     * 💡 Function to find the minimum length 
     * substring in string s that contains
     * all characters from string t.
     */
    string minWindow(string s, string t) {

        int minLen = INT_MAX;      // 🏆 To store the smallest window length
        int sIndex = -1;           // 📌 Starting index of that window
        
        int hash[256] = {0};       // 🧮 Frequency map for characters in t
        
        // 🔁 Count characters in t
        for (char c : t) {
            hash[c]++;
        }

        int count = 0;             // ✅ Characters matched
        int l = 0, r = 0;          // 🔍 Sliding window pointers

        // 🔁 Traverse the string using sliding window
        while (r < s.size()) {
            // ➕ Include s[r] in the window
            if (hash[s[r]] > 0) {
                count++;
            }
            hash[s[r]]--;  // 🧾 Decrease count even if char not needed
            r++;           // Move right pointer

            // 🎯 All characters matched — try shrinking
            while (count == t.size()) {
                // ✨ Update answer if current window is smaller
                if (r - l < minLen) {
                    minLen = r - l;
                    sIndex = l;
                }

                // ➖ Shrink from the left
                hash[s[l]]++;
                if (hash[s[l]] > 0) {
                    count--;  // Character became unmatched
                }
                l++;  // Move left pointer
            }
        }

        // 📤 Return final result
        return (sIndex == -1) ? "" : s.substr(sIndex, minLen);
    }
};
