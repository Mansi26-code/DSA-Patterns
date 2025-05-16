// Given an array where the number of positive and negative elements are equal, rearrange elements so that positives are at even indices and negatives at odd indices.
// Maintain the relative order of appearance for positives and negatives.



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // ✅ Approach 1: Using Separate Positive and Negative Arrays
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    vector<int> rearrangeArrayUsingTwoVectors(vector<int>& nums) {
        int n = nums.size();

        // Separate vectors for storing positive and negative numbers
        vector<int> pos, neg;

        // Separate the elements
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) pos.push_back(nums[i]);
            else neg.push_back(nums[i]);
        }

        // Interleave positive at even and negative at odd indices
        for (int i = 0; i < n / 2; ++i) {
            nums[2 * i] = pos[i];
            nums[2 * i + 1] = neg[i];
        }

        return nums;
    }

    // ✅ Approach 2: Using Direct Indexing (Better Readability)
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    vector<int> rearrangeArrayWithIndexPointers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0); // Result array initialized with zeros
        int pos = 0; // Pointer for placing positives at even indices
        int neg = 1; // Pointer for placing negatives at odd indices

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                ans[pos] = nums[i];
                pos += 2;
            } else {
                ans[neg] = nums[i];
                neg += 2;
            }
        }

        return ans;
    }
};
