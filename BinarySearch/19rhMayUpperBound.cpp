/*
🧾 Problem: Implement Upper Bound using Binary Search

The **upper bound** of a number `x` in a sorted array `nums` is the **index of the first element that is strictly greater than `x`**.
If no such element exists, behavior is undefined (you may return an index equal to nums.size()).

This function mimics `std::upper_bound` in C++ STL.

Approach:
- Use binary search.
- If `nums[mid] > x`, we store the index `mid` in `ans` and continue searching in the left half.
- Otherwise, we move to the right half.
*/

class Solution {
    public:
        int upperBound(vector<int> &nums, int x) {
            int s = 0;
            int e = nums.size() - 1;
            int ans = nums.size(); // Default to size of array (i.e., no upper bound exists)
    
            // Binary search for first number > x
            while (s <= e) {
                int mid = s + (e - s) / 2;
    
                if (nums[mid] > x) {
                    ans = mid;      // Candidate for upper bound
                    e = mid - 1;    // Try to find a smaller valid index
                } else {
                    s = mid + 1;    // Move right to find > x
                }
            }
    
            return ans;
        }
    };
    