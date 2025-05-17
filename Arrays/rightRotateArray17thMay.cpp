// Title: Right Rotate an Array by k Positions
// Description: Rotates the given array to the right by k places
// Time Complexity: O(n)
// Space Complexity: O(k) - for temporary storage

#include <vector>
using namespace std;

class Solution {
public:
    void rotateArray(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // In case k > n

        // Step 1: Store the last k elements in a temporary array
        vector<int> temp(k);
        for (int i = 0; i < k; i++) {
            temp[i] = nums[n - k + i];
        }

        // Step 2: Shift the remaining elements (from end to front) to the right
        for (int i = n - k - 1; i >= 0; i--) {
            nums[i + k] = nums[i];
        }

        // Step 3: Copy the stored k elements to the beginning of the array
        for (int i = 0; i < k; i++) {
            nums[i] = temp[i];
        }
    }
};
