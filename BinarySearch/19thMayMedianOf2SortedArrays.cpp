class Solution {
    public:
        // Function to find the median of two sorted arrays using binary search
        double median(vector<int> &arr1, vector<int> &arr2) {
            int n1 = arr1.size();
            int n2 = arr2.size();
    
            // Always apply binary search on the smaller array for optimized performance
            if (n1 > n2) {
                return median(arr2, arr1); // Swap arrays if arr1 is larger
            }
    
            int lo = 0, hi = n1;
    
            while (lo <= hi) {
                // Partitioning arr1 and arr2
                int cut1 = lo + (hi - lo) / 2; // Mid index of arr1
                int cut2 = (n1 + n2 + 1) / 2 - cut1; // Corresponding index in arr2 to maintain half split
    
                // Elements just before and after the partition in both arrays
                int l1 = (cut1 == 0) ? INT_MIN : arr1[cut1 - 1]; // Left of cut1
                int l2 = (cut2 == 0) ? INT_MIN : arr2[cut2 - 1]; // Left of cut2
    
                int r1 = (cut1 == n1) ? INT_MAX : arr1[cut1]; // Right of cut1
                int r2 = (cut2 == n2) ? INT_MAX : arr2[cut2]; // Right of cut2
    
                // Check if valid partition
                if (l1 <= r2 && l2 <= r1) {
                    // If total number of elements is even, return average of two middle values
                    if ((n1 + n2) % 2 == 0) {
                        return (max(l1, l2) + min(r1, r2)) / 2.0;
                    } else {
                        // If odd, return the maximum of the left elements
                        return max(l1, l2);
                    }
                }
                // If l1 is greater than r2, move left in arr1
                else if (l1 > r2) {
                    hi = cut1 - 1;
                }
                // If l2 is greater than r1, move right in arr1
                else {
                    lo = cut1 + 1;
                }
            }
    
            // This line will never be reached for valid sorted inputs
            return 0.0;
        }
    };
    
    /*
    🧠 Intuition:
    We perform binary search on the smaller array to partition both arrays in such a way that all elements
    on the left side are less than or equal to all elements on the right side. This enables us to find the
    median in O(log(min(n, m))) time.
    
    📈 Time Complexity:
    - O(log(min(n, m))) where n and m are the sizes of the two arrays.
    - Because we perform binary search on the smaller array.
    
    🧮 Space Complexity:
    - O(1) extra space.
    - Only a constant amount of variables are used regardless of input size.
    */
    