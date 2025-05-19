class Solution {
    public:
        /**
         * Function to find the Kth element in the union of two sorted arrays.
         * Time Complexity: O(log(min(n1, n2)))
         * Space Complexity: O(1)
         *
         * @param a First sorted array
         * @param b Second sorted array
         * @param k The position (1-based index) of the element to find in the merged sorted array
         * @return The Kth element in the combined sorted array
         */
        int kthElement(vector<int> &a, vector<int>& b, int k) {
            int n1 = a.size();
            int n2 = b.size();
    
            // Always binary search on the smaller array for efficiency
            if (n1 > n2) {
                return kthElement(b, a, k);
            }
    
            // Define search boundaries
            int lo = max(0, k - n2);        // At least k-n2 elements must come from a
            int hi = min(k, n1);            // At most k elements can come from a
    
            while (lo <= hi) {
                int cut1 = lo + (hi - lo) / 2; // Elements taken from a
                int cut2 = k - cut1;           // Remaining elements from b
    
                // Left part values
                int l1 = (cut1 == 0) ? INT_MIN : a[cut1 - 1];
                int l2 = (cut2 == 0) ? INT_MIN : b[cut2 - 1];
    
                // Right part values
                int r1 = (cut1 == n1) ? INT_MAX : a[cut1];
                int r2 = (cut2 == n2) ? INT_MAX : b[cut2];
    
                // Check for correct partition
                if (l1 <= r2 && l2 <= r1) {
                    return max(l1, l2);
                }
                // Move left in a
                else if (l1 > r2) {
                    hi = cut1 - 1;
                }
                // Move right in a
                else {
                    lo = cut1 + 1;
                }
            }
    
            return -1; // Invalid input case (theoretically unreachable with valid input)
        }
    };
    