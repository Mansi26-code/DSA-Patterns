class Solution {
    public:
        /*
        Function to check if it is possible to place all k cows
        in stalls such that minimum distance between any two cows >= mid
        */
        bool isPossible(vector<int>& nums, int k, int mid) {
            int countCows = 1;       // place first cow at first stall
            int lastPos = nums[0];   // position of last placed cow
    
            // Try to place remaining cows
            for (int i = 1; i < nums.size(); i++) {
                // If current stall is at least 'mid' away from last cow
                if (nums[i] - lastPos >= mid) {
                    countCows++;          // place a cow here
                    lastPos = nums[i];    // update last placed cow position
                    if (countCows == k)   // all cows placed successfully
                        return true;
                }
            }
    
            // Not possible to place all cows with 'mid' minimum distance
            return false;
        }
    
        /*
        Aggressive Cows Problem:
    
        - Find the largest minimum distance between cows in the stalls.
        - Use binary search on possible distances.
        */
    
        int aggressiveCows(vector<int>& nums, int k) {
            sort(nums.begin(), nums.end());  // sort stall positions
    
            int n = nums.size();
            int s = 1;                       // minimum possible distance
            int e = nums[n - 1] - nums[0];  // maximum possible distance (between first and last stall)
            int ans = -1;
    
            // Binary search on distance
            while (s <= e) {
                int mid = s + (e - s) / 2;  // middle distance to check
    
                if (isPossible(nums, k, mid)) {
                    ans = mid;     // mid is a valid minimum distance
                    s = mid + 1;   // try for larger minimum distance
                } else {
                    e = mid - 1;   // try smaller minimum distance
                }
            }
    
            return ans;  // largest minimum distance found
        }
    };
    