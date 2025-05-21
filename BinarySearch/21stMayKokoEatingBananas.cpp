#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the minimum eating speed (bananas per hour) such that 
    // Koko can finish all the bananas in 'h' hours.
    int minimumRateToEatBananas(vector<int> nums, int h) {
        // Lowest possible eating speed is 1 banana/hour
        long long s = 1;

        // Highest possible eating speed is the max pile size
        long long e = *max_element(nums.begin(), nums.end());

        long long ans = 0;

        while (s <= e) {
            // Try middle speed (binary search step)
            long long mid = s + (e - s) / 2;

            // Calculate how many hours Koko needs at this speed
            long long consumedHour = 0;
            for (int i = 0; i < nums.size(); i++) {
                // Use ceil to round up division
                consumedHour += ceil((double)nums[i] / mid);
            }

            // If Koko can finish all bananas within 'h' hours
            if (consumedHour <= h) {
                ans = mid;         // Store current speed as possible answer
                e = mid - 1;       // Try to find a lower valid speed
            } else {
                s = mid + 1;       // Speed too slow, try faster
            }
        }

        return ans;
    }
};
