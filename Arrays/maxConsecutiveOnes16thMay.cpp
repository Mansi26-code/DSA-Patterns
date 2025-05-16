// Given a binary array nums, return the maximum number of consecutive 1s in the array.
// A binary array is an array that contains only 0s and 1s.


class Solution {
    public:
        // Function to find the maximum number of consecutive 1s in a binary array
        int findMaxConsecutiveOnes(vector<int>& nums) {
            int cnt = 0;    // To count current streak of 1s
            int maxi = 0;   // To keep track of the maximum streak of 1s
    
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == 1) {
                    cnt++;                      // Increment counter when 1 is found
                    maxi = max(maxi, cnt);      // Update max if current streak is greater
                } else {
                    cnt = 0;    // Reset counter if a 0 is encountered
                }
            }
    
            return maxi; // Return the maximum count of consecutive 1s
        }
    };
    