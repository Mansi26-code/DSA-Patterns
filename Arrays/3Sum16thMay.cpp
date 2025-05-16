// Given an array nums, find all unique triplets (i, j, k) such that nums[i] + nums[j] + nums[k] == 0. You must return only unique triplets, with no duplicates.

// ✅ Brute-force solution for 3Sum problem
// Time: O(N^3), Space: O(K) — where K is number of unique triplets
class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            int n = nums.size();
            set<vector<int>> st; // Set to automatically handle duplicates
    
            // Triple nested loop to check all combinations
            for (int i = 0; i < n - 2; i++) {
                for (int j = i + 1; j < n - 1; j++) {
                    for (int k = j + 1; k < n; k++) {
                        if (nums[i] + nums[j] + nums[k] == 0) {
                            vector<int> temp = {nums[i], nums[j], nums[k]};
                            sort(temp.begin(), temp.end()); // Sort to avoid permutations like [1,-1,0] and [0,-1,1]
                            st.insert(temp); // Set handles duplicate triplets
                        }
                    }
                }
            }
    
            // Convert set to vector of vectors
            vector<vector<int>> result(st.begin(), st.end());
            return result;
        }
    };

    


    // ✅ Optimal two-pointer solution for 3Sum problem
// Time: O(N^2), Space: O(K) for the output triplets
class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            vector<vector<int>> ans;
            int n = nums.size();
    
            // Step 1: Sort the array to apply two-pointer technique
            sort(nums.begin(), nums.end());
    
            // Step 2: Fix the first number and use two pointers for the rest
            for (int i = 0; i < n; i++) {
                // Skip duplicate elements to avoid repeated triplets
                if (i > 0 && nums[i] == nums[i - 1]) continue;
    
                int j = i + 1;
                int k = n - 1;
    
                // Two-pointer approach to find remaining two numbers
                while (j < k) {
                    int sum = nums[i] + nums[j] + nums[k];
    
                    if (sum < 0) {
                        j++; // Need a larger number
                    } else if (sum > 0) {
                        k--; // Need a smaller number
                    } else {
                        // Triplet found
                        ans.push_back({nums[i], nums[j], nums[k]});
                        j++;
                        k--;
    
                        // Skip duplicates after adding the triplet
                        while (j < k && nums[j] == nums[j - 1]) j++;
                        while (j < k && nums[k] == nums[k + 1]) k--;
                    }
                }
            }
    
            return ans;
        }
    };
    