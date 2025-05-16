// Given an array of integers, return all elements that are greater than or equal to all the elements to their right.
// The rightmost element is always a leader.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find leaders in the array
    vector<int> leaders(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans; // Stores the leaders
        unordered_set<int> seen; // To avoid duplicates

        // Start from the last element — it's always a leader
        int maxi = nums[n - 1];
        ans.push_back(maxi);
        seen.insert(maxi);

        // Traverse from right to left
        for (int i = n - 2; i >= 0; i--) {
            // If current element is greater than or equal to max so far
            if (nums[i] >= maxi && seen.find(nums[i]) == seen.end()) {
                ans.push_back(nums[i]);
                seen.insert(nums[i]);
                maxi = nums[i];
            } else {
                // Still update maxi to maintain correct state
                maxi = max(maxi, nums[i]);
            }
        }

        // Reverse to restore left-to-right order of leaders
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

#include <bits/stdc++.h>
using namespace std;

class BruteSolution {
public:
    // Function to find leaders using brute force
    vector<int> leaders(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        unordered_set<int> seen; // To avoid duplicates

        for (int i = 0; i < n; i++) {
            bool isLeader = true;

            // Check if nums[i] is greater than or equal to all to its right
            for (int j = i + 1; j < n; j++) {
                if (nums[i] < nums[j]) {
                    isLeader = false;
                    break;
                }
            }

            // If leader and not already in ans, add it
            if (isLeader && seen.find(nums[i]) == seen.end()) {
                ans.push_back(nums[i]);
                seen.insert(nums[i]);
            }
        }

        return ans;
    }
};



