class Solution {
public:
    int longestNonRepeatingSubstring(string& s) {
        int n = s.size();
        int maxLen = 0;

        // Try every possible substring
        for (int i = 0; i < n; i++) {
            unordered_set<char> st;
            int currLen = 0;

            for (int j = i; j < n; j++) {
                // If character already exists in set, break as it's repeating
                if (st.find(s[j]) != st.end()) {
                    break;
                }

                // Insert character and update current length
                st.insert(s[j]);
                currLen++;
            }

            // Update max length found so far
            maxLen = max(maxLen, currLen);
        }

        return maxLen;
    }
};

Brute-Force Approach

Time Complexity: O(n²)

Space Complexity: O(min(n, 26)) → O(1)




class Solution{
public:
    int longestNonRepeatingSubstring(string& s){
        int left = 0;
        unordered_set<char> st;
        int maxLen = 0;

        for(int right = 0; right < s.size(); right++) {
            // Remove characters from the left until no duplicate
            while(st.find(s[right]) != st.end()) {
                st.erase(s[left]);
                left++;
            }
            st.insert(s[right]);
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

Optimized Sliding Window Approach

Time Complexity: O(n)

Space Complexity: O(min(n, 26)) → O(1)