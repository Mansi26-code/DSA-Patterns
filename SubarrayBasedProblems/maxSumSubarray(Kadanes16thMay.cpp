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
    


    //To print the subarray with maximum sum 

    TC= O(n)
    SC= O(1)

    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find maximum sum of subarrays and print the subarray having maximum sum
    int maxSubArray(vector<int>& nums) {
        
        // maximum sum
        long long maxi = LLONG_MIN; 
        
        // current sum of subarray
        long long sum = 0;
        
        // starting index of current subarray
        int start = 0; 
        
        // indices of the maximum sum subarray
        int ansStart = -1, ansEnd = -1; 
        
        // Iterate through the array
        for (int i = 0; i < nums.size(); i++) {
            
            // update starting index if sum is reset
            if (sum == 0) {
                start = i;
            }
            
            // add current element to the sum
            sum += nums[i]; 
            
            /* Update maxi and subarray indice
            s if current sum is greater*/
            if (sum > maxi) {
                maxi = sum;
                ansStart = start;
                ansEnd = i;
            }
            
            // Reset sum to 0 if it becomes negative
            if (sum < 0) {
                sum = 0;
            }
        }
        
        // Printing the subarray
        cout << "The subarray is: [";
        for (int i = ansStart; i <= ansEnd; i++) {
            cout << nums[i] << " ";
        }
        cout << "]" << endl;
        
        // Return the maximum subarray sum found
        return maxi;
    }
};