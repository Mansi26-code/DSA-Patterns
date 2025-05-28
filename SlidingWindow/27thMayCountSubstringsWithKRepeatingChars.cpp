// Brute-force solution using unordered_map to track frequency
// Time Complexity: O(n^2 * 26) ~ O(n^2)
// Space Complexity: O(26) = O(1)
class Solution {
public:
    long long numberOfSubstrings(string s, int k) {
        int n = s.size();
        long long count = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<char, int> freq;

            for (int j = i; j < n; j++) {
                freq[s[j]]++;

                // Check if any character has frequency >= k
                for (auto &entry : freq) {
                    if (entry.second >= k) {
                        count++;
                        break; // Only one such character needed, move to next substring
                    }
                }
            }
        }

        return count;
    }
};


// Optimized solution using early termination and counting in batches
// Time Complexity: O(n^2) in worst-case, but faster in practice
// Space Complexity: O(26) = O(1)
class Solution {
public:
    long long numberOfSubstrings(string s, int k) {
        int n = s.size();
        long long count = 0;

        for (int i = 0; i < n; ++i) {
            int freq[26] = {0};
            int maxFreq = 0;

            for (int j = i; j < n; ++j) {
                int idx = s[j] - 'a';
                freq[idx]++;
                maxFreq = max(maxFreq, freq[idx]);

                if (maxFreq >= k) {
                    // All substrings starting from i and ending at j to n-1 are valid
                    count += (n - j);
                    break; // No need to continue further for this i
                }
            }
        }

        return count;
    }
};

