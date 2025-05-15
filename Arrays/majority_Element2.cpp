// Given an integer array nums, return all elements that appear more than ⌊n/3⌋ times. At most, two such elements can exist.


// Time Complexity: O(n)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElementTwo(vector<int>& nums) {
        // Hash map to store frequency of each element
        unordered_map<int, int> mp;
        vector<int> ans;

        // Count frequency of each element
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        // Check which elements appear more than ⌊n/3⌋ times
        for (auto &it : mp) {
            if (it.second > nums.size() / 3) {
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};




// Time Complexity: O(n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElementTwo(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Initialize two potential candidates and their counters
        int cnt1 = 0, cnt2 = 0;
        int el1 = INT_MIN, el2 = INT_MIN;

        // Step 2: Voting phase to find potential candidates
        for (int i = 0; i < n; i++) {
            if (cnt1 == 0 && nums[i] != el2) {
                cnt1 = 1;
                el1 = nums[i];
            }
            else if (cnt2 == 0 && nums[i] != el1) {
                cnt2 = 1;
                el2 = nums[i];
            }
            else if (nums[i] == el1) {
                cnt1++;
            }
            else if (nums[i] == el2) {
                cnt2++;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }

        // Step 3: Count actual frequencies of the candidates
        cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == el1) cnt1++;
            if (nums[i] == el2) cnt2++;
        }

        int threshold = n / 3 + 1;
        vector<int> result;

        // Step 4: Validate candidates
        if (cnt1 >= threshold) result.push_back(el1);
        if (cnt2 >= threshold && el1 != el2) result.push_back(el2);

        return result;
    }
};
