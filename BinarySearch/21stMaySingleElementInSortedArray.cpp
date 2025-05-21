// Leetcode 540: Single Element in a Sorted Array
// Link: https://leetcode.com/problems/single-element-in-a-sorted-array/

// Approach:
// - The input array is sorted and every element appears exactly twice except one element which appears only once.
// - We use Binary Search to find the unique element in O(log n) time.

class Solution {
    public:
        int singleNonDuplicate(vector<int> &nums) {
            int n = nums.size();
            int s = 0, e = n - 1;
    
            while (s < e) {
                int mid = s + (e - s) / 2;
    
                // If the current mid is the unique element
                if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
                    return nums[mid];
    
                // We are in the left half of the correct pair positioning
                // Check the pattern and shift the search space accordingly
    
                if (mid % 2 == 1) {
                    // If mid is odd and equal to previous, search right
                    if (nums[mid] == nums[mid - 1]) {
                        s = mid + 1;
                    }
                    // If mid is odd and equal to next, search left
                    else {
                        e = mid - 1;
                    }
                } else {
                    // If mid is even and equal to next, search right
                    if (nums[mid] == nums[mid + 1]) {
                        s = mid + 1;
                    }
                    // If mid is even and equal to previous, search left
                    else {
                        e = mid - 1;
                    }
                }
            }
    
            // When s == e, we've found the unique element
            return nums[s];
        }
    };
    