class Solution {
    public:
        int getPivot(vector<int>& nums) {
            int s = 0, e = nums.size() - 1;
    
            while (s < e) {
                int mid = s + (e - s) / 2;
    
                if (nums[mid] < nums[e]) {
                    e = mid;
                } 
                else if (nums[mid] > nums[e]) {
                    s = mid + 1;
                } 
                else {
                    // nums[mid] == nums[e], can't decide, shrink window
                    e--;
                }
            }
    
            return s; // index of minimum element
        }
    
        bool binsearch(vector<int>& nums, int s, int e, int target) {
            while (s <= e) {
                int mid = s + (e - s) / 2;
    
                if (nums[mid] == target)
                    return true;
                    if(nums[s]==nums[mid] && nums[mid]==nums[e])
                    {
                        s++;
                        e--;
                    }
                else if (nums[mid] < target)
                    s = mid + 1;
                else
                    e = mid - 1;
            }
            return false;
        }
    
        bool search(vector<int>& nums, int target) {
            if (nums.empty()) return false;
    
            int pivot = getPivot(nums);
    
            // Check if pivot is 0 (array not rotated at all)
            if (pivot == 0) {
                return binsearch(nums, 0, nums.size() - 1, target);
            }
    
            // If target is in the sorted right half
            if (target >= nums[pivot] && target <= nums[nums.size() - 1]) {
                return binsearch(nums, pivot, nums.size() - 1, target);
            }
    
            // Otherwise in the left half
            return binsearch(nums, 0, pivot - 1, target);
        }
    };
    