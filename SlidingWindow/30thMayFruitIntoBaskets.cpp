class Solution {
public:
    int totalFruits(vector<int>& fruits) {
        // This problem is a variant of "Longest Substring with at Most 2 Distinct Characters"
        // We use the sliding window approach to find the longest subarray with at most 2 types of fruits.

        int left = 0; // Left boundary of the window
        int maxLen = 0; // To store the maximum length of valid subarray
        int n = fruits.size(); // Total number of fruit trees
        unordered_map<int, int> mp; // HashMap to store count of each fruit type in current window

        // Traverse through the array using right pointer
        for (int right = 0; right < n; right++) {
            mp[fruits[right]]++; // Add the current fruit to the basket (i.e., increment count in map)

            // If there are more than 2 types of fruits, shrink the window from the left
            while (mp.size() > 2) {
                mp[fruits[left]]--; // Remove the leftmost fruit type
                if (mp[fruits[left]] == 0) {
                    mp.erase(fruits[left]); // If its count becomes zero, remove it from the map
                }
                left++; // Move the left boundary to the right
            }

            // Calculate the maximum length of valid window so far
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen; // Return the maximum fruits that can be collected
    }
};
