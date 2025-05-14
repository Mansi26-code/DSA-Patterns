// Given an array nums and an integer k, count the total number of index pairs (i, j) where 0 <= i < j < n and nums[i] + k < nums[j].
// Each such valid pair represents a "jump".


class Solution {
    public:
        int NumberOfJumps(vector<int>& nums, int k) {
            int ans = 0;
            int n = nums.size();
    
            // Iterate through each index i from 0 to n-2
            for (int i = 0; i < n - 1; i++) {
                int count = 0;
    
                // For each index i, check all j > i
                for (int j = i + 1; j < n; j++) {
                    // If nums[i] + k is strictly less than nums[j], it's a jump
                    if (nums[i] + k < nums[j]) {
                        count++; // Count this jump
                    }
                }
    
                ans += count; // Add jumps from index i
            }
    
            return ans; // Return total number of jumps
        }
    };
    
    ⏱ Time Complexity:
Outer loop runs n - 1 times, inner loop up to n

Total: O(n²)

📦 Space Complexity:
Only integer variables used → O(1)


//Better approach

class Solution {
    public:
        int NumberOfJumps(vector<int>& nums, int k) {
            int n = nums.size();
            multiset<int> seen;         // Keeps track of elements to the right of current index
            int totalCount = 0;
    
            // Traverse the array from right to left
            for (int i = n - 1; i >= 0; --i) {
                // Find the first number in the multiset that is greater than nums[i] + k
                auto it = seen.upper_bound(nums[i] + k);
    
                // Count how many such elements exist (all those from 'it' to end)
                totalCount += distance(it, seen.end());
    
                // Insert current number into the multiset for future comparisons
                seen.insert(nums[i]);
            }
    
            return totalCount;
        }
    };
    TC=O(nlog n)
    SC= O(n)