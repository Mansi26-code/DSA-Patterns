/*
🔸 Problem: Distinct Numbers in Each Subarray

Given an array `nums` and an integer `k`, return an array `ans` where `ans[i]` represents the number of distinct elements 
in the subarray of size `k` starting from index `i`. That is, for each valid `i`, compute distinct count in `nums[i:i+k-1]`.
*/

// -----------------------------------------
// 🔹 Brute Force Approach (O(n * k))
// -----------------------------------------

class Solution {
public:
    vector<int> distinctNumbers(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();

        // Traverse every possible window of size k
        for (int i = 0; i <= n - k; i++) {
            unordered_set<int> st;
            int count = 0;

            // Check distinct elements in the window [i, i + k - 1]
            for (int j = i; j < i + k; j++) {
                if (st.find(nums[j]) == st.end()) {
                    count++;
                    st.insert(nums[j]);
                }
            }

            ans.push_back(count);
        }

        return ans;
    }
};

// -----------------------------------------
// 🔹 Optimized Approach using Sliding Window + Hash Map (O(n))
// -----------------------------------------

class Solution {
public:
    vector<int> distinctNumbers(vector<int>& nums, int k) {
        unordered_map<int, int> freq;  // Stores frequency of elements in current window
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            // Add current element to frequency map
            freq[nums[i]]++;

            // Remove element that moves out of the window
            if (i >= k) {
                freq[nums[i - k]]--;
                if (freq[nums[i - k]] == 0) {
                    freq.erase(nums[i - k]);
                }
            }

            // Once we have a full window, store the distinct count
            if (i >= k - 1) {
                ans.push_back(freq.size());
            }
        }

        return ans;
    }
};
