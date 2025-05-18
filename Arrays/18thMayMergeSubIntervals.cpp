class Solution {
    public:
        vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
            // Resultant vector to store merged intervals
            vector<vector<int>> intervals;
    
            // Step 1: Sort the given intervals based on start time
            // Sorting ensures we can linearly compare overlapping intervals
            sort(arr.begin(), arr.end(), [](vector<int>& a, vector<int>& b) {
                return a[0] < b[0];
            });
    
            int n = arr.size();
            int i = 0; // Iterator to traverse all intervals
    
            // Step 2: Traverse through the sorted intervals
            while (i < n) {
                // Case 1: If 'intervals' is empty OR
                // current interval does not overlap with the last one in result
                if (intervals.empty() || intervals.back()[1] < arr[i][0]) {
                    intervals.push_back(arr[i]); // Simply add the current interval
                } else {
                    // Case 2: Overlapping intervals found
                    // Modify the end time of the last interval in result
                    // to the maximum of current and previous
                    intervals.back()[1] = max(intervals.back()[1], arr[i][1]);
                }
    
                i++; // Move to the next interval
            }
    
            return intervals;
        }
    };
TC= Total: O(N log N)    