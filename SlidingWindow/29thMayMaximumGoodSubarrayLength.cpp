class Solution {
public:
    // Function to return the maximum length of a good subarray
    int maxGoodSubarray(vector<int> &nums, vector<int> &badNumbers) {
        // Step 1: Create a set from badNumbers for O(1) lookup
        unordered_set<int> badSet(badNumbers.begin(), badNumbers.end());

        // Step 2: Map to keep track of bad numbers in the current window
        unordered_map<int, int> badCount;

        int maxLen = 0;     // Stores the maximum length of a good subarray
        int left = 0;       // Left pointer of the sliding window

        // Step 3: Expand the window with the right pointer
        for (int right = 0; right < nums.size(); right++) {
            // If current element is a bad number, include it in the count
            if (badSet.count(nums[right])) {
                badCount[nums[right]]++;
            }

            // Step 4: Shrink the window from the left 
            // until not all bad numbers are present in it
            while (badCount.size() == badSet.size()) {
                if (badSet.count(nums[left])) {
                    badCount[nums[left]]--;
                    // Remove the number from map if its count drops to 0
                    if (badCount[nums[left]] == 0) {
                        badCount.erase(nums[left]);
                    }
                }
                left++;  // Shrink the window
            }

            // Step 5: Update the maximum good subarray length
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
