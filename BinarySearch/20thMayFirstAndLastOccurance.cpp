// Efficient solution using Binary Search to find first and last positions of a target element


//O(log n)
class Solution {
    public:
    
        // Function to find the first occurrence of the target in the sorted array
        int foundFirst(vector<int> &nums, int target) {
            int n = nums.size();
            int s = 0, e = n - 1;
            int first = -1;  // Initialize first occurrence as -1 (not found)
    
            while (s <= e) {
                int mid = s + (e - s) / 2;
    
                if (nums[mid] == target) {
                    first = mid;    // Potential answer found
                    e = mid - 1;    // But search in left half for earlier occurrence
                }
                else if (nums[mid] > target) {
                    e = mid - 1;
                }
                else {
                    s = mid + 1;
                }
            }
            return first;
        }
    
        // Function to find the last occurrence of the target in the sorted array
        int foundLast(vector<int> &nums, int target) {
            int n = nums.size();
            int s = 0, e = n - 1;
            int last = -1;  // Initialize last occurrence as -1 (not found)
    
            while (s <= e) {
                int mid = s + (e - s) / 2;
    
                if (nums[mid] == target) {
                    last = mid;     // Potential answer found
                    s = mid + 1;    // But search in right half for later occurrence
                }
                else if (nums[mid] > target) {
                    e = mid - 1;
                }
                else {
                    s = mid + 1;
                }
            }
            return last;
        }
    
        // Main function that returns the first and last positions of the target
        vector<int> searchRange(vector<int> &nums, int target) {
            vector<int> ans;
            ans.push_back(foundFirst(nums, target)); // First position
            ans.push_back(foundLast(nums, target));  // Last position
            return ans;
        }
    };
    

    //O(n)

    // Simple linear scan solution to find first and last occurrences of the target

class Solution {
    public:
        vector<int> searchRange(vector<int> &nums, int target) {
            int first = -1, last = -1;
            vector<int> ans;
    
            // Traverse the entire array
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == target) {
                    if (first == -1)
                        first = i;  // First time target found
    
                    last = i;       // Update last every time target is found
                }
            }
    
            ans.push_back(first);  // Push first index (or -1 if not found)
            ans.push_back(last);   // Push last index (or -1 if not found)
            return ans;
        }
    };
    