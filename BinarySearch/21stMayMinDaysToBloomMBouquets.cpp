class Solution {
    public:
    
        // Helper function to check if it's possible to make 'm' bouquets
        // with at least 'k' adjacent flowers bloomed on or before 'mid' day.
        bool PossibleBlooming(vector<int>& nums, int mid, int m, int k) {
            int bouquets = 0; // total bouquets formed
            int count = 0;    // count of consecutive bloomed flowers
    
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] <= mid) {
                    count++; // flower is bloomed on or before 'mid' day
                    if (count == k) {
                        bouquets++; // one bouquet formed
                        count = 0;   // reset for next bouquet
                    }
                } else {
                    count = 0; // sequence breaks, reset count
                }
            }
    
            // Check if required number of bouquets can be formed
            return bouquets >= m;
        }
    
        // Main function to find the minimum number of days required
        // to make 'm' bouquets of 'k' adjacent flowers.
        int roseGarden(int n, vector<int> nums, int k, int m) {
            int s = 1;
            int e = *max_element(nums.begin(), nums.end()); // max bloom day
            int ans = -1;
    
            while (s <= e) {
                int mid = s + (e - s) / 2;
    
                // Check if it's possible to bloom enough bouquets by 'mid' day
                if (PossibleBlooming(nums, mid, m, k)) {
                    ans = mid;     // possible answer, try to find earlier day
                    e = mid - 1;
                } else {
                    s = mid + 1;   // need more days
                }
            }
    
            return ans; // minimum days required to make 'm' bouquets
        }
    };
    