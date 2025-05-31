/* 
🔸 Problem: Merge two sorted arrays (nums1 and nums2) into nums1 as one sorted array.
🔹 Constraint: nums1 has enough space to hold elements from nums2 as well (size = m + n)
*/

class Solution {
public:

    // 👉 APPROACH 1: Gap Method (Optimal - Shell Sort Concept)
    // Time Complexity: O((m+n) * log(m+n)) approx
    // Space Complexity: O(1) - In-place
    void mergeGapMethod(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len = m + n;

        // Step 1: Calculate initial gap
        int gap = (len / 2) + (len % 2); // Equivalent to ceil(len/2)

        // Step 2: Continue reducing gap and comparing/swapping elements
        while (gap > 0) {
            int left = 0;
            int right = left + gap;

            while (right < len) {
                // Case 1: left in nums1 and right in nums2
                if (left < m && right >= m) {
                    swapIfGreater(nums1, nums2, left, right - m);
                }
                // Case 2: both in nums2
                else if (left >= m) {
                    swapIfGreater(nums2, nums2, left - m, right - m);
                }
                // Case 3: both in nums1
                else {
                    swapIfGreater(nums1, nums1, left, right);
                }
                left++;
                right++;
            }

            // Reduce gap
            if (gap == 1) break;
            gap = (gap / 2) + (gap % 2); // Equivalent to ceil(gap/2)
        }

        // Step 3: Copy sorted nums2 into nums1
        for (int i = m; i < m + n; i++) {
            nums1[i] = nums2[i - m];
        }
    }

    // Utility Function to Swap if left element is greater than right element
    void swapIfGreater(vector<int>& arr1, vector<int>& arr2, int idx1, int idx2) {
        if (arr1[idx1] > arr2[idx2]) {
            swap(arr1[idx1], arr2[idx2]);
        }
    }

    // 👉 APPROACH 2: Naive Method - Merge then Sort
    // Time Complexity: O((m + n) * log(m + n))
    // Space Complexity: O(1) - Sorting is in-place
    void mergeNaiveMethod(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Copy elements of nums2 to the end of nums1
        for (int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];
        }

        // Sort the merged array
        sort(nums1.begin(), nums1.end());
    }
};
