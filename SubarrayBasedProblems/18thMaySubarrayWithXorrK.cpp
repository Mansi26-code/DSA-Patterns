/*
Problem: Count Subarrays with XOR = K
--------------------------------------

Given an array of integers `nums` and an integer `k`, return the total number of subarrays whose elements have an XOR equal to `k`.

Approaches:
-----------
1️⃣ Brute Force (O(n³)) – Triple loop  
2️⃣ Better Approach (O(n²)) – Double loop using running XOR  
3️⃣ Optimal Approach (O(n)) – Prefix XOR with hashmap

Input:
- nums: vector of integers
- k: target XOR value

Output:
- count of subarrays with XOR equal to k
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // 1️⃣ Brute Force (O(n³)): Try all subarrays and calculate XOR in inner loop
    int subarraysWithXorK_Brute(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int xorVal = 0;
                for (int l = i; l <= j; l++) {
                    xorVal ^= nums[l];
                }
                if (xorVal == k) count++;
            }
        }

        return count;
    }

    // 2️⃣ Better Approach (O(n²)): Keep running XOR in the inner loop
    int subarraysWithXorK_Better(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int xorVal = 0;
            for (int j = i; j < n; j++) {
                xorVal ^= nums[j];
                if (xorVal == k) count++;
            }
        }

        return count;
    }



    /*
Problem: Count the number of subarrays with XOR equal to K
------------------------------------------------------------
Given an integer array `nums` and an integer `k`, return the number of subarrays whose XOR is equal to `k`.

Approach:
- Use prefix XOR and a hash map to store the frequency of XORs seen so far.
- The key observation is:
    If `prefix_xor ^ K = required_xor`, then `prefix_xor = required_xor ^ K`.
- So, we check how many times the XOR `prefix_xor ^ K` has occurred before — each occurrence contributes to a valid subarray.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
    public:
        int subarraysWithXorK(vector<int> &nums, int k) {
            int n = nums.size();
            map<int, int> mp; // stores frequency of prefix XORs
            int xr = 0;       // prefix XOR
            int count = 0;
    
            mp[xr]++;  // Initialize with 0 XOR to handle subarrays starting from index 0
    
            for (int i = 0; i < n; i++) {
                xr = xr ^ nums[i];  // update prefix XOR
    
                // Check if there is a prefix XOR such that current_xor ^ previous_xor = k
                int x = xr ^ k;
    
                // If found in map, it means there's a subarray ending at i with XOR == k
                count += mp[x];
    
                // Store current prefix XOR in the map
                mp[xr]++;
            }
    
            return count;
        }
    };
    