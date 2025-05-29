class Solution {
public:
    int minSwaps(vector<int>& data) {
        // 🧠 Step 1: Calculate total number of 1s in the array
        // Because we want all 1s to be together, we'll try to form a window of size k (total 1s)
        int k = accumulate(data.begin(), data.end(), 0); // total number of 1s

        // 🧠 Step 2: Use sliding window of size k to find the window which already contains
        // maximum number of 1s (we won't need to swap those 1s)
        int maxOnes = 0;     // Maximum number of 1s in any window of size k
        int count = 0;       // Current number of 1s in the window
        int left = 0;        // Left pointer for the window

        for (int right = 0; right < data.size(); right++) {
            // 👉 Expand the window by including data[right]
            if (data[right] == 1) {
                count++;
            }

            // 👉 Shrink the window if its size exceeds k
            while (right - left + 1 > k) {
                if (data[left] == 1) {
                    count--; // Remove the contribution of data[left] as it is sliding out
                }
                left++; // Slide the window forward
            }

            // 👉 Update max number of 1s found in a window of size k
            if (right - left + 1 == k) {
                maxOnes = max(maxOnes, count);
            }
        }

        // ✅ Step 3: Minimum swaps required = total 1s - maximum 1s already together
        // Because only the remaining 1s need to be swapped inside the window
        return k - maxOnes;
    }
};

📊 Time Complexity:
O(n) where n is the size of the input array.

One pass to compute total number of 1s using accumulate().

One pass using sliding window logic.

🧠 Space Complexity:
O(1) constant space.

We only use a few integer variables for tracking window state.