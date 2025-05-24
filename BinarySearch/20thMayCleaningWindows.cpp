class Solution {
    public:
        /*
        Cleaning Windows Problem:
        - Find minimum speed k to clean all windows within h hours
        - windows[i] = panes in ith window
        - time for each window = ceil(windows[i] / k)
    
        Approach:
        - Binary search on k (cleaning speed)
        - Check if for a given k, total time <= h
        */
    
        int cleaningWindows(vector<int>& windows, int h) {
            // Minimum possible speed = 1 pane/hour
            int s = 1;
    
            // Maximum speed = maximum panes in any window (clean it in 1 hour)
            int e = *max_element(windows.begin(), windows.end());
    
            int ans = -1;
    
            while (s <= e) {
                int mid = s + (e - s) / 2; // current cleaning speed
                int hour = 0;              // total hours needed at speed mid
    
                // Calculate total hours needed to clean all windows at speed mid
                for (int i = 0; i < windows.size(); i++) {
                    hour += (int)ceil((double)windows[i] / mid);
                }
    
                // If total hours needed <= h, mid speed is a valid candidate
                if (hour <= h) {
                    ans = mid;        // record answer
                    e = mid - 1;      // try to find smaller speed
                } else {
                    s = mid + 1;      // need higher speed to meet time constraint
                }
            }
    
            return ans;
        }
    };
    