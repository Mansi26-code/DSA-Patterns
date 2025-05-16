// Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.


// Time Complexity: O(n^3) -> Three nested loops
// Space Complexity: O(1)

class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int n = nums.size();
            int maxSum = INT_MIN;        // Stores the maximum subarray sum
    
            for (int i = 0; i < n; i++) {
                for (int j = i; j < n; j++) {
                    int sum = 0;         // Reset sum for each subarray (i to j)
                    for (int k = i; k <= j; k++) {
                        sum += nums[k];  // Sum the subarray from i to j
                    }
                    maxSum = max(maxSum, sum); // Update maxSum if needed
                }
            }
            return maxSum;               // Return the maximum subarray sum
        }
    };

    







    // Time Complexity: O(n^2) -> Two nested loops
// Space Complexity: O(1)

class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int n = nums.size();
            int maxSum = INT_MIN;        // Stores the maximum subarray sum
    
            for (int i = 0; i < n; i++) {
                int sum = 0;             // Initialize sum for subarrays starting at i
                for (int j = i; j < n; j++) {
                    sum += nums[j];      // Add the j-th element to current sum
                    maxSum = max(maxSum, sum); // Update maxSum if needed
                }
            }
            return maxSum;               // Return the maximum subarray sum
        }
    };

    




    // Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int sum = 0;                 // Stores the current running sum
            int maxSum = INT_MIN;        // Stores the maximum subarray sum found so far
    
            for (int i = 0; i < nums.size(); i++) {
                sum += nums[i];          // Add current element to the sum
                maxSum = max(maxSum, sum); // Update maxSum if current sum is greater
    
                if (sum < 0) {
                    sum = 0;             // If sum becomes negative, reset it to 0
                }
            }
            return maxSum;               // Return the maximum subarray sum
        }
    };
    