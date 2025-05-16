// Given an array nums and an integer target, return the indices of the two numbers such that they add up to the target.
// Return {-1, -1} or {} if no such pair exists.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // ✅ Approach 1: Brute Force
    // Check every possible pair to find the target sum.
    // Time Complexity: O(n^2)
    // Space Complexity: O(1)
    vector<int> twoSumBruteForce(vector<int>& nums, int target) {
        int n = nums.size();

        // Check each pair of elements
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // If a valid pair is found, return their indices
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }

        // No valid pair found
        return {-1, -1};
    }

    // ✅ Approach 2: Hash Map (Optimal)
    // Store each element's index while checking if complement exists
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    vector<int> twoSumHashMap(vector<int>& nums, int target) {
        unordered_map<int, int> mp; // To store element -> index mapping

        for (int i = 0; i < nums.size(); i++) {
            int needed = target - nums[i];

            // If complement is found in the map, return indices
            if (mp.find(needed) != mp.end()) {
                return {mp[needed], i};
            }

            // Store current number with its index
            mp[nums[i]] = i;
        }

        // No valid pair found
        return {};
    }
};



//optimal 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /* Function to find two indices in the array `nums`
       such that their elements sum up to `target`.
    */
    vector<int> twoSum(vector<int>& nums, int target) {
        // Size of the nums vector
        int n = nums.size(); 
        
        // Vector to store indices of two numbers
        vector<int> ans; 
        
        vector<vector<int>> eleIndex;
        for(int i = 0; i < nums.size(); i++){
            eleIndex.push_back({nums[i], i});
        }
        
        //Sort by first element in ascending order
        sort(eleIndex.begin(), eleIndex.end(), [](const vector<int>& a, const vector<int>& b) {
           return a[0] < b[0]; 
        });

        /* Two pointers: one starting 
        from left and one from right*/
        int left = 0, right = n - 1; 

        while (left < right) {
             /* Calculate sum of elements
             at left and right pointers*/
            int sum = eleIndex[left][0] + eleIndex[right][0];

            if (sum == target) {
                
                /* If sum equals target, 
                store indices and return*/
                ans.push_back(eleIndex[left][1]);
                ans.push_back(eleIndex[right][1]);
                return ans;
                
            } else if (sum < target) {
                
                /* If sum is less than target, 
                move left pointer to the right*/
                left++;
                
            } else {
                
                /* If sum is greater than target,
                move right pointer to the left*/
                right--;
                
            }
        }

        // If no such pair found, return {-1, -1}
        return {-1, -1};
    }
};



Time Complexity: O(N) + O(N*logN),

sc=O(N)