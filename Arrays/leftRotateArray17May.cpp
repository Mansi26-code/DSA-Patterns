// Title: Left Rotate an Array by k Positions
// Description: Rotates the given array to the left by k places
// Time Complexity: O(n)
// Space Complexity: O(k) - for temporary array

#include <vector>
using namespace std;

class Solution {
public:
    void rotateArray(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // In case k is greater than the array size

        // Step 1: Store the first k elements in a temporary array
        vector<int> temp(k);
        for (int i = 0; i < k; i++) {
            temp[i] = nums[i];
        }

        // Step 2: Shift the remaining elements of the array to the left
        for (int i = k; i < n; i++) {
            nums[i - k] = nums[i];
        }

        // Step 3: Copy the stored k elements to the end of the array
        for (int i = 0; i < k; i++) {
            nums[n - k + i] = temp[i];
        }
    }
};
