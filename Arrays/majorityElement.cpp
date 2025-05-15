// Given an array nums of size n, find the element that appears more than ⌊n / 2⌋ times. It is guaranteed that such an element exists.



// Time Complexity: O(n)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the majority element using a hash map
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp; // Map to store frequencies
        int ans = -1;

        // Count frequency of each element
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        // Check which element occurs more than n/2 times
        for (auto it : mp) {
            if (it.second > nums.size() / 2) {
                ans = it.first;
                break;
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
    // Function to find the majority element using Moore's Voting Algorithm
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate;

        // Step 1: Find a potential candidate
        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) {
                candidate = nums[i];
                count = 1;
            } else if (nums[i] == candidate) {
                count++;
            } else {
                count--;
            }
        }

        // Step 2: Verify the candidate (if needed, although problem guarantees existence)
        int count1 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == candidate)
                count1++;
        }

        if (count1 > nums.size() / 2)
            return candidate;

        return -1; // In case majority element doesn't exist (not needed per constraints)
    }
};
