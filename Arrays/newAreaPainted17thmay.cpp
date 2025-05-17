// Given a list of painting intervals, return the number of new units painted each day, ignoring previously painted sections.
// Each interval is of the form [start, end), where end is exclusive.



// Title: Amount of New Area Painted Each Day
// Description: For each painting interval, count how many units are newly painted (i.e., not painted before).
// Time Complexity: O(N), where N is the sum of lengths of all intervals.
// Space Complexity: O(50001) ~ O(1) since coordinates are bounded.

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> amountPainted(vector<vector<int>>& paint) {
        int maxCoordinates = 50000;
        vector<bool> isPainted(maxCoordinates + 1, false); // Track painted positions
        vector<int> ans;

        for (auto &interval : paint) {
            int start = interval[0];
            int end = interval[1];
            int newPainted = 0;

            // Paint only the unpainted units in the interval
            for (int pos = start; pos < end; pos++) {
                if (!isPainted[pos]) {
                    isPainted[pos] = true;
                    newPainted++;
                }
            }

            ans.push_back(newPainted); // Store the count of newly painted units
        }

        return ans;
    }
};



//optimal approach
TC= O(m+n)
SC=O(n)



#include <vector>
#include <numeric> // for iota
using namespace std;

class Solution {
public:
    vector<int> amountPainted(vector<vector<int>>& paint) {

        // Step 1: Define the max possible coordinate.
        int maxCoordinate = 50000;

        // Step 2: Initialize the nextUnpainted vector where
        // nextUnpainted[i] = i initially, i.e., each position points to itself.
        vector<int> nextUnpainted(maxCoordinate + 1);
        iota(nextUnpainted.begin(), nextUnpainted.end(), 0);

        vector<int> result;

        // Step 3: Process each painter's interval.
        for (auto& interval : paint) {
            int start = interval[0];
            int end = interval[1];
            int newPainted = 0;

            // Step 4: Use path compression to skip already painted positions.
            while (start < end) {

                // If current position is unpainted, paint it.
                if (start == nextUnpainted[start]) {
                    newPainted++;
                    nextUnpainted[start] = start + 1;
                }

                // Store the next position to jump to
                int nextPos = nextUnpainted[start];

                // Compress path: nextUnpainted[start] now directly points to end
                nextUnpainted[start] = end;

                // Move to the next position
                start = nextPos;
            }

            // Add the count of newly painted positions for this painter
            result.push_back(newPainted);
        }

        return result;
    }
};
