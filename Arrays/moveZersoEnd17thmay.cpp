class Solution {
    public:
        // Function to move all zeros to the end using an extra array
        void moveZeroes(vector<int>& nums) {
            int n = nums.size();
    
            // Create a temporary array filled with 0s
            vector<int> temp(n, 0);
    
            int start = 0; // Index to place next non-zero element in temp
    
            // Copy non-zero elements from original array to temp
            for (int i = 0; i < n; i++) {
                if (nums[i] != 0) {
                    temp[start] = nums[i];
                    start++;
                }
            }
    
            // Copy the updated array back to original array
            nums = temp;
        }
    };TC=O(N)
    SC=O(N)






    class Solution {
        public:
            // Function to move zeros to the end without using extra space
            void moveZeroes(vector<int>& nums) {
                int n = nums.size();
                int j = -1;
        
                // Step 1: Find the index of the first zero
                for (int i = 0; i < n; i++) {
                    if (nums[i] == 0) {
                        j = i;
                        break;
                    }
                }
        
                // If there is no zero, no need to proceed
                if (j == -1) return;
        
                // Step 2: From index j+1, look for non-zero elements and swap with j
                for (int i = j + 1; i < n; i++) {
                    if (nums[i] != 0) {
                        swap(nums[i], nums[j]);
                        j++; // Move j to the next zero position
                    }
                }
            }
        };

        
        TC=O(N)
        SC=O(1)
    