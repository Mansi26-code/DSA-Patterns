// Given an array nums, rotate the elements to the left by one position. This means the first element moves to the end, and the rest shift one step to the left.


#include <vector>
using namespace std;

class Solution {
public:
    void rotateArrayByOne(vector<int>& nums) {
        // Step 1: Store the first element in a temporary variable
        int temp = nums[0];
        int n = nums.size();

        // Step 2: Shift all elements to the left by one
        for (int i = 1; i < n; i++) {
            nums[i - 1] = nums[i];
        }

        // Step 3: Place the first element at the end
        nums[n - 1] = temp;
    }
};

//tc=O(n)
// sc= O(1)
