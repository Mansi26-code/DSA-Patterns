// Given two sorted arrays, return their union (all distinct elements in sorted order).
// Implement both brute force and optimal approaches.


// Brute Force Approach: Using Hash Map
// Time Complexity: O((m + n) log(m + n)) -> due to sorting at the end
// Space Complexity: O(m + n) -> for storing all unique elements in map

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        vector<int> ans;

        // Store all elements of nums1 in map
        for(int i = 0; i < nums1.size(); i++) {
            mp[nums1[i]]++;
        }

        // Add elements of nums2 if not already present
        for(int num : nums2) {
            if(mp.find(num) == mp.end()) {
                mp[num]++;
            }
        }

        // Push all unique keys to result vector
        for(auto &it : mp) {
            ans.push_back(it.first);
        }

        // Sort result to get final union in sorted order
        sort(ans.begin(), ans.end());

        return ans;
    }
};








// Optimal Approach: Using Two Pointers (for Sorted Arrays)
// Time Complexity: O(m + n)
// Space Complexity: O(1) (excluding output vector)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        int m = nums1.size(), n = nums2.size();
        vector<int> unionArr;

        while(i < m && j < n) {
            // Choose the smaller element to insert into unionArr
            if(nums1[i] <= nums2[j]) {
                if(unionArr.empty() || unionArr.back() != nums1[i]) {
                    unionArr.push_back(nums1[i]);
                }
                i++;
            } else {
                if(unionArr.empty() || unionArr.back() != nums2[j]) {
                    unionArr.push_back(nums2[j]);
                }
                j++;
            }
        }

        // Add remaining elements from nums1
        while(i < m) {
            if(unionArr.empty() || unionArr.back() != nums1[i]) {
                unionArr.push_back(nums1[i]);
            }
            i++;
        }

        // Add remaining elements from nums2
        while(j < n) {
            if(unionArr.empty() || unionArr.back() != nums2[j]) {
                unionArr.push_back(nums2[j]);
            }
            j++;
        }

        return unionArr;
    }
};
