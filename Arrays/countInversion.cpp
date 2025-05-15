// Problem: Count Inversions in an Array
// Given an array 'nums', return the number of inversion pairs (i, j)
// such that i < j and nums[i] > nums[j].

// Approach: Brute Force - Compare every pair (i, j) where i < j.

// Time Complexity: O(n^2)
// Space Complexity: O(1)

class Solution {
    public:
        long long int numberOfInversions(vector<int> nums) {
            int n = nums.size();
            int count = 0;
    
            // Loop through all possible pairs
            for(int i = 0; i < n - 1; i++) {
                for(int j = i + 1; j < n; j++) {
                    // If nums[i] > nums[j], it's an inversion
                    if(nums[i] > nums[j]) {
                        count++;
                    }
                }
            }
    
            return count;
        }
    };

    


    // Problem: Count Inversions in an Array
// Given an array 'nums', return the number of inversion pairs (i, j)
// such that i < j and nums[i] > nums[j].

// Approach: Merge Sort - Count inversions while merging sorted subarrays.

// Time Complexity: O(n log n)
// Space Complexity: O(n)

class Solution {
    public:
        // Merge two sorted halves and count inversions
        long long int merge(vector<int>& nums, int low, int mid, int high) {
            vector<int> temp;
            int left = low;
            int right = mid + 1;
            long long int cnt = 0;
    
            // Merge the two halves while counting inversions
            while(left <= mid && right <= high) {
                if(nums[left] <= nums[right]) {
                    temp.push_back(nums[left++]);
                } else {
                    temp.push_back(nums[right++]);
                    cnt += (mid - left + 1); // Count inversions
                }
            }
    
            // Add remaining elements from the left half
            while(left <= mid) {
                temp.push_back(nums[left++]);
            }
    
            // Add remaining elements from the right half
            while(right <= high) {
                temp.push_back(nums[right++]);
            }
    
            // Copy merged elements back into the original array
            for(int i = low; i <= high; i++) {
                nums[i] = temp[i - low];
            }
    
            return cnt;
        }
    
        // Recursive merge sort function
        long long int mergeSort(vector<int>& nums, int low, int high) {
            long long int cnt = 0;
    
            if(low < high) {
                int mid = low + (high - low) / 2;
                cnt += mergeSort(nums, low, mid);       // Sort left half
                cnt += mergeSort(nums, mid + 1, high);  // Sort right half
                cnt += merge(nums, low, mid, high);     // Merge and count
            }
    
            return cnt;
        }
    
        // Main function to call merge sort
        long long int numberOfInversions(vector<int> nums) {
            int n = nums.size();
            return mergeSort(nums, 0, n - 1);
        }
    };
    