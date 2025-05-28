// Brute_Force_Solution.cpp

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * This function returns the number of substrings of length k
     * in the given string 's' that contain all unique characters.
     *
     * If k > 26, it's impossible to form such a substring,
     * since there are only 26 lowercase letters.
     *
     * This approach checks all possible substrings of length k.
     * For each substring, it uses a frequency array to check
     * if all characters are unique. If any character repeats,
     * the substring is skipped.
     */
    int numKLenSubstrNoRepeats(string s, int k) {
        if (k > 26) return 0;

        int n = s.size();
        int answer = 0;

        for (int i = 0; i <= n - k; i++) {
            int freq[26] = {0};
            bool isUnique = true;

            // Check substring from index i to i+k-1
            for (int j = i; j < i + k; j++) {
                int index = s[j] - 'a';
                freq[index]++;

                // If a character appears more than once, it's not unique
                if (freq[index] > 1) {
                    isUnique = false;
                    break;
                }
            }

            // If all characters are unique, count this substring
            if (isUnique) {
                answer++;
            }
        }

        return answer;
    }
};



// Optimal_Solution.cpp

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * This function returns the number of substrings of length k
     * in the given string 's' that contain all unique characters.
     *
     * An unordered_set is used to efficiently maintain a sliding
     * window with unique characters. Whenever a character is repeated,
     * we shrink the window from the left until the duplicate is removed.
     *
     * If the window size becomes exactly k, and all characters are unique,
     * it's counted as a valid substring. Then we slide the window by removing
     * the leftmost character.
     */
    int numKLenSubstrNoRepeats(string s, int k) {
        int n = s.length();
        if (k > 26 || k > n) return 0;

        unordered_set<char> st;
        int left = 0, substrings = 0;

        for (int right = 0; right < n; right++) {
            // If current character is already in the set, remove from the left
            while (st.find(s[right]) != st.end()) {
                st.erase(s[left]);
                left++;
            }

            // Insert current character into the set
            st.insert(s[right]);

            // If window size is exactly k, increment result and slide window
            if (right - left + 1 == k) {
                substrings++;
                st.erase(s[left]);
                left++;
            }
        }

        return substrings;
    }
};
