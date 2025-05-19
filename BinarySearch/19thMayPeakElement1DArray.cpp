class Solution {
    public:
        int findPeakElement(vector<int>& nums) {
            // Initialize the start and end pointers for binary search
            int s = 0, e = nums.size() - 1;
    
            // Perform binary search
            while (s < e) {
                // Find the middle index to avoid potential overflow
                int mid = s + (e - s) / 2;
    
                // If the current element is less than the next element,
                // then the peak lies on the right side (including mid + 1)
                if (nums[mid] < nums[mid + 1]) {
                    s = mid + 1;
                }
                // Else, the peak lies on the left side (including mid)
                else {
                    e = mid;
                }
            }
    
            // When start == end, we've found the peak element index
            return s;
        }
    };

    
    TC=O(log n)