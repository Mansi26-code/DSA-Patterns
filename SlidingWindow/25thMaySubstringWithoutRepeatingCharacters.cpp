#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // ✅ Brute Force Approach
    int bruteForce(string s) {
        int n = s.size();
        int count = 0;

        // Check all substrings
        for (int i = 0; i < n; i++) {
            unordered_set<char> st;
            for (int j = i; j < n; j++) {
                // If character is already in set, break (not a special substring)
                if (st.count(s[j])) break;
                st.insert(s[j]);
                count++; // Valid substring found
            }
        }

        return count;
    }

    // ✅ Optimized Approach: Sliding Window Technique
    int slidingWindow(string s) {
        int n = s.size();
        int left = 0;
        int count = 0;
        unordered_set<char> window; // Tracks current non-repeating window

        for (int right = 0; right < n; right++) {
            // Shrink window from left until s[right] is unique
            while (window.count(s[right])) {
                window.erase(s[left]);
                left++;
            }

            window.insert(s[right]);

            // All substrings ending at right and starting from left to right are unique
            count += (right - left + 1);
        }

        return count;
    }

    // 🚀 You can call either function here to test
    int numberOfSpecialSubstrings(string s) {
        // return bruteForce(s);     // Uncomment to test brute-force
        return slidingWindow(s);     // Optimal solution
    }
};


🧠 Time & Space Complexity
🐢 Brute Force
Time: O(n^2)
(We check all substrings, and check uniqueness using a set in O(1) avg per char)

Space: O(n) (for the set)

🚀 Optimized (Sliding Window)
Time: O(n)
(Each character is inserted and removed from the set at most once)

Space: O(26) or O(n) (depending on character set size)