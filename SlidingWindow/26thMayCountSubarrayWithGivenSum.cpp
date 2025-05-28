/*
🔸 Problem: Subarray Sum Equals K

Given an integer array `nums` and an integer `k`, return the total number of continuous subarrays
whose sum equals to `k`.
*/

// -----------------------------------------
// 🔹 Brute Force Approach (O(n^2))
// -----------------------------------------

class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        int n = nums.size();
        int count = 0;

        // Try every subarray starting from each index
        for (int i = 0; i < n; i++) {
            int sum = 0;

            for (int j = i; j < n; j++) {
                sum += nums[j];

                if (sum == k) {
                    count++;
                }
            }
        }

        return count;
    }
};

/*
🕒 Time Complexity: O(n^2)
🧠 Space Complexity: O(1)
*/

// -----------------------------------------
// 🔹 Optimized Approach using Prefix Sum + Hash Map (O(n))
// -----------------------------------------

class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        unordered_map<int, int> prefixSumFreq;
        prefixSumFreq[0] = 1;  // Base case: empty subarray sum is 0

        int sum = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            // Check if there exists a prefix sum that satisfies sum - k
            if (prefixSumFreq.find(sum - k) != prefixSumFreq.end()) {
                count += prefixSumFreq[sum - k];
            }

            // Store current prefix sum frequency
            prefixSumFreq[sum]++;
        }

        return count;
    }
};

/*
🕒 Time Complexity: O(n)
🧠 Space Complexity: O(n)
*/
