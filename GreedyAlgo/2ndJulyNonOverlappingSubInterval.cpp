/*
    Problem: Non-overlapping Intervals (Leetcode 435)
    Approach:
    - Sort intervals by start time
    - Iterate and count overlaps
    - Keep track of the minimum end time to reduce future overlaps

    Time Complexity: O(N log N) for sorting + O(N) traversal = O(N log N)
    Space Complexity: O(1) (sorting in-place)
*/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        // Sort intervals by start time
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });

        int count = 0;
        int prevEnd = intervals[0][1];

        for (int i = 1; i < n; i++) {
            int start = intervals[i][0];
            if (start >= prevEnd) {
                // No overlap
                prevEnd = intervals[i][1];
            } else {
                // Overlap found
                count++;
                // Keep the interval with smaller end to minimize overlaps
                prevEnd = min(prevEnd, intervals[i][1]);
            }
        }
        return count;
    }
};
