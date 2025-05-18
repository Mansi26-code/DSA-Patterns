// 🔴 Brute Force Approach (Three nested loops)
// ✅ Idea: Try every possible subarray, calculate sum, and check if it's equal to k

class Solution {
    public:
        int subarraySum(vector<int> &nums, int k) {
            int n = nums.size();
            int count = 0;
    
            // Loop through all subarrays [i...j]
            for (int i = 0; i < n; i++) {
                for (int j = i; j < n; j++) {
                    int sum = 0;
    
                    // Calculate sum of subarray from i to j
                    for (int l = i; l <= j; l++) {
                        sum += nums[l];
                    }
    
                    // If subarray sum is equal to k, increment count
                    if (sum == k) {
                        count++;
                    }
                }
            }
    
            return count;
        }
    };
    
    /*
    🔍 Time Complexity: O(n^3)
    🧠 Space Complexity: O(1)
    Explanation: Three nested loops for all subarrays, sum calculation inside.
    */
    
    
    
    
    // 🟠 Better Approach (Two nested loops)
    // ✅ Idea: Avoid one loop by keeping a running sum of subarray [i...j]
    
    class Solution {
    public:
        int subarraySum(vector<int> &nums, int k) {
            int n = nums.size();
            int count = 0;
    
            // Loop through starting index
            for (int i = 0; i < n; i++) {
                int sum = 0;
    
                // Extend subarray from i to j and update running sum
                for (int j = i; j < n; j++) {
                    sum += nums[j];
    
                    // If running sum == k, increment count
                    if (sum == k) {
                        count++;
                    }
                }
            }
    
            return count;
        }
    };
    
    /*
    🔍 Time Complexity: O(n^2)
    🧠 Space Complexity: O(1)
    Explanation: Two loops to generate subarrays; sum maintained in a single variable.
    */
    
    
    
    
    // 🟢 Optimal Approach (Prefix Sum + HashMap)
    // ✅ Idea: Use cumulative sum and map to count how many times currSum - k has occurred.
    
    class Solution {
    public:
        int subarraySum(vector<int> &nums, int k) {
            unordered_map<int, int> mp;
            int n = nums.size();
    
            // Base case: prefix sum 0 has occurred once
            mp.insert({0, 1});
    
            int currSum = 0;
            int count = 0;
    
            for (int i = 0; i < n; i++) {
                currSum += nums[i]; // Update current prefix sum
    
                // If (currSum - k) exists in map, add its frequency to count
                if (mp.find(currSum - k) != mp.end()) {
                    count += mp[currSum - k];
                }
    
                // Increment frequency of current prefix sum
                mp[currSum]++;
            }
    
            return count;
        }
    };
    
    /*
    🔍 Time Complexity: O(n)
    🧠 Space Complexity: O(n)
    Explanation: One pass using hashmap to store prefix sums and their frequencies.
    */
    