class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int k) {
        // Total number of bulbs
        int n = bulbs.size();

        /*
        Create a days[] array such that:
        days[i] = day on which bulb at position (i+1) is turned ON.
        For example:
        bulbs = [1, 3, 2] → days = [1, 3, 2]
        */
        vector<int> days(n);
        for (int i = 0; i < n; i++) {
            days[bulbs[i] - 1] = i + 1;
        }

        // Initialize result to a large value
        int ans = INT_MAX;

        // Sliding window pointers:
        int left = 0;
        int right = k + 1;

        /*
        Start sliding the window from index 0 to n-1:
        - Window size is always k+2 → left and right are ON bulbs
        - Check all bulbs in between them
        */
        for (int i = 0; right < n; i++) {
            bool valid = true;

            // Check if bulbs in between are turned on before left or right
            for (int j = left + 1; j < right; j++) {
                if (days[j] < days[left] || days[j] < days[right]) {
                    // Invalid window → slide to new window
                    valid = false;
                    left = j;
                    right = j + k + 1;
                    break;
                }
            }

            // Valid window → update answer
            if (valid) {
                ans = min(ans, max(days[left], days[right]));
                // Move window forward
                left = right;
                right = left + k + 1;
            }
        }

        // If no valid pair found, return -1
        return (ans == INT_MAX) ? -1 : ans;
    }
};
// Time Complexity: O(n)
// - Building days[] → O(n)
// - Sliding window with two pointers → O(n) in total (each element visited at most twice)

// Space Complexity: O(n)
// - Extra array days[] of size n




class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int k) {
        // Total number of bulbs
        int n = bulbs.size();

        /*
        Create an array 'on' of size n to mark ON/OFF status of bulbs
        on[i] = 1 means bulb at position (i+1) is ON
        Initially all bulbs are OFF (0)
        */
        vector<int> on(n, 0);

        // Store the earliest valid day when the condition is satisfied
        int ans = INT_MAX;

        /*
        Simulate day by day, turning on one bulb each day
        */
        for (int i = 0; i < n; i++) {
            // Turn ON the bulb at position bulbs[i] (convert to 0-based index)
            on[bulbs[i] - 1] = 1;

            int one = 0;   // Counts number of ON bulbs found while scanning
            int count = 0; // Counts number of OFF bulbs between two ON bulbs

            // Scan the entire row to check for two ON bulbs with exactly k OFF in between
            for (int j = 0; j < n; j++) {
                if (on[j] == 1) {
                    /*
                    If we have already found one ON bulb before,
                    and exactly k OFF bulbs were in between → valid pair found
                    */
                    if (one > 0 && count == k) {
                        ans = i + 1;  // i+1 = current day (1-based)
                        break;
                    }
                    // Reset count and increment ON bulb counter
                    count = 0;
                    one++;
                } else {
                    // Bulb is OFF → increase count
                    count++;
                }
            }

            // Exit early if answer is found
            if (ans != INT_MAX) {
                break;
            }
        }

        // Return -1 if no valid day is found
        return (ans == INT_MAX) ? -1 : ans;
    }
};
// Time Complexity: O(n^2)
// - Outer loop runs for n days
// - Inner loop scans all bulbs every day (n times in worst case)

// Space Complexity: O(n)
// - on[] array used to store ON/OFF status
