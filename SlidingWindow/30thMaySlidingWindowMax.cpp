// Author: Mansi
// Title: Sliding Window Maximum using Deque
// Time Complexity: O(n)
// Space Complexity: O(k) for deque + O(n - k + 1) for result

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * @brief Finds the maximum value in each sliding window of size k.
     * 
     * @param nums A vector of integers representing the input array.
     * @param k The size of the sliding window.
     * @return A vector containing the maximum of each sliding window.
     * 
     * Time Complexity: O(n) where n is the number of elements in nums.
     * Space Complexity: O(k) for deque to store indices + O(n - k + 1) for result vector.
     */
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        deque<int> dq;          // Stores indices of useful elements in current window
        vector<int> res;        // Stores the result (maximums of each window)
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            // Remove the indices which are out of the current window
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }

            // Remove all indices whose corresponding values are less than nums[i]
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            // Add current index to the deque
            dq.push_back(i);

            // Add the maximum for the current window to the result
            if (i >= k - 1) {
                res.push_back(nums[dq.front()]);
            }
        }

        return res;
    }
};
