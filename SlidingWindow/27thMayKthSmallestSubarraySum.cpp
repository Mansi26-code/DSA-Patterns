// BRUTE FORCE APPROACH
// Time Complexity: O(n^2 log n)
// Space Complexity: O(n^2)
// Description:
// - We generate all possible subarray sums.
// - Store them in a temporary array.
// - Sort the array of sums.
// - Return the k-th smallest subarray sum.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthSmallestSubarraySum(vector<int>& nums, int k) {
        vector<int> temp;
        int n = nums.size();

        // Generate all subarray sums
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                temp.push_back(sum); // Store each subarray sum
            }
        }

        // Sort the array of all subarray sums
        sort(temp.begin(), temp.end());

        // Return the k-th smallest sum (0-indexed)
        return temp[k - 1];
    }
};



// OPTIMIZED APPROACH: Binary Search on Answer
// Time Complexity: O(n log(sum of array))
// Space Complexity: O(1)
// Description:
// - We binary search the value of the k-th smallest subarray sum.
// - For a guessed value `mid`, we count how many subarrays have sum <= mid.
// - If count >= k, we explore smaller values to find the minimum valid sum.
// - This avoids explicitly storing or sorting all subarray sums.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper function to count subarrays with sum <= given value `mid`
    int countSubarrayWithSumLE(vector<int>& nums, int mid) {
        int left = 0, sum = 0, count = 0;

        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];

            // Shrink the window if sum exceeds `mid`
            while (sum > mid) {
                sum -= nums[left];
                left++;
            }

            // All subarrays ending at `right` and starting from [left ... right] are valid
            count += (right - left + 1);
        }

        return count;
    }

    int kthSmallestSubarraySum(vector<int>& nums, int k) {
        // Minimum possible subarray sum
        int low = *min_element(nums.begin(), nums.end());

        // Maximum possible subarray sum = sum of entire array
        int high = accumulate(nums.begin(), nums.end(), 0);

        int ans = -1;

        // Binary search on the possible sum values
        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Count how many subarrays have sum <= mid
            if (countSubarrayWithSumLE(nums, mid) >= k) {
                ans = mid;      // mid is a possible answer
                high = mid - 1; // Try to find a smaller one
            } else {
                low = mid + 1;  // Not enough subarrays <= mid, search higher
            }
        }

        return ans;
    }
};
