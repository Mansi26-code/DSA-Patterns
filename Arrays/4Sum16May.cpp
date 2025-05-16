/*
🧠 Problem: Given an array 'nums' of integers and an integer 'target', return all unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
    nums[a] + nums[b] + nums[c] + nums[d] == target
Each quadruplet must be unique. You can return the answer in any order.
*/


// ✅ Brute Force Approach for Four Sum
// Time Complexity: O(N^4 * logK) → due to 4 nested loops and set insertion
// Space Complexity: O(K) → for storing unique quadruplets in a set

class Solution {
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            int n = nums.size();
            set<vector<int>> st;  // To store unique sorted quadruplets
    
            for (int i = 0; i < n - 3; i++) {
                for (int j = i + 1; j < n - 2; j++) {
                    for (int k = j + 1; k < n - 1; k++) {
                        for (int l = k + 1; l < n; l++) {
                            long long sum = 1LL * nums[i] + nums[j] + nums[k] + nums[l];
                            if (sum == target) {
                                vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                                sort(temp.begin(), temp.end()); // To handle permutations
                                st.insert(temp);
                            }
                        }
                    }
                }
            }
    
            // Convert set to vector
            return vector<vector<int>>(st.begin(), st.end());
        }
    };

    


    // ✅ Optimal Two Pointer Approach for Four Sum
// Time Complexity: O(N^3), where N is the size of the array
// Space Complexity: O(K) for storing K unique quadruplets

class Solution {
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            int n = nums.size();
            vector<vector<int>> ans;
    
            // Step 1: Sort the array to apply two-pointer technique
            sort(nums.begin(), nums.end());
    
            // Step 2: Outer two loops for i and j
            for (int i = 0; i < n; i++) {
                if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicate i
    
                for (int j = i + 1; j < n; j++) {
                    if (j > i + 1 && nums[j] == nums[j - 1]) continue; // Skip duplicate j
    
                    int k = j + 1;
                    int l = n - 1;
    
                    while (k < l) {
                        long long sum = 1LL * nums[i] + nums[j] + nums[k] + nums[l];
    
                        if (sum < target) {
                            k++;
                        } else if (sum > target) {
                            l--;
                        } else {
                            // Found a valid quadruplet
                            ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                            k++;
                            l--;
    
                            // Skip duplicates for k and l
                            while (k < l && nums[k] == nums[k - 1]) k++;
                            while (k < l && nums[l] == nums[l + 1]) l--;
                        }
                    }
                }
            }
    
            return ans;
        }
    };
    