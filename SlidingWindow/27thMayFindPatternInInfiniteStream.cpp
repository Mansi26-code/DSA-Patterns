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
        int left = 0;
        int k = pattern.size();
        int count = 0;
        int ans = -1;

        vector<int> window;

        // We'll keep fetching values from stream
        while (true) {
            int current = stream->next();
            window.push_back(current);

            // Maintain window size of at most k
            if (window.size() > k) {
                window.erase(window.begin());
                left++;
            }

            // Check if window matches the pattern
            if (window.size() == k) {
                bool isMatch = true;
                for (int i = 0; i < k; i++) {
                    if (window[i] != pattern[i]) {
                        isMatch = false;
                        break;
                    }
                }

                if (isMatch) {
                    ans = left;
                    break;
                }
            }
        }

        return ans;
    }
};

TC=O(nxk)
sc=O(k)