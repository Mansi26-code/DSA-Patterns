/**
 * Definition for an infinite stream.
 * class InfiniteStream {
 * public:
 *     InfiniteStream(vector<int> bits);
 *     int next();
 * };
 */

class Solution {
public:
    int findPattern(InfiniteStream* stream, vector<int>& pattern) {
        int patternLength = pattern.size();

        // Step 1: Preprocess the pattern to build the LPS (Longest Prefix Suffix) array
        // lps[i] will be the length of the longest proper prefix which is also a suffix in pattern[0..i]
        vector<int> lps(patternLength, 0);
        int len = 0; // length of the previous longest prefix suffix
        int i = 1;

        while (i < patternLength) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    // Try to fall back in the prefix pattern
                    len = lps[len - 1];
                } else {
                    // No prefix suffix found, so set lps[i] = 0
                    lps[i] = 0;
                    i++;
                }
            }
        }

        // Step 2: Stream processing using KMP-style pattern matching
        int streamIndex = 0;     // Current index in the stream
        int patternIndex = 0;    // Current index in the pattern

        while (true) {
            int currentBit = stream->next();  // Read one bit at a time from the infinite stream

            // Mismatch after some matches: backtrack using the lps array
            while (patternIndex > 0 && currentBit != pattern[patternIndex]) {
                patternIndex = lps[patternIndex - 1];
            }

            // If current bit matches the pattern character
            if (currentBit == pattern[patternIndex]) {
                patternIndex++;
            }

            // If the whole pattern is matched
            if (patternIndex == patternLength) {
                // Return the starting index of the matched pattern in the stream
                return streamIndex - patternLength + 1;
            }

            // Move to the next index in the stream
            streamIndex++;
        }

        // The return below will never be hit due to the constraints that the pattern appears in the first 10^5 bits
        return -1;
    }
};

👉 Overall TC = O(M + N)
👉 Overall SC = O(M)