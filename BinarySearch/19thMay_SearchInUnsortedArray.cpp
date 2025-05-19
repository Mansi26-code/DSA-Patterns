/*
Binary Searchable Numbers in an Unsorted Array:
Count how many elements in an unsorted array are guaranteed to be found using a modified binary search that randomly picks a pivot and discards one side based on the pivot value.
*/

class Solution {
    public:
        // Arrays to store prefix maximums and suffix minimums
        vector<int> suffixMin, prefixMax;
    
        // Check if nums[i] is the maximum from the start to index i
        bool checkLeftLargest(vector<int>& nums, int index) {
            return prefixMax[index] == nums[index];
        }
    
        // Check if nums[i] is the minimum from index i to the end
        bool checkRightSmallest(vector<int>& nums, int index) {
            return suffixMin[index] == nums[index];
        }
    
        int binarySearchableNumbers(vector<int>& nums) {
            int n = nums.size();
            prefixMax.resize(n);
            suffixMin.resize(n);
    
            // Build prefixMax array: prefixMax[i] = max(nums[0..i])
            prefixMax[0] = nums[0];
            for (int i = 1; i < n; i++) {
                prefixMax[i] = max(prefixMax[i - 1], nums[i]);
            }
    
            // Build suffixMin array: suffixMin[i] = min(nums[i..n-1])
            suffixMin[n - 1] = nums[n - 1];
            for (int i = n - 2; i >= 0; i--) {
                suffixMin[i] = min(suffixMin[i + 1], nums[i]);
            }
    
            int ans = 0;
    
            // An element is "binary searchable" if:
            // - It is the maximum so far from the left
            // - It is the minimum from this index to the end
            for (int i = 0; i < n; i++) {
                if (checkLeftLargest(nums, i) && checkRightSmallest(nums, i)) {
                    ans += 1;
                }
            }
    
            return ans;
        }
    };
    
    /*
    Time Complexity: O(n) – One pass for prefix, one for suffix, and one for checking.
    Space Complexity: O(n) – Extra space for prefixMax and suffixMin arrays.
    */
    