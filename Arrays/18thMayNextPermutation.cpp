// ✅ Problem: Rearrange the numbers into the lexicographically next greater permutation of numbers.
// If such an arrangement is not possible, it must be rearranged as the lowest possible order (i.e., sorted in ascending order).

// ----------------------------------------------------------------------------------
// 🔁 Approach 1: Manual Implementation of Next Permutation (Without STL)
// ----------------------------------------------------------------------------------

class Solution_Manual {
    public:
        void nextPermutation(vector<int>& nums) {
            int n = nums.size();
            int currIndex = -1;
    
            // Step 1: Find the first index from right where nums[i] > nums[i-1]
            // This indicates the point where the descending order breaks
            for (int i = n - 1; i > 0; i--) {
                if (nums[i] > nums[i - 1]) {
                    currIndex = i - 1;
                    break;
                }
            }
    
            // Step 2: If such index is found, find the next larger element to the right of currIndex and swap
            if (currIndex != -1) {
                int swapIndex = currIndex;
                for (int i = n - 1; i > currIndex; i--) {
                    if (nums[i] > nums[currIndex]) {
                        swapIndex = i;
                        break;
                    }
                }
    
                // Swap the values to make permutation slightly larger
                swap(nums[currIndex], nums[swapIndex]);
            }
    
            // Step 3: Reverse the subarray from currIndex + 1 to end to get the next permutation
            // (if currIndex == -1, we reverse entire array, i.e., highest permutation → lowest)
            reverse(nums.begin() + currIndex + 1, nums.end());
        }
    };
    
    /*
    🔍 Dry Run Example:
    Input: [1, 2, 3]
    Step 1: currIndex = 1 (nums[2] > nums[1])
    Step 2: swapIndex = 2 → swap nums[1] and nums[2] → [1, 3, 2]
    Step 3: reverse from index 2 to end → [1, 3, 2]
    Output: [1, 3, 2]
    */
    
    // ✅ Time Complexity: O(n) for scanning + O(n) for reversing = O(n)
    // ✅ Space Complexity: O(1) — done in-place
    
    // ----------------------------------------------------------------------------------
    // ⚡ Approach 2: Using Built-in STL Function `next_permutation`
    // ----------------------------------------------------------------------------------
    
    class Solution_STL {
    public:
        void nextPermutation(vector<int>& nums) {
            // Uses C++ STL to rearrange to next lexicographical permutation
            next_permutation(nums.begin(), nums.end());
        }
    };
    
    /*
    💡 STL Function Behavior:
    - Modifies the range [first, last) to the next lexicographically greater permutation.
    - If no such permutation exists, it rearranges into the lowest possible order (sorted ascending).
    - Based on Narayana Pandita's algorithm.
    
    ✅ Time Complexity: O(n) worst-case (internally does similar steps: find, swap, reverse)
    ✅ Space Complexity: O(1)
    */
    
    // ----------------------------------------------------------------------------------
    // ✅ Usage:
    // Solution_Manual sol;
    // sol.nextPermutation(nums);
    //
    // OR
    // Solution_STL sol;
    // sol.nextPermutation(nums);
    // ----------------------------------------------------------------------------------
    