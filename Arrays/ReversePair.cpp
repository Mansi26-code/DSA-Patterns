// Given an array nums, count the number of reverse pairs (i, j) where i < j and nums[i] > 2 * nums[j].



// Time Complexity: O(n^2)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int count = 0; // To store the number of valid reverse pairs

        // Iterate through each pair of indices (i, j) such that i < j
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {

                // Check the reverse pair condition: nums[i] > 2 * nums[j]
                if (nums[i] > 2LL * nums[j]) {
                    count++;
                }
            }
        }

        return count;
    }
};




//Optimal Approach

#include <vector>
using namespace std;

class Solution {
public:
    // Merge two sorted halves and count reverse pairs
    void mergeAndCount(vector<int>& nums, int low, int mid, int high, int &count) {
        int j = mid + 1;

        // Count the reverse pairs using the given condition
        for (int i = low; i <= mid; i++) {
            while (j <= high && nums[i] > 2LL * nums[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }

        // Merge the two sorted halves
        vector<int> temp;
        int left = low, right = mid + 1;

        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left++]);
            } else {
                temp.push_back(nums[right++]);
            }
        }

        // Append remaining elements
        while (left <= mid) {
            temp.push_back(nums[left++]);
        }
        while (right <= high) {
            temp.push_back(nums[right++]);
        }

        // Copy the sorted merged array back to original array
        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
    }

    // Recursive Merge Sort function that counts reverse pairs
    int mergeSort(vector<int>& nums, int low, int high) {
        int cnt = 0;
        if (low >= high) return cnt;

        int mid = low + (high - low) / 2;

        // Count in left and right halves
        cnt += mergeSort(nums, low, mid);
        cnt += mergeSort(nums, mid + 1, high);

        // Count cross reverse pairs and merge both halves
        mergeAndCount(nums, low, mid, high, cnt);

        return cnt;
    }

    // Driver function
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};
Time Complexity: O(n log n)
SC= O(n)